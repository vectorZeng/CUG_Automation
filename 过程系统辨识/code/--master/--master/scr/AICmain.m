close all; 
clear all; 
clc; 
%%导入输入输出数据
load('data.dat');
u=data(:,1);
z=data(:,2);
L=length(u);
Hf=0;theta=0;            %赋初值 Hf1=[L,n];Hf2=[L,n]
L=800;                   %长度N为数据长度
n=10;                     %阶次数设置
for i=1:n                %阶次长度设置
    na=i;nd=i;                      
    Hf1=zeros(L,i);Hf2=zeros(L,i);
    %%构建Hf矩阵
    for t=1:i
        Hf1(1:L,i-t+1)=-z(t:L+t-1);
        Hf2(1:L,i-t+1)=u(t:L+t-1);
    end
    Hf=[Hf1,Hf2];
    %%求噪声方差
    x1=inv(Hf'*Hf);  
    theta=x1*Hf'*z(i+1:i+L);
    e(i+1:L+i,1)=z(i+1:L+i)-Hf*theta; 
    ee=e'*e/L; 
    %%根据AIC准则求解AIC
    AIC(i)=L*log(ee)+3*(i);
end
plot(1:i,AIC,'*-');
title('阶次判断')


