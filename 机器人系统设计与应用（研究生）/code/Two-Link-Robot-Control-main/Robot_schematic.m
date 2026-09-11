%% Robot 2D planar
figure(1)
axis equal
axis([-1 2.5 -1 2.5]);
grid on
hold on
xlabel('X (m)')
ylabel('Y (m)')
title('Robot Movement');

% Initial Position Of Joints
Joint_1=[0 0];
Joint_2=[1 0];
Joint_3=[2 0];

Robot_arm_1=patch('XData',[Joint_1(1) Joint_2(1)],'YData',[Joint_1(2) Joint_2(2)],'LineWidth',4);
Robot_arm_2=patch('XData',[Joint_2(1) Joint_3(1)],'YData',[Joint_2(2) Joint_3(2)],'LineWidth',4);
Robot_path =patch('XData',[Joint_3(1)-0.01 Joint_3(1)],'YData',[Joint_3(2)-0.01 Joint_3(2)],'LineWidth',.5);

