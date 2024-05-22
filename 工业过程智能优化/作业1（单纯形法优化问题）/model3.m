function [xm, fm, no_result] = model3(A, b, c)
    % 单纯形法求解线性规划问题
    % 输出xm为最优解，fm为最优函数值
    %% 初始化数据
    format rat %元素使用分数表示
    [m, n] = size(A);
    v = nchoosek(1:n, m);  %从n个元素中取m个元素的所有组合
    basisIndices = [];
    judge_count = 0;  % 记录判断次数
    no_result = false;  % 记录无解次数

    %% 提取可行解所在列
    for i = 1:size(v, 1)

        if isequal(A(:, v(i, :)), eye(m)) %在中心部位A中取v的第i种取法取出m列判断是否存在m*m大小的单位矩阵
            basisIndices = v(i, :);
        end

    end

    %% 提取非基变量的索引
    nonbasisIndices = setdiff(1:n, basisIndices); %非基变量的索引,返回在1:n中出现而不在basisIndices（即基变量索引中出现的元素），并从小到大排序

    while true
        x0 = zeros(n, 1);
        x0(basisIndices) = b;
        cB = c(basisIndices); %计算cB，即目标函数在基变量处对应的系数
        Sigma = zeros(1, n); %Sigma为检验数向量
        Sigma(nonbasisIndices) = c(nonbasisIndices)' - cB' * A(:, nonbasisIndices); %计算检验数（非基变量）
        [~, s] = min(Sigma); %选出最大检验数
        Theta = b ./ A(:, s);
        Theta(Theta <= 0) = 10000;
        [~, q] = min(Theta); %选出最小θ
        q = basisIndices(q);

        % 判断是否是最优解
        if ~any(Sigma < 0) %所有检验数都小于0，此基可行解为最优解
            xm = x0;
            fm = c' * xm; %算出最优解
            return
        else
            judge_count = judge_count + 1;
            if (judge_count > 1000)
                no_result = true;
                xm = [];
                fm = [];
                return
            end
        end

        % 判断是否有解
        if all(A(:, s) <= 0) %表示检验数这一列每个数都<=0，有无界解
            xm = [];
            break
        end

        % 换基
        basisIndices(basisIndices == q) = s; %新的基变量索引
        nonbasisIndices = setdiff(1:n, basisIndices); %非基变量索引
        % 旋转
        A(:, nonbasisIndices) = A(:, basisIndices) \ A(:, nonbasisIndices); %非基变量的部分等于（=）基变量索引的矩阵的逆乘剩余非基变量的矩阵
        b = A(:, basisIndices) \ b;
        A(:, basisIndices) = eye(m, m); %基变量索引的矩阵更换成单位矩阵
    end

end
