function objective = objectiveFcn(x,y,z)
% 此函数应返回一个表示优化目标的标量。

% 示例: 小吃摊位利润
% revenue = 3*soda + 5*popcorn + 2*candy;
% cost = 1*soda + 2*popcorn + 0.75*candy;
% objective = revenue - cost; % profit

% 编辑以下行以添加您的计算方法。
load tree tree_trainedModel
load data input_test
load flag i
depth = input_test(i,1);
pre = [depth,x,y,0,z,0];

objective = tree_trainedModel.predictFcn(pre);
end
