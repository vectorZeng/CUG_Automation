close all; 
clear all; 
clc
%%载入数据
load('data.dat');
u1=data(:,1);
z1=data(:,2);
u=u1';z=z1';
%%初始化数据
L=900;          %设置数据长度
n=5;            %设置模型阶次
h=n*(n+1)/2;    %1—n阶辨识参数的总长度
t=1;   
a=zeros(1,h);b=zeros(1,h);d=zeros(1,h); %设置1-n阶a、b、c参数的长度

%%迭代部分
for i=1:n
    N=3*i;
    theta0=10^-6*ones(N,1);      %初始化θ的值
    P0=eye(N,N);                 %初始话P的值
    theta=[theta0,zeros(N,L-1)]; %设置θ对应估计值的矩阵大小
    %赋初值
    zf(1:i)=z(1:i);
    uf(1:i)=u(1:i);
    vf(1:i)=0;v1(1:i)=0;
    %迭代求θ的估计值
    for k=i+1:L
    H=[-z(k-1:-1:k-i),u(k-1:-1:k-i),v1(k-1:-1:k-i)]'; %构建H矩阵
    Hf=[-zf(k-1:-1:k-i),uf(k-1:-1:k-i),vf(k-1:-1:k-i)]';%构建Hf矩阵
    v1(k)=z(k)-H'*theta0;                             
    K=P0*Hf*inv(Hf'*P0*Hf+1); %求K
    P=(eye(N,N)-K*Hf')*P0;    %求P
    theta1=theta0+K*v1(k);    %求θ
    %对P和θ进行迭代
    P0=P;                      
    theta0=theta1;
    theta(:,k)=theta1;  %将迭代所得θ进行保存
    zf(k)=z(k)-zf(k-1:-1:k-i)*theta1(N:-1:N-i+1);
    uf(k)=u(k)-uf(k-1:-1:k-i)*theta1(N:-1:N-i+1);
    vf(k)=v1(k)-vf(k-1:-1:k-i)*theta1(N:-1:N-i+1);
    end
    %%将获取辨识参数进行保存
    c1=theta(1:N,L)';  %获取θ最后的估计值 
    a1=c1(1,1:i); 
    a(1,t:t+i-1)=a1;  %对a参数进行储存
    b1=c1(1,i+1:2*i); 
    b(1,t:t+i-1)=b1; %对b参数进行储存
    d1=c1(1,2*i+1:N);   
    d(1,t:t+i-1)=d1; %对d参数进行储存
    t=t+i;
end
%%参数对应的阶次
n1=zeros(1,h);
 p=0;
for k=1:n
    for i=1:k
    n1(1,p+i)=k;
    end
    p=p+k;
end
T=table(n1',a',b',d','VariableNames',{'n' 'a' 'b' 'd'});%将不同阶次对应的各个参数保存


%%将所得模型进行对比
v=randn(1000,1); %生成方差为1,均值为0 的随机白噪声         
 L=900;            %设置数据长度
 e=0;              %误差设初值
 t=2;              %用于循环，根据不同的阶次变化模型乘上对应的参数
 n=4;              
 %%阶次从2到n循环，
for i=2:n
    %%根据n的变化构建出对应的模型方程
    for k=i+1:L+i
        %下面的a、b、d为RML算法程序部分中用于保存已经辨识出的所有参数
        z(k)=a(t:i+t-1)*(-z1(k-1:-1:k-i))+b(t:i+t-1)*u1(k-1:-1:k-i)+0.01*(v(k)+d(t:i+t-1)*v(k-1:-1:k-i)); %根据L长度求模型输出
        e(k)=z(k)-z1(k);  %求误差e
    end
    t=t+i;
    %输出相应n阶次时的模型输出z和数据输出z1
    figure(i)
    plot(z) 
    hold on;
    plot(z1)
    %输出相应n阶次时的两种输出误差
    figure(i+3)
    plot(e);
end

%% plot theta and rho
%plot theta
na=2;
nb=4;
c = ['r', 'g', 'b', 'c', 'm', 'k', 'y'];
para_num = size(theta, 1);
h = zeros(para_num, 1);
str = cell(1, para_num);
for i = 1:na
    str{i} = ['a_', num2str(i)];
end
for i = 1:nb
    str{i + na} = ['b_', num2str(i)];
end
%theta(:, end)
theta_final=mean(theta(:,end-5:end),2);
disp('theta :');
disp(theta_final);

figure;
hold on;
for i = 1:para_num
    h(i) = plot(1:L, theta(i, :), c(mod(i, length(c)) + 1));
    plot([1, L], [theta_final(i) theta_final(i)], [c(mod(i, length(c)) + 1), '--']);
end
legend(h, str);
xlabel('iteration');ylabel('parameter');,title('identification parameters');
set(findobj(get(gca,'Children'),'LineWidth',0.5),'LineWidth',2);
figure;
plot(1 : 900, theta, LineWidth=0.8);
xlabel(sprintf("k")); ylabel(sprintf("参数估计a、b、c"));
legend("a_1", "a_2", "b_0", "b_1", "c_1"); grid on; grid minor;
title(sprintf("参数估计值的变化过程"))