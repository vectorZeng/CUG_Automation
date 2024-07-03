%% 相关性分析
[R,P] = corrcoef(simout_00maxmin);
figure
h = heatmap(R);
title('变量间的相关系数热力图');
%% 大于0.8的强相关变量
power = 0.8;
%将强相关的变量筛选出来，并放入矩阵中 (行 列 相关系数)
scorr = [];
max_scorr = [0,0,0];%用于存放最强相关的变量
%用于计数
scor_set = 0;
for i = 2:size(simout_00maxmin,2)
    for ii=1:i-1
        if abs(R(ii,i)) > power
            scor_set = scor_set + 1;
            scorr(scor_set,:) = [ii,i,R(ii,i)];
        end
    end
end
out_1 = ['共找到 ',num2str(scor_set),' 个强相关变量'];
disp(out_1)
disp(scorr)
%取出最强相关的变量
for i = 1:size(scorr,1)
    if abs(scorr(i,3)) > abs(max_scorr(1,3))
       max_scorr(1,:) = scorr(i,:); 
    end
end
disp('最强相关变量为：')
disp(max_scorr)
%强相关变量间的对比
figure
sgtitle('强相关变量间的趋势对比', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,1)
plot(simout_00maxmin(:,7))
title('第7个变量', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,2)
plot(simout_00maxmin(:,13))
title('第13个变量', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,3)
plot(simout_00maxmin(:,16))
title('第16个变量', 'FontWeight', 'bold', 'FontSize', 14)
figure
sgtitle('强相关变量间的趋势对比', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,1)
plot(simout_00maxmin(:,20))
title('第20个变量', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,2)
plot(simout_00maxmin(:,5))
title('第5个变量', 'FontWeight', 'bold', 'FontSize', 14)
subplot(3,1,3)
plot(simout_00maxmin(:,6))
title('第6个变量', 'FontWeight', 'bold', 'FontSize', 14)
%% scatter matrix
 figure
 sgtitle('5对强相关变量间的散点拟合图', 'FontWeight', 'bold', 'FontSize', 14)
for i=1:5
   
c1 = scorr(i,1);
c2 = scorr(i,2);
c3 = scorr(i,3);
x = simout_00(:,c1);
y = simout_00(:,c2);
fitresult = fit(x, y, 'poly1' );
subplot(3,2,i)
plot(fitresult,x,y)
 xlabel(['第',num2str(c1),'个变量'])
ylabel(['第',num2str(c2),'个变量'])
title(['第',num2str(c1),'个和第',num2str(c2),'个变量之间的散点图, 相关系数：',num2str(c3)], 'FontWeight', 'bold', 'FontSize', 14)
end

%% 最小二乘法
%被拟合数据可视化
figure
x = simout_00maxmin(:,max_scorr(:,1));
y = simout_00maxmin(:,max_scorr(:,2));

plot(x,y,'bo')
grid on
hold on  %在下一幅图中保持
%用一次函数拟合
%[fitresult, gof] = poly(test_x, test_y)
% plot(fitresult,x,y)
p = polyfit(x,y,1);%得到斜率和截距
pre = polyval(p,x);%得到拟合曲线的纵坐标
plot(x,pre,'r-','LineWidth',1)
hold on
axis([-1 1 -1 1])
xlabel(['变量',num2str(max_scorr(:,1))]);
ylabel(['变量',num2str(max_scorr(:,2))]); 
title('第7个变量和第16个变量的最小二乘法拟合曲线, y = 0.9863x - 0.015', 'FontWeight', 'bold', 'FontSize', 14)  
legend('data','拟合曲线')
%误差分析
[MAE] = claMAE(pre,y)
[RMSE] = claRMSE(pre,y)

%% 第29个成分变量的回归分析
R29 = R(29,1:22);

% 将数组 R 转换为表，列的名称是1到22
T = array2table(R29, 'VariableNames',cellstr(num2str((1:22)')));

% 对T表按照第一行降序排序
[~, idx] = sort(abs(T{1,:}), 'descend');
T_sorted = T(:,idx);
figure
bar(T_sorted{1,:});
xticks(1:22);
xticklabels(T_sorted.Properties.VariableNames);
xlabel('过程变量');
ylabel('相关系数');
title('第29个成分变量与过程变量之间的相关系数', 'FontWeight', 'bold', 'FontSize', 14);
% 在条形图上显示数值
for i = 1:numel(T_sorted{1, :})
    text(i, T_sorted{1, i}, num2str(T_sorted{1, i}, '%.2f'), 'HorizontalAlignment', 'center', 'VerticalAlignment', 'bottom');
end
%% 做回归的表


% 选取第20，5，6，18，14，12，22，11，19，29列的数据
selected_columns = [20, 5, 6, 18, 14, 12, 22, 11, 19, 29];
selected_data = simout_00wde(:, selected_columns);

% 创建一个表，指定列名称为20, 5, 6, 18, 14, 12, 22, 11, 19, 29
predict29 = array2table(selected_data, 'VariableNames', cellstr(num2str(selected_columns')));

%% 回归模型对比
reg29_rf = bo_rf_29trainedModel.predictFcn(predict29(:,1:9));
reg29_tree = tree_reg29_trainedModel.predictFcn(predict29(:,1:9)) ;
reg29_gpr = GPR_trainedModel.predictFcn(predict29(:,1:9)) ;
orgdata = predict29.("29");
figure
hold on
plot(orgdata(100:200),'b--o')
plot(reg29_rf(100:200),'r-*')
plot(reg29_tree(100:200),'g-^')
plot(reg29_gpr(100:200),'m-+')
legend('原始数据','随机森林预测','决策树','高斯过程回归')
xlabel('样本')
ylabel('响应')
hold off

