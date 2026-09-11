%% Simulation of a 2D planar Arm Robot
% Control : Feedback Linearization
% By : Do with Me (Amin)
% Date : 2022
%%
clear all;
clc;
%% Robot Configurtion
Robot_schematic;
%% Run Simulation
SimOut = sim('Control_Robot'); %Run Simulink 
% Simulation Loop
for S = 1 : 1 : size(SimOut,1)      
    Robot.X1 = X1_out.signals.values(S);
    Robot.Y1 = Y1_out.signals.values(S);
    Robot.X2 = X2_out.signals.values(S);
    Robot.Y2 = Y2_out.signals.values(S);

    Plot_Robot_movement  
    
    plot(X2_out.signals.values(S),Y2_out.signals.values(S),'r.');
    plot(X_input.signals.values,Y_input.signals.values,'--b')
    pause(.005)   
end
%% -----------Plot Data---------------
% figure(2)
% subplot(2,2,1);
% plot(t_input1.time,rad2deg(t_out1.signals.values),'k',t_input1.time,rad2deg(t_input1.signals.values),'--b','linewidth',1.2)
% title(' \theta 1 Input & Output');
% xlabel('Time(s)');
% ylabel(' \theta (Deg)');
% axis([0 10 -10 160]);
% legend('\theta 1 Output','\theta 1 Input');
% grid on
% 
% subplot(2,2,2);
% plot(t_input2.time,rad2deg(t_out2.signals.values),'k',t_input2.time,rad2deg(t_input2.signals.values),'--b','linewidth',1.2)
% title(' \theta 2 Input & Output');
% xlabel('Time(s)');
% ylabel(' \theta (Deg)');
% axis([0 10 -160 10]);
% legend('\theta 2 Output','\theta 2 Input');
% grid on
% 
% subplot(2,2,3);
% plot(X2_out.time,X2_out.signals.values,'k',X2_out.time,X_input.signals.values,'--b','linewidth',1.2)
% title(' X(end point) Input & Output');
% xlabel('Time(s)');
% ylabel(' X (m)');
% axis([0 10 -1 4]);
% legend('X output','X input');
% grid on
% 
% subplot(2,2,4);
% plot(Y2_out.time,Y2_out.signals.values,'k',X2_out.time,Y_input.signals.values,'--b','linewidth',1.2)
% title(' Y(end point) Input & Output');
% xlabel('Time(s)');
% ylabel(' Y (m)');
% axis([0 10 -2 4]);
% legend('Y output','Y input');
% grid on