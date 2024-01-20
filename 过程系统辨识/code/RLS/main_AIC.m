%% DaISy dataset identification
% AIC to determine na and nb
clear;
close all;

%% initial
load('data.dat');
u=data(:,1);
z=data(:,2);
L=length(u);
%% AIC
K1=10;
K2=10;
K3=5;
%AIC=zeros(K1,K2,K3);
AIC=zeros(K1,K2);
for na=1:K1
    for nb=1:K2
        iter=L-max(na,nb);
        [~,~,J,~,~]=RLS(na,nb,z,u,iter);
        sigma_v2=J(iter)/iter;
        AIC(na,nb)=iter*log(sigma_v2)+2*(na+nb);
    end 
end
% %ARMAX
% for na=1:K1
%     for nb=1:K2
%         for nd=1:K3
%             iter=L-max(max(na,nb),nd);
%             [~,~,J,~,~]=RML(na,nb,nd,z,u,iter);
%             sigma_v2=J(iter)/iter;
%             AIC(na,nb,nd)=iter*log(sigma_v2)+2*(na+nb+nd);
%         end
%     end 
% end

plot_AIC(AIC);






