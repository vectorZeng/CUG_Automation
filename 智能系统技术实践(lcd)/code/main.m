
% This m file is the main function used to calculate the response of
% drill-string subject to active control and bit-rock interaction.
%function main 
% clc
% clear all
%close all

% Solving state feeedback gain and observer gain
[Ks,G,P,E] = LQR_PolePlacement;

%Ks1 = Ks(1:end-1);
Ks1 = [735,2490,505,248,612,909,960,1000];
C_3 = [1 0 0 0 0 0 0 0;
     0 0 0 0 0 0 1 0;
     0 0 0 1 0 0 0 0];
C_37 = [1 0 0 0 0 0 0;
     0 0 0 0 0 0 1;
     0 0 0 1 0 0 0];
% C = [1 0 0 0 0 0 0];
% B_1 = [1/J1;0;0;0;0;0;0;];
% Ks -> state feeedback gain
% G -> observer gain
%%
% simulation time
time = [0 100];

% the total number of state is 15
% x1-x7->original system states
% x1->speed of rotary table
% x2->speed of pipe
% x3->speed of collar
% x4->speed of bit
% x8->state of the internal model
% x9-x15->states of observer
x0 = zeros(15,1); 

% Solving the whole system (ODE) via ode45 method
[t45,x45] = ode45(@drillstring,time,x0,[],Ks,G);
[t23,x23] = ode23(@drillstring,time,x0,[],Ks,G);
[t15,x15] = ode15s(@drillstring,time,x0,[],Ks,G);


%% ode45
figure(1)
set(gcf,'Position',[300,300,800,400])
hold on
plot([0,100],[12,12],'r--','LineWidth',2)
plot(t45,x45(:,1),'g',t45,x45(:,4),'b','LineWidth',2);
legend('Reference','Rotary table speed','Bit speed')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 20])
grid on
box on

set(gca,"fontsize",20)

figure(2)
plot([0,100],[12,12],'r--','LineWidth',2)
hold on
set(gcf,'Position',[300,300,800,400])
plot(t45,x45(:,4),'b',t45,x45(:,12),'m--','LineWidth',2);
legend('Reference','Bit speed','Observed bit speed')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 20])
grid on
box on
set(gca,"fontsize",20)

%% ode compare
% rotary speed
figure(3)
set(gcf,'Position',[300,300,800,400])
hold on
plot([0,100],[12,12],'r--','LineWidth',2)
plot(t15,x15(:,1),'m',t23,x23(:,1),'g',t45,x45(:,1),'b','LineWidth',2);
legend('Reference','ode15','ode23','ode45')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 20])
grid on
box on

set(gca,"fontsize",20)

% 

figure(4)
set(gcf,'Position',[300,300,800,400])
hold on
plot([0,100],[12,12],'r--','LineWidth',2)
plot(t15,x15(:,4),'m',t23,x23(:,4),'g',t45,x45(:,4),'b','LineWidth',2);
legend('Reference','ode15','ode23','ode45')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 20])
grid on
box on

set(gca,"fontsize",20)

%%

[t45_raw,x45_raw] = ode45(@drillstring_raw,time,zeros(8,1),[]);    

figure(4)
set(gcf,'Position',[300,300,800,400])
hold on
plot([0,100],[12,12],'r--','LineWidth',2)
plot(t45_raw,x45_raw(:,1),'b','LineWidth',2);
plot(t45_raw,x45_raw(:,4),'g','LineWidth',2);
%plot(t23_raw,x23_raw(:,4),'g','LineWidth',2);
% plot(t15_raw,x15_raw(:,1),'r','LineWidth',2);
legend('Reference', 'Rotary Speed','Bit Speed')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 15])
grid on
box on
%%
%{
set(gca,"fontsize",20)

%%
[t45_raw,x45_raw] = ode45(@drillstring_raw,time,zeros(8,1),[]);    
[t23_raw,x23_raw] = ode23(@drillstring_raw,time,zeros(8,1),[]);    
[t15_raw,x15_raw] = ode15s(@drillstring_raw,time,zeros(8,1),[]);    
figure(5)
set(gcf,'Position',[300,300,800,400])
hold on
% plot([0,100],[12,12],'r--','LineWidth',2)
plot(t45_raw,x45_raw(:,1),'b','LineWidth',2);
plot(t23_raw,x23_raw(:,1),'g','LineWidth',2);
plot(t15_raw,x15_raw(:,1),'r','LineWidth',2);
legend('ode45', 'ode23','ode15')
xlabel('Times (s)')
ylabel('Speed (rad/s)')
axis([0 100 -5 15])
grid on
box on

set(gca,"fontsize",20)
%}