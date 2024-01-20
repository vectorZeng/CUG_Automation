%% DaISy dataset identification
clear;
close all;

%% initial
load('data.dat');
u=data(:,1);
z=data(:,2);
% %plot(z);
L=length(u);
na=2;
nb=4;
L=L-max(na,nb);

%% parameter identification
[theta, Inn, J, lambda,epsilon] = RML(na, nb, z, u, L);
theta_final=mean(theta(:,end-5:end),2);
disp('theta :');
disp(theta_final);
%% estimate z
z_est=estimate_z(theta_final,na,nb,u,z,L);
%% epsilon
epsilon=epsilon(1:L);
R=xcorr(epsilon, 'unbiased');
m=30;
rho=R(L+1:L+m)/R(L);
t1=L*sum(rho.^2);
t2=m+1.65*sqrt(2*m);
t3=max(abs(rho));
t4=1.98/sqrt(L);
disp(['mean(epsilon)=',num2str(mean(epsilon))]);
disp(['L*sum(rho.^2)=',num2str(t1),'<=m+1.65*sqrt(2*m)=',num2str(t2)]);
disp(['max(abs(rho))=',num2str(t3),'<=1.98*sqrt(L)=',num2str(t4)]);


%% plot theta and rho
%plot theta
c = ['r', 'g', 'b', 'c', 'm', 'k', 'y',];
para_num = size(theta, 1);
h = zeros(para_num, 1);
str = cell(1, para_num);
for i = 1:na
    str{i} = ['a_', num2str(i)];
end
for i = 1:nb
    str{i + na} = ['b_', num2str(i)];
end
for i = 1:2
       str{na + nb + i} = ['d_', num2str(i)];
end
figure;
hold on;
for i = 1:para_num
    h(i) = plot(1:L, theta(i, :), c(mod(i, length(c)) + 1));
    plot([1, L], [theta_final(i) theta_final(i)], [c(mod(i, length(c)) + 1), '--']);
end
legend(h, str);
xlabel('iteration');ylabel('parameter');,title('identification parameters');
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);

%plot epsilon
figure;
plot(epsilon);
xlabel('iteration');title('epsilon');
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);

%plot Autocorrelation coefficient
figure;
stem(rho);
xlabel('m');title('autocorrelation coefficient');
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);





