% Variable definition
clear all
clc

Cs = [473 -473; -473 473];
Cd = [23.2 -23.2; -23.2 23.2];
J = diag([2122 374]);
D = diag([425 50]);

% PID控制器参数
% Kp = 4829.95;    % 比例增益
% Ki = 10;
% Kd = 0;     % 微分增益（增加Kd）

% Kp = 2200;

Kp = 1500;
Ki = 794;
Kd = 0;     % 微分增益（增加Kd）

wd = 12;      % 期望角速度

% Simulation
m = 2;
% 初始条件：[角位移；角速度；摩擦力状态z；积分误差]
y0 = zeros(2*m+2,1);
opt = odeset('RelTol',1e-8);
% [t, x] = ode15s(@friction2, [0, 200], y0, opt);
[t, x] = ode15s(@(t, x) friction2(t, x, Kp, Ki, Kd), [0, 200], y0, opt);
% [t, x] = ode23(@(t, x) friction2(t, x, Kp, Ki, Kd), [0, 200], y0, opt);
% [t, x] = ode45(@(t, x) friction2(t, x, Kp, Ki, Kd), [0, 200], y0, opt);




% 绘制角速度曲线
figure(1)
plot(t, x(:, m+1), 'r--', 'LineWidth', 1);
hold on;
plot(t, x(:, 2*m), 'b-', 'LineWidth', 1);
legend('钻台', '钻头');
xlabel('时间 [s]');
ylabel('角速度 [rad/s]');
axis([0 200 0 70]);
grid on;
title('角速度随时间变化曲线');


% 计算并绘制控制力矩u
u = zeros(length(t), 1);
error_prev = 0;
for i = 1:length(t)
    e = wd - x(i, m+1);           % 当前误差
    e_int = x(i, end);            % 积分误差
    if i == 1
        de_dt = 0;
    else
        de_dt = (e - error_prev) / (t(i) - t(i-1)); % 误差的导数
    end
    error_prev = e;
    u(i) = Kp * e + Ki * e_int + Kd * de_dt;   % 增加微分项

end


figure(2)
plot(t, u, 'b', 'LineWidth', 1);
xlabel('时间 [s]');
ylabel('控制力矩 [N]');
axis([0 200 -200 70000]);
grid on;
title('控制力矩随时间变化曲线');

%% 计算动态和稳态指标
omega_target = x(:, m+1); % 钻台角速度
steady_state_value = mean(omega_target(end-100:end)); % 使用最后100个点的平均值作为稳态值

% 稳定时间：当输出保持在最终值的±2%范围内
settling_threshold = 0.02 * wd; 
settling_indices = find(abs(omega_target - wd) <= settling_threshold);
if ~isempty(settling_indices)
    % 查找连续满足条件的最小时间点
    for i = 1:length(settling_indices)-1
        if all(abs(omega_target(settling_indices(i):end) - wd) <= settling_threshold)
            settling_time = t(settling_indices(i));
            break;
        end
    end
else
    settling_time = inf;
end

% 最大超调量
peak_value = max(omega_target);
if peak_value > wd
    overshoot_percent = (peak_value - wd) / wd * 100;
else
    overshoot_percent = 0;
end

% 上升时间：从10%到90%的响应时间
rise_start_idx = find(omega_target >= 0.1*wd, 1);
rise_end_idx = find(omega_target >= 0.9*wd, 1);
if ~isempty(rise_start_idx) && ~isempty(rise_end_idx)
    rise_time = t(rise_end_idx) - t(rise_start_idx);
else
    rise_time = inf;
end

% 稳态误差
steady_state_error = abs(wd - steady_state_value);

% 显示性能指标
fprintf('\n系统性能指标:\n');
fprintf('稳定时间: %.2f 秒\n', settling_time);
fprintf('最大超调量: %.2f%%\n', overshoot_percent);
fprintf('上升时间: %.2f 秒\n', rise_time);
fprintf('稳态误差: %.2f rad/s\n', steady_state_error);

% 绘制性能指标图
figure(3)
plot(t, omega_target, 'b', 'LineWidth', 1);
hold on;
% 绘制目标值
plot([0 max(t)], [wd wd], 'k--');
% 绘制±2%范围
plot([0 max(t)], [wd*(1+0.02) wd*(1+0.02)], 'r:');
plot([0 max(t)], [wd*(1-0.02) wd*(1-0.02)], 'r:');
% 标注性能指标
if ~isinf(settling_time)
    plot(settling_time, omega_target(settling_indices(1)), 'ro');
    text(settling_time, omega_target(settling_indices(1)), sprintf('稳定时间: %.2fs', settling_time));
end
if overshoot_percent > 0
    [max_val, max_idx] = max(omega_target);
    plot(t(max_idx), max_val, 'ro');
    text(t(max_idx), max_val, sprintf('最大超调: %.2f%%', overshoot_percent));
end
xlabel('时间 [s]');
ylabel('角速度 [rad/s]');
title('系统响应与性能指标');
grid on;
legend('系统响应', '目标值', '±2%范围');




%% Function definition
function dx = friction2(t, x, Kp, Ki, Kd)
    % 系统参数
    Cs = [473 -473; -473 473];    % 刚度矩阵
    Cd = [23.2 -23.2; -23.2 23.2];% 阻尼矩阵
    J = diag([2122 374]);         % 惯性矩阵
    D = diag([425 50]);           % 阻力矩阵
    
    % PID控制器参数
    % Kp = 2500;
    % Ki = 0;
    % Kd = 0;   % 增加Kd

    wd = 12;  % 期望角速度

    % 状态变量
    m = 2;
    theta = x(1:m);
    omega = x(m+1:2*m);
    z = x(2*m+1);      % 摩擦力状态
    e_int = x(2*m+2);  % 积分误差

    % 误差计算
    e = wd - omega(1);

    % 使用 persistent 变量计算误差导数
    persistent last_error last_t
    if isempty(last_error)
        last_error = e;
        last_t = t;
    end
    dt = t - last_t;
    if dt == 0
        de_dt = 0;
    else
        de_dt = (e - last_error) / dt;
    end
    last_error = e;
    last_t = t;

    % 计算控制力矩u
    u = Kp * e + Ki * e_int + Kd * de_dt;

    % LuGre摩擦模型参数
    uc = 0.3; us = 0.35; vs = 0.01;
    sita0 = 25; sita1 = 193;
    u0 = 40000;

    % 计算摩擦力
    g = uc + (us - uc) * exp(-(omega(2)/vs)^2);
    dz = omega(2) - sita0 * abs(omega(2)) * z / g;
    mu = sita0 * z + sita1 * dz;

    % 摩擦力矩Ft
    Ft = u0 * mu;

    % 系统矩阵
    Pi = 0.01 * eye(m);
    A1 = Pi - J \ (Cd + D);
    A2 = -A1 * Pi - J \ Cs;
    B1 = J \ [1; 0];
    B2 = -J \ [0; 1];

    % 状态方程
    dx = zeros(2*m+2, 1);
    dx(1:m) = -Pi * theta + omega;
    dx(m+1:2*m) = A1 * omega + A2 * theta + B1 * u + B2 * Ft;
    dx(2*m+1) = dz;     % 更新摩擦力状态z
    dx(2*m+2) = e;      % 积分误差的导数为当前误差
end


