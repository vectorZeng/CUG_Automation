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