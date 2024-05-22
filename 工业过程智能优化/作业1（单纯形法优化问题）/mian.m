% 单纯形法求解线性规划
clc, clear;

%% 获取用户输入
matrix = get_input();

A = matrix(1:end - 1, 1:end - 1);  % 约束方程组系数矩阵
b = matrix(1:end - 1, end); % 约束方程组常数项
c = -matrix(end, 1:end - 1)';  % 目标函数系数向量（归一化为min）

%% 调用函数，求解线性规划，输出计算结果
[xm, fm, no_result] = model3(A, b, c);

% 输出结果
if no_result == 1
    fprintf('无最优解\n');
else
    fprintf('\n最优解为：')

    for i = 1:length(xm)
        fprintf('x%d=%d ', i, xm(i));
    end

    fprintf('')
    fprintf('\n最优函数值为：%d\n', -fm);
end

