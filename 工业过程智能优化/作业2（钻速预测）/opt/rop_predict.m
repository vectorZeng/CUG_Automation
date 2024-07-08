%% 钻速预测部分
%% 导入数据
load ROP_sn.mat
xvalues = {'Depth','WOB','RPM',...
        'Torque','PumpFlow','SPP','ROP'};
rop_table = array2table(ROP_sn,'VariableNames',xvalues);
%% 数据清理
% 画箱线图
label = rop_table.Properties.VariableNames(:,idx(:,1:7));
  figure
  
for i = 1:7
    subplot(1, 7, i); % 1行7列，第i个子图
    boxchart(ROP_sn(:, i));
    title([label(i)]);
    ylabel('Value');
end

% 四分法+线性插值处理异常值

%rop_filted = filloutliers(rop_table,"linear","quartiles");
rop_filted = ROP_sn;
rop_filted(13,:) = [];
%% 相关性分析 绘制热力图
filted = table2array(rop_filted);

x = corr(filted,'Type','Spearman');

figure(1)


h = heatmap(xvalues,xvalues,x);

h.Title = 'Corelation Heatmap';
h.XLabel = 'features';
h.YLabel = 'features';

%% 按相关性

figure(2)
cor = x(7,:);
T = array2table(cor, 'VariableNames',{'Depth','WOB','RPM',...
        'Torque','PumpFlow','SPP','ROP'});

% 对T表按照第一行降序排序
[~, idx] = sort(abs(T{1,:}), 'descend');
T_sorted = T(:,idx);
T_sorted = T_sorted(:,2:end);
bar(T_sorted{1,:});
xticks(1:length(xvalues));
xticklabels(T_sorted.Properties.VariableNames);
xlabel('feature');
ylabel('correlation coefficient');
title('Correlation between ROP and features');
a = T_sorted.Properties.VariableNames
% 标明每个值的标签
text(1:6, T_sorted{1,:}, num2str(T_sorted{1,:}', '%.2f'), ...
    'HorizontalAlignment', 'center', 'VerticalAlignment', 'bottom');


%% 数据集划分
input1 = rop_filted(:,1:6);
output1 = rop_filted(:,7);
input_train = input1(1:84,:);
output_train = output1(1:84,:);
input_test = input1(85:end,:);
output_test = output1(85:end,:);
predict_test = tree_trainedModel.predictFcn(input_test);

save data input_train output_train input_test output_test
%% 预测
plot(output_test,'b-o','LineWidth',1.5)
hold on
plot(predict_test,'r-*','LineWidth',1.5)
legend('真实值','预测值','fontsize',20)

%% predict BO-RF

depth = input1(:,1);

Y = output1;
result = bo_rf_trainedModel.predictFcn(rop_filted(:,1:6));
predict_y = result;
rf_pre = predict_y;
figure

plot(depth,Y,'b--o')
hold on
plot(depth,predict_y,'r-*')

legend('Measured Value','Predicted Value')
title('BO-Random Forest')
xlabel('Depth')
ylabel('ROP')
view(90, 90);
hold off

[fitresult.train, gof.train] = fit( predict_y, Y, 'poly1' );
R = gof.train.rsquare;

% 计算均方根误差（RMSE）
rmse = sqrt(mean((predict_y - Y).^2));

% 计算平均绝对误差（MAE）
mae = mean(abs(predict_y - Y));

compare(1,:) = [{'BO-RF'},R,rmse,mae];

figure
plot(fitresult.train,predict_y,Y)
maintitle = 'BO-Random Forest';
subtitle = ['R' char(0xB2) '=', num2str(R),',RMSE = ',num2str(rmse), ', MAE=', num2str(mae)];
title({maintitle;subtitle});
xlabel('True ROP Value')
ylabel('Predict ROP Value')
legend('data','Field ROP')
%% BO-GPR


depth = input1(:,1);
Y = output1;
    result = bo_gpr_trainedModel.predictFcn(rop_filted(:,1:6));
    predict_y = result;
    GPR = predict_y;

figure(3)

plot(depth,Y,'b--o')
hold on
plot(depth,predict_y,'r-*')

legend('Measured Value','Predicted Value')
title('BO-GPR')
xlabel('Depth')
ylabel('ROP')
view(90, 90);
hold off

[fitresult.train, gof.train] = fit( predict_y, Y, 'poly1' );
R = gof.train.rsquare;

% 计算均方根误差（RMSE）
rmse = sqrt(mean((predict_y - Y).^2));

% 计算平均绝对误差（MAE）
mae = mean(abs(predict_y - Y));

compare(2,:) = [{'BO-GPR'},R,rmse,mae];

figure(4)
plot(fitresult.train,predict_y,Y)
maintitle = 'GPR';
subtitle = ['R' char(0xB2) ' = ', num2str(R),', RMSE = ',num2str(rmse), ', MAE = ', num2str(mae)];
title({maintitle;subtitle});
xlabel('True ROP Value')
ylabel('Predict ROP Value')
legend('data','Field ROP')

%% tree
% load mod.mat
depth = input1(:,1);
Y = output1;
    result = bo_tree_trainedModel.predictFcn(rop_filted(:,1:6));
    predict_y = result;
    tree_pre = predict_y;

figure(5)
plot(depth,Y,'b--o')
hold on
plot(depth,predict_y,'r-*')


legend('Measured Value','Predicted Value')
title('Decision Tree')
xlabel('Depth')
ylabel('ROP')
view(90, 90);
hold off

[fitresult.train, gof.train] = fit( predict_y, Y, 'poly1' );
R = gof.train.rsquare;

% 计算均方根误差（RMSE）
rmse = sqrt(mean((predict_y - Y).^2));

% 计算平均绝对误差（MAE）
mae = mean(abs(predict_y - Y));

compare(3,:) = [{'Decision Tree'},R,rmse,mae];

figure(6)
plot(fitresult.train,predict_y,Y)
maintitle = 'Decision Tree';
subtitle = ['R' char(0xB2) ' = ', num2str(R),', RMSE = ',num2str(rmse), ', MAE = ', num2str(mae)];
title({maintitle;subtitle});
xlabel('True ROP Value')
ylabel('Predict ROP Value')
legend('data','Field ROP')

%% kernel
% load mod.mat
depth = input1(:,1);
Y = output1;
    result = bo_kernel_trainedModel.predictFcn(rop_filted(:,1:6));
    predict_y = result;
    kernel_pre = predict_y;

figure(7)
plot(depth,Y,'b--o')
hold on
plot(depth,predict_y,'r-*')


legend('Measured Value','Predicted Value')
title('BO-kernel')
xlabel('Depth')
ylabel('ROP')
view(90, 90);
hold off

[fitresult.train, gof.train] = fit( predict_y, Y, 'poly1' );
R = gof.train.rsquare;

% 计算均方根误差（RMSE）
rmse = sqrt(mean((predict_y - Y).^2));

% 计算平均绝对误差（MAE）
mae = mean(abs(predict_y - Y));

compare(4,:) = [{'BO-kernel'},R,rmse,mae];

figure(8)
plot(fitresult.train,predict_y,Y)
maintitle = 'BO-kernel';
subtitle = ['R' char(0xB2) ' = ', num2str(R),', RMSE = ',num2str(rmse), ', MAE = ', num2str(mae)];
title({maintitle;subtitle});
xlabel('True ROP Value')
ylabel('Predict ROP Value')
legend('data','Field ROP')
set(gca, 'FontSize', 25, 'FontName', 'Times New Roman');
%% compare
figure 
plot(depth,Y,'b--o',...
    depth,rf_pre,'r-*', ...
    depth,GPR,'m-+',...
    depth,tree_pre,'g-^',...
    depth,kernel_pre,'c-^')

legend('Measured Value','BO-RF','BO-GPR','Desicion Tree','BO-kernel')
title('Comparison of prediction results')
xlabel('Depth')
ylabel('ROP')
view(90, 90);
set(gca, 'FontSize', 20, 'FontName', 'Times New Roman');
%% 
compare_table = cell2table(compare);