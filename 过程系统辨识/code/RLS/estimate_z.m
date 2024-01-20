function z_est=estimate_z(theta,na,nb,u,z,L)
L=L+max(na,nb);
nMax = max(na, nb);
h = zeros(na + nb, 1);
z_est=z;
for k = nMax+1 : L
    for i = 1:na
        h(i) = -z_est(k - i);
    end
    for i = 1:nb
        h(na + i) = u(k - i);
    end
    z_est(k) = h' * theta;
end

figure;
hold on;
plot(1:L,z,'b');
plot(1:L,z_est,'r');
legend('real output','estimate output');
title('real output and estimate output');
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);
hold off;
end