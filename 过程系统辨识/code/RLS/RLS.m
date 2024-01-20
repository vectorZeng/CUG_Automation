%% RLS

function [theta, Inn, J, lambda,epsilon] = RLS(n_a, n_b, z, u, L)

nMax = max(n_a, n_b);
h = zeros(n_a + n_b, L + nMax);
s = zeros(L + nMax, 1);
Inn = zeros(L + nMax, 1); % new information
K = zeros(n_a + n_b, L + nMax); % gain
P = ones(n_a + n_b, n_a + n_b, L + nMax); % Covariance matrix
P(:, :, nMax) = eye(n_a + n_b) * 1000;
theta = ones(n_a + n_b, L + nMax) * 0.0001; % model parameter
J = zeros(L + nMax, 1); %loss function

for k = nMax + 1 : L + nMax
    
    for i = 1:n_a
        h(i, k) = -z(k - i);
    end
    for i = 1:n_b
        h(n_a + i, k) = u(k - i);
    end
%     if z(k) == 0
%         z(k) = h(:, k)' * theta(:, k-1);
%     end
    %update variable
    s(k) = h(:, k)' * P(:, :, k-1) * h(:, k) + 1.0;
    Inn(k) = z(k) - h(:, k)' * theta(:, k-1);
    K(:, k) = P(:, :, k-1) * h(:, k) / s(k);
    P(:, :, k) = P(:, :, k-1) - K(:, k) * K(:, k)' * s(k);
    theta(:, k) = theta(:, k-1) + K(:, k) * Inn(k);
    % count loss
    J(k) = J(k-1) + Inn(k)^2 / s(k);
end

theta = theta(:, nMax+1 : end);
Inn = Inn(nMax+1 : end);
lambda = sqrt(J(L + nMax) / L);
epsilon = z(nMax+1:nMax+L) - h(:, nMax + 1 : nMax + L)' * theta(:, end);

end
