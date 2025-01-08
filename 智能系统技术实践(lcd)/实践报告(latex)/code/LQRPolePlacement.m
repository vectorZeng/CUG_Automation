% This is the code for Conference paper "Observer-Based Tracking Control for Suppressing Stick-Slip
% Vibration of Drillstring System"
% Author£ºCJ
% Date£º2018/1/19

% This m file is used to solve state-feedback gain

function [K, LL,P,E] = LQR_PolePlacement

% Ji(i=1,2,3) is inertia of each disk
% ki(i=1,2,3) is stiffness of each spring connected between 2 disks
% ci(i=1,2,3) is material damping of each spring connected between 2 disks
% cr and cb are local damping existing in top part and bottom part,
% respectively.
% For more specific definition, please see paper "Observer-Based Tracking Control for Suppressing Stick-Slip
% Vibration of Drillstring System"
J1 = 930;J2 = 2782.25;J3 = 750;J4 = 471.9698;
k1 = 698.063;k2 = 1080;k3 = 907.48;
c1 = 139.6126;c2 = 190;c3 = 181.49;
cr = 425;cb = 50;

% state matrix
A = [-(c1+cr)/J1 c1/J1 0 0 -k1/J1 0 0;
    c1/J2 -(c1+c2)/J2 c2/J2 0 k1/J2 -k2/J2 0;
    0 c2/J3 -(c2+c3)/J3 c3/J3 0 k2/J3 -k3/J3;
    0 0 c3/J4 -(c3+cb)/J4 0 0 k3/J4;
    1 -1 0 0 0 0 0 ;
    0 1 -1 0 0 0 0 ;
    0 0 1 -1 0 0 0 ];
% disturbance input matrix
B1 = [0;0;0;-1/J4;0;0;0;];
% control input matrix
B = [1/J1;0;0;0;0;0;0;];
% output matrix
C = [1 0 0 0 0 0 0];

% Q and R
Q = diag([1 1 1 10 1 1 1 1000]);
%R = 0.001;
R = 0.0005;

Bc = [1];Ac = [0];


AA = [A zeros(7,1);-Bc*C Ac];
BB = [B;0;];

% check the controllability
rank(ctrb(AA,BB));

% Using LQR method to determine the best state feeedback gain
[K P E] = lqr(AA,BB,Q,R);

% Using Pole Placement method to determine the best observer gain
LL = ( place(A',C',[-0.93;-2+0.84i;-2-0.84i;-1.5+1i;-1.5-1i;-3+1.95i;-3-1.95i;]))';

end


