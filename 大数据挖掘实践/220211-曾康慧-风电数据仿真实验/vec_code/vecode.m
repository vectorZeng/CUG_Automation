%数据导入
%demo = table2array(datapltr(1:20000,2:4));
demo = readtable("data\wind.xlsx");
%% 数据预处理部分
%1. 基于第一列删除重复行,只保留第一次出现的行
[~, uniqueIndices] = unique(demo{:, 1}, 'first');
uniqueDataTable = demo(sort(uniqueIndices), :);

%2. 检查是否有缺失值,若有则用前一日同位置的值来补
for col = 1:width(uniqueDataTable)
% 检查列的类型
    if iscell(uniqueDataTable{:, col})
% 处理单元格数组类型的列
        for row = 2:height(uniqueDataTable)
            if isempty(uniqueDataTable{row, col})
                uniqueDataTable{row, col} = uniqueDataTable{row - 1, col};
            end
        end
    elseif isnumeric(uniqueDataTable{:, col})
% 处理数值类型的列
        for row = 2:height(uniqueDataTable)
            if isnan(uniqueDataTable{row, col})
                uniqueDataTable{row, col} = uniqueDataTable{row - 1, col};
            end
        end
    end
end

%{
id = [0 NaN];
TF = ismissing(demo,id);   %查询demo中缺失值所在的位置
demo_1 = demo; %删除缺失值后的矩阵
for i = size(TF,1):-1:4
    for j = 1:3
        if TF(i-3,j)+TF(i-2,j)+TF(i-1,j) > 2 %连续三行的空值直接删除
            demo_1(i,:) = [];
        end
    end
end
%TF2 = ismissing(demo_1,id)
%}

%% 3-划分数据集(按顺序8:2)
numRows = height(uniqueDataTable);
splitPoint = round(0.8 * numRows);

% 确保划分点是96的倍数
splitPoint = floor(splitPoint / 96) * 96;

% 划分数据集
trainData = uniqueDataTable(1:splitPoint, :);
testData = uniqueDataTable(splitPoint+1:end, :);

% 显示训练集和测试集的大小
disp('训练集大小:');
disp(size(trainData));

disp('测试集大小:');
disp(size(testData)); 


%% 4-风电场数据特征分析(训练集)

% 提取相关列
windSpeed = trainData{:, 2}; % 风速
windDirection = trainData{:, 3}; % 风向
windPower = trainData{:, 7};% 风电功率

%1. 风速功率散点图
figure;
scatter(windSpeed, windPower);
xlabel('风速(m/s)');
ylabel('风电功率(kW)');
title('风速与风电功率散点图');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);


%2. 风速频率直方图
figure;
histogram(windSpeed);
xlabel('风速(m/s)');
ylabel('频率');
title('风速频率直方图');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);


%3. 风向功率散点图
figure;
scatter(windDirection,windSpeed);
xlabel('风向(°)');
ylabel('风电功率(kW)');
title('风速与风向功率散点图');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);


% 4. 风向玫瑰图
figure;
% 将风向数据分成36个等间隔的方向区段
numDirections = 36;
windDirectionBins = linspace(0, 360, numDirections + 1);
windDirectionCounts = histcounts(windDirection, windDirectionBins);
windDirectionAngles = windDirectionBins(1:end-1) + diff(windDirectionBins)/2;
polarplot(deg2rad([windDirectionAngles windDirectionAngles(1) ]), ...
    [windDirectionCounts windDirectionCounts(1)],'r-o',LineWidth=1);
title('风向玫瑰图');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);

%5. 风向频率直方图
figure;
histogram(windDirection, 'BinEdges', windDirectionBins);
xlabel('风向(°)');
ylabel('频率');
title('风向频率直方图');
% 设置图表中的文字的字体和大小
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);

% 6. 统计特征

% 初始化存储统计特征的表格
statsTable = array2table(zeros(6, 5), ...
    'VariableNames', {'Mean','Median','Mode','Range', 'StdDev'}, ...
    'RowNames', trainData.Properties.VariableNames(2:end));

% 计算统计特征
for col = 2:7
data = trainData{:, col};

meanValue = mean(data);
rangeValue = range(data);
stdDevValue = std(data);
medValue = median(data);
modeValue = mode(data);


statsTable{col-1, 'Mean'} = meanValue;
statsTable{col-1, 'Median'} = medValue;
statsTable{col-1, 'Mode'} = modeValue;
statsTable{col-1, 'Range'} = rangeValue;
statsTable{col-1, 'StdDev'} = stdDevValue;

end

% 显示统计特征表格
disp('统计特征:');
disp(statsTable);


%% 5-训练集归一化(可以用matlab自带的函数)
normalizedTrainData = trainData;
% 对数值类型的列进行归一化
for col = 2:width(trainData)
    if isnumeric(trainData{:, col}) || islogical(trainData{:, col})
        minValue = min(trainData{:, col});
        maxValue = max(trainData{:, col});
        normalizedTrainData{:, col} = (trainData{:, col} - minValue) / (maxValue - minValue);
    end
end

%% 6-DBSCAN聚类去异常值(使用风速和功率)
% 提取风速和风电功率用于聚类
feature = normalizedTrainData{:, 2};
windPower = normalizedTrainData{:, end};
% 准备聚类数据
dataToCluster = [feature, windPower];

% 设置DBSCAN参数
epsilon=0.05; % 邻域半径
minPts =120; % 最小点数

% 进行DBSCAN聚类
clusterIndices = dbscan(dataToCluster, epsilon, minPts);

% 标记异常值
outliers = clusterIndices == -1;

% 可视化DBSCAN聚类结果
figure;
hold on;
scatter(dataToCluster(~outliers, 1), dataToCluster(~outliers, end), 'b'); % 正常点
scatter(dataToCluster(outliers, 1), dataToCluster(outliers, end), 'r'); % 异常点
xlabel('风速(m/s)');
ylabel('风电功率(kW)');
title('DBSCAN聚类结果');
legend('正常点','异常点');
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);
% 只绘制清洗后保留的样本
figure;
scatter(dataToCluster(~outliers, 1), dataToCluster(~outliers, end), 'b'); % 正常点
xlabel('风速(m/s)');
ylabel('风电功率(kW)');
title('清洗后保留的样本');
legend('保留的样本');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);
% 导出保留的数据
cleanedDataTable = normalizedTrainData(~outliers, :);

%% 7-相关性分析(减少特征数量,通过相关性分析和特征筛选,可以去除这些无关或冗余的特征,使模型更专注于有效信息。)
% 分析第二至第六列与第七列的相关性
variablesToAnalyze = normalizedTrainData{:, 2:7};
correlationMatrix = corr(variablesToAnalyze, 'Rows', 'complete');

% 显示相关性矩阵
disp('相关性矩阵:');
corr = array2table(correlationMatrix, 'VariableNames', ...
normalizedTrainData.Properties.VariableNames(2:7), ...
'RowNames', normalizedTrainData.Properties.VariableNames(2:7));

writetable(corr,'corr.xlsx');

disp(corr);

% 可视化相关性矩阵
figure;
h = heatmap(normalizedTrainData.Properties.VariableNames(2:7),...
normalizedTrainData. Properties. VariableNames(2:7), correlationMatrix);


title('相关性矩阵热图');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);

% 筛选与第七列相关性绝对值大于等于0.3的特征(不包括第七列本身)
threshold = 0.3;
absCorrelationWithTarget = abs(correlationMatrix(1:end, end));
selectedIndices = find(absCorrelationWithTarget >= threshold);

% 保留相关性绝对值大于等于0.3的特征
filteredVariableNames = normalizedTrainData. Properties. VariableNames(2:7);
filteredVariableNames = filteredVariableNames(selectedIndices);

% 打印筛选后的相关性矩阵
disp('筛选后的相关性矩阵:');

filteredCorrelationMatrix = correlationMatrix(selectedIndices, selectedIndices);
corr_filt=array2table(filteredCorrelationMatrix, ...
    'VariableNames', filteredVariableNames, ...
    'RowNames', filteredVariableNames);
writetable(corr_filt,'corr_filt.xlsx');
disp(corr_filt)

% 生成列索引,包括风速和风电功率
selectedColumnIndices = selectedIndices + 1;

% 将筛选后的数据(风速和风电功率)用于DBSCAN聚类
filteredData = normalizedTrainData(:, selectedColumnIndices);


%% 8-K-means聚类(聚类后再建立模型可以让每个模型专注于特定的数据模式,提高整体的预测性能。
% 聚类数确定、聚类散点图、数据分布图
% 提取特征列
features = filteredData{:, 1:3};

% 肘部法确定聚类数
sum_of_squared_distances = [];
max_clusters = 10;

for k = 1:10
    [~, w, sumd] = kmeans(features, k, 'Replicates', 10);
    sum_of_squared_distances = [sum_of_squared_distances; sum(sumd) ];
end
%6绘制肘部法图
figure;
plot(1:max_clusters, sum_of_squared_distances, '-o');
xlabel('聚类数K');
ylabel('总的平方距离和');
title('肘部法确定聚类数');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);
%轮廓系数法确定聚类数
silhouette_avg = [];
for k = 2:10
    [idx, ~] = kmeans(features, k, 'Replicates', 10);
    S = silhouette(features, idx);
    silhouette_avg = [silhouette_avg; mean(S)];
end
% 绘制轮廓系数图

figure;
plot(2:max_clusters, silhouette_avg, '-o');
xlabel('聚类数K');
ylabel('平均轮廓系数');
title('轮廓系数法确定聚类数');
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);
% 选择最佳聚类数
optimal_clusters= 3; % 根据图形选择的最佳聚类数

% 执行K-means聚类
[idx, C] = kmeans(features, optimal_clusters, 'Replicates', 10);

% 对聚类结果进行可视化
% 提取风速和功率列
wind_speed = filteredData{:, 1};
wind_direction = filteredData{:, 2};
temperature = filteredData{:, 3};
power = filteredData{:, 4};

% 绘制聚类结果
figure;
gscatter(wind_speed, power, idx);
hold on;
xlabel('风速');
ylabel('功率');
title('K-means聚类结果');
legend('Cluster 1', 'Cluster 2', 'Cluster 3');
grid on;
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);

figure;
gscatter(wind_direction, power, idx);
hold on;
xlabel('风向');
ylabel('功率');
title('K-means聚类结果');
legend('Cluster 1', 'Cluster 2', 'Cluster 3');
grid on;
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);

figure;
gscatter(temperature, power, idx);
hold on;
xlabel('温度');
ylabel('功率');
title('K-means聚类结果');
legend('Cluster 1', 'Cluster 2', 'Cluster 3');
grid on;
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);

% 初始化颜色数组,为每个聚类指定一种颜色
figure;
clusterColors = ['r', 'g', 'b', 'c', 'm', 'y', 'k'];

% 绘制风速频率分布图,为每个聚类使用不同的子图
for i = 1:optimal_clusters
% 选择当前聚类的样本
    cluster_wind_speed = wind_speed(idx == i);

% 创建新的子图
    subplot(optimal_clusters, 1, i);

% 绘制直方图
    histogram(cluster_wind_speed, 'FaceColor', clusterColors(i));

% 标题和轴标签
    title(sprintf('Cluster %d:风速频率分布',i));
    xlabel('风速(m/s)');
    ylabel('频率');

% 确保横轴范围对所有聚类相同以便比较
    xlim([min(wind_speed) max(wind_speed) ]);
     grid on
     set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);
end

% 调整子图间的间距以防止标签重叠
sgtitle('各聚类风速频率分布', 'FontName', 'Microsoft YaHei', 'FontSize', 20);% 使用supertitle对所有子图设置一个共同的标题
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 15);
%% 9-BP神经网络建模(分类建模,参数不同)
% 提取特征列和目标变量
wind_speed = filteredData{:, 1};
wind_direction = filteredData{:, 2};
temperature = filteredData{:, 3};
power = filteredData{:, 4};

% 将特征矩阵合并
features = [wind_speed, wind_direction, temperature];

% 初始化存储模型的单元数组
models = cell(optimal_clusters, 1);

% 训练每个聚类的BP神经网络
for k = 1:optimal_clusters
%提取属于当前聚类的数据
    clusterIndices = (idx == k);
    clusterFeatures = features(clusterIndices, :);
    clusterPower = power(clusterIndices);
    %创建BP神经网络
    net = feedforwardnet(10);
    net.trainParam.showWindow=false; % 关闭训练窗口
    % 训练BP神经网络
    net = train(net, clusterFeatures', clusterPower');

% 存储模型
    models{k} = net;

end

%% 10-测试数据归一化

% 从测试数据中筛选出与训练数据相同的特征
testDataFiltered = testData(:, selectedColumnIndices);

% 对测试数据进行归一化(使用训练数据的最小值和最大值)
normalizedTestData = testDataFiltered;
minValues = zeros(1, width(testDataFiltered));
maxValues = zeros(1, width(testDataFiltered));

for col = 1:width(testDataFiltered)
    if isnumeric(testDataFiltered{:, col}) || islogical(testDataFiltered{:, col})
        trainCol= trainData{:,col+1};% 对应训练数据的列进行归一化
        minValue = min(trainCol);
        maxValue = max(trainCol);
        minValues(col) = minValue;
        maxValues(col) = maxValue;
        normalizedTestData{:, col} = (testDataFiltered{:, col} - minValue) / (maxValue - minValue);

    end

end

% 提取特征列和目标变量
test_wind_speed = normalizedTestData{:, 1};
test_wind_direction = normalizedTestData{:, 2};
test_temperature = normalizedTestData{:, 3};
test_power=testData{:, end}; % 实际风电功率

% 将特征矩阵合井
test_features = [test_wind_speed, test_wind_direction, test_temperature];

%% 11-测试样本类别判断、預测和评估

% 初始化存储预测值的向量
test_predictedPower = zeros(size(test_power));

% 使用训练好的k-means模型的中心来判断测试数据的类别
dists = pdist2(test_features, C); % 计算测试数据点到各聚类中心的距离
[~, test_idx]=min(dists,[], 2); % 找出最近的聚类中心

% 使用相应类别的BP神经网络模型进行预测
for k = 1:optimal_clusters
% 提取属于当前聚类的数据
    clusterIndices = (test_idx == k);
    clusterFeatures = test_features(clusterIndices, :);

% 使用模型进行预测

    if ~isempty(clusterFeatures)
        test_predictedPower(clusterIndices) = models{k} (clusterFeatures')';

    end
end

minValuePower = min(trainData{:, end});% 最后一列为风电功率
maxValuePower = max(trainData{:, end});

% 归一化实际风电功率
normalized_test_power = (test_power - minValuePower) / (maxValuePower - minValuePower);

%计算归一化预测误差
normalized_test_predictionError = normalized_test_power - test_predictedPower;

% 计算归一化数据的平均绝对误差(MAE)
normalized_test_mae = mean(abs(normalized_test_predictionError));

% 计算归一化数据的均方根误差(RMSE)
normalized_test_rmse = sqrt(mean(normalized_test_predictionError .^ 2));

% 计算归一化数据的决定系数(R2)
normalized_test_sst = sum((normalized_test_power - mean(normalized_test_power)) .^ 2);
normalized_test_ssres = sum(normalized_test_predictionError .^ 2);
normalized_test_r2 = 1 - normalized_test_ssres / normalized_test_sst;

% 打印归一化数据的模型评估结果
disp('归一化测试集平均绝对误差(MAE):');
disp(normalized_test_mae);
disp('归一化测试集均方根误差(RMSE):');
disp(normalized_test_rmse);
disp('归一化测试集决定系数(R2):');
disp(normalized_test_r2);

criteria(1,:) = {{'BP'},normalized_test_mae,normalized_test_rmse,normalized_test_r2};


% 对预测值进行反归一化
test_predictedPower = test_predictedPower * (maxValuePower - minValuePower) + minValuePower;

%计算预测误差
test_predictionError = test_power - test_predictedPower;

% 计算平均绝对误差(MAE)
test_mae = mean(abs(test_predictionError));

% 计算均方限误差(RMSE)
test_rmse = sqrt(mean(test_predictionError .^ 2));

% 计算决定系数(R)
test_r2 = 1 - sum(test_predictionError .^ 2) / sum((test_power - mean(test_power)) .^ 2);

% 显示模型评估结果
disp('测试集平均绝对误差(MAE):');
disp(test_mae);
disp('测试集均方根误差(RMSE):');
disp(test_rmse);
disp('测试集决定系数(R2):');
disp(test_r2);

BP_pre_result = test_predictedPower;


% 可视化预测结果
figure;
plot(1:length(test_power), test_power, 'b', 'LineWidth', 1.5);
hold on;
plot(1:length(test_power), test_predictedPower, 'r', 'LineWidth', 1.5);
xlabel('样本索引');
ylabel('风电功率(kW)');
title('测试集实际值与预测值对比');
legend('实际值','预测值');
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);


%% 对比
figure;
plot(1:length(test_power), test_power, 'b-o', 'LineWidth', 1.5);
hold on;
plot(1:length(test_power), BP_pre_result, 'r-*', 'LineWidth', 1.5);
plot(1:length(test_power), RF_pre_result, 'g-^', 'LineWidth', 1.5);
plot(1:length(test_power), tree_pre_result, 'm-+', 'LineWidth', 1.5);
plot(1:length(test_power), SVM_pre_result, 'c-x', 'LineWidth', 1.5);
xlabel('样本索引');
ylabel('风电功率(kW)');
title('4个预测模型测试集实际值与预测值对比');
legend('实际值','BP','随机森林','决策树','精细高斯支持向量机','');
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);

%% 对比
figure;
plot(test_power(2000:2100), 'b-o', 'LineWidth', 1.5);
hold on;
plot( BP_pre_result(2000:2100), 'r-*', 'LineWidth', 1.5);
plot( RF_pre_result(2000:2100), 'g-^', 'LineWidth', 1.5);
plot( tree_pre_result(2000:2100), 'm-+', 'LineWidth', 1.5);
plot(SVM_pre_result(2000:2100), 'c-x', 'LineWidth', 1.5);
xlabel('样本索引');
ylabel('风电功率(kW)');
title('4个预测模型测试集实际值与预测值对比');
legend('实际值','BP','随机森林','决策树','精细高斯支持向量机','');
hold off;
set(gca, 'FontName', 'Microsoft YaHei', 'FontSize', 20);
