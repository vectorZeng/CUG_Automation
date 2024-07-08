%% 钻速优化部分

% 创建优化变量
WOB13 = optimvar("WOB","LowerBound",1,"UpperBound",23.14);
RPM9 = optimvar("RPM","LowerBound",88,"UpperBound",102);
Q6 = optimvar("Q","LowerBound",15.5,"UpperBound",18);

for i = 1:10
save flag i

% 设置求解器的初始起点
initialPoint10.WOB = input_test(i,2);
initialPoint10.RPM = input_test(i,3);
initialPoint10.Q = input_test(i,5);

% 创建问题 钻速最大化 max ROP
problem = optimproblem("ObjectiveSense","Maximize");

% 定义问题目标
problem.Objective = fcn2optimexpr(@objectiveFcn,WOB13,RPM9,Q6);

% 定义问题约束
problem.Constraints.constraint1 = WOB13*RPM9 <= 1657.45;
problem.Constraints.constraint2 = 2*(5.59 - 0.0162*WOB13)/(0.5*RPM9 + 2.18*10^(-5)*RPM9^3) >= 200;
%problem.Constraints.constraint3 = objectiveFcn(WOB15,RPM11,Q8) <= 4.2;

% 显示问题信息
show(problem);

% 求解问题
[solution(i),objectiveValue(i),reasonSolverStopped] = solve(problem,initialPoint10,...
    "Solver","fmincon");

% 显示结果
solution(i)
reasonSolverStopped
objectiveValue(i)
end
%% 优化前后对比
figure
plot(objectiveValue,'r-*','LineWidth',1.5)
hold on
plot(output_test,'b-o','LineWidth',1.5);
plot(predict_test,'g-^','LineWidth',1.5);
legend('优化后','实际值','预测值')
title('测试集优化钻速')
xlabel('样本')
ylabel('输出')
set(gca, 'FontSize', 18);