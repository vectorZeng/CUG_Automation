%% 导入数据
%save simout_normal simout
load select.mat
load simout_00.mat


%% 最初数据可视化
figure(1)
subplot(2,2,2)
histogram(simout_00(:,1))
title('A物料流量 直方图', 'FontWeight', 'bold', 'FontSize', 14)
subplot(2,2,1)    
plot(1:7201,simout_00(:,1))
title('A物料流量 原始数据', 'FontWeight', 'bold', 'FontSize', 14)
subplot(2,2,3)
boxplot(simout_00(:,1),'Labels','A物料流量','Whisker',1)
title('A物料流量 箱体图', 'FontWeight', 'bold', 'FontSize', 14)
subplot(2,2,4)
area(1:7201,simout_00(:,1))
title('A物料流量 填充区二维绘图', 'FontWeight', 'bold', 'FontSize', 14)
figure
boxplot(simout_00)
title('41个变量的统计分布箱体图','FontWeight', 'bold', 'FontSize', 14)
%% 小波去噪
figure(2)
subplot(5,1,1)
plot(1:size(simout_00,1),simout_00(:,1))
title('A物料流量-去噪前', 'FontWeight', 'bold', 'FontSize', 14)
subplot(5,1,2)
simout_00wde = wdenoise(simout_00);
plot(1:size(simout_00wde,1),simout_00wde(:,1))
title('A物料流量-小波去噪', 'FontWeight', 'bold', 'FontSize', 14)
subplot(5,1,3)
simout_00mov = smoothdata(simout_00,"movmedian",20);
plot(1:size(simout_00mov,1),simout_00mov(:,1))
title('A物料流量-移动中位数滤波', 'FontWeight', 'bold', 'FontSize', 14)
subplot(5,1,4)
simout_00mean = smoothdata(simout_00,"movmean",20);
plot(1:size(simout_00mov,1),simout_00mov(:,1))
title('A物料流量-移动均值滤波', 'FontWeight', 'bold', 'FontSize', 14)
subplot(5,1,5)
simout_00mean = smoothdata(simout_00,"sgolay",20);
plot(1:size(simout_00mov,1),simout_00mov(:,1))
title('A物料流量-S-G滤波', 'FontWeight', 'bold', 'FontSize', 14)
%% 移动均值滤波比较
figure
subplot(4,1,1)
plot(1:size(simout_00,1),simout_00(:,1))
title('A物料流量-去噪前', 'FontWeight', 'bold', 'FontSize', 14)
subplot(4,1,2)
simout_00mov1 = smoothdata(simout_00,"movmean",10);
plot(1:size(simout_00mov1,1),simout_00mov1(:,1))
title('A物料流量-均值滤波-k=10', 'FontWeight', 'bold', 'FontSize', 14)
subplot(4,1,3)
simout_00mov2 = smoothdata(simout_00,"movmean",20);
plot(1:size(simout_00mov2,1),simout_00mov2(:,1))
title('A物料流量-均值滤波-k=20', 'FontWeight', 'bold', 'FontSize', 14)
subplot(4,1,4)
simout_00mov3 = smoothdata(simout_00,"movmean",30);
plot(1:size(simout_00mov3,1),simout_00mov3(:,1))
title('A物料流量-均值滤波-k=30', 'FontWeight', 'bold', 'FontSize', 14)

%% 小波变换分解
A_feed = simout_00(:,1);
[cl,ll] = wavedec(A_feed,3,'db3');
approx1 = appcoef(cl,ll,'db3');
[cdd1,cdd2,cdd3] = detcoef(cl,ll,[1,2,3]);
sgtitle('小波变换分解', 'FontWeight', 'bold', 'FontSize', 14)
subplot(4,1,1)
plot(approx1);
title("Approximation Coefficients")
subplot(4,1,2)
plot(cdd3);
title("Level 3 Detail Coefficients")
subplot(4,1,3)
plot(cdd2);
title("Level 2 Detail Coefficients")
subplot(4,1,4)
plot(cdd1);
title("Level 1 Detail Coefficients")
%% 归一化
figure(3)
subplot(3,1,1)
plot(1:size(simout_00wde,1),simout_00wde(:,1))
title('A物料流量-归一化前', 'FontWeight', 'bold', 'FontSize', 14)
%进行最大最小归一化
subplot(3,1,2)
simout_00maxminT = mapminmax(simout_00wde');
simout_00maxmin = simout_00maxminT';
plot(1:size(simout_00maxmin,1),simout_00maxmin(:,1))
title('A物料流量-最大最小归一化', 'FontWeight', 'bold', 'FontSize', 14)
%进行Z分数变换
subplot(3,1,3)
simout_00zscore = zscore(simout_00wde);
plot(1:size(simout_00zscore,1),simout_00zscore(:,1))
title('A物料流量-z分数归一化', 'FontWeight', 'bold', 'FontSize', 14)


%% PCA降维
simout_00zscore = zscore(simout_00wde);
[coeff,score,latent,tsquared,explained] = pca(simout_00zscore);
num = min(find(explained>2,1,'last'),22);
explained_pc = explained(1:num,1);
contribution = sum(explained_pc);
for i = 1:num
    fprintf('第%d个主成分的贡献度为%f%%\n',i,explained_pc(i,1));
end
fprintf('22个主成分总贡献度为%f%%\n',contribution);
X = categorical({'PC1','PC2','PC3','PC4','PC5','PC6','PC7','PC8','PC9','PC10', ...
    'PC11','PC12','PC13','PC14','PC15','PC16','PC17','PC18','PC19','PC20','PC21','PC22'});
X = reordercats(X,{'PC1','PC2','PC3','PC4','PC5','PC6','PC7','PC8','PC9','PC10', ...
    'PC11','PC12','PC13','PC14','PC15','PC16','PC17','PC18','PC19','PC20','PC21','PC22'});

figure
bar(X,explained_pc);
xlabel('主成分');
ylabel('贡献度');
title('主成分降维', 'FontWeight', 'bold', 'FontSize', 14);

