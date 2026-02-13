% This is the code for Conference paper "Observer-Based Tracking Control for Suppressing Stick-Slip
% Vibration of Drillstring System"
% Author£ºCJ
% Date£º2018/1/19

% This m file is used to describe the dynamic of drill-string system using
% state-space equation


function dd = drillstring(t,x0,Ks,G)
%% drill-string model

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

% Reference speed
wd = 12;

A = [-(c1+cr)/J1 c1/J1 0 0 -k1/J1 0 0;
    c1/J2 -(c1+c2)/J2 c2/J2 0 k1/J2 -k2/J2 0;
    0 c2/J3 -(c2+c3)/J3 c3/J3 0 k2/J3 -k3/J3;
    0 0 c3/J4 -(c3+cb)/J4 0 0 k3/J4;
    1 -1 0 0 0 0 0 ;
    0 1 -1 0 0 0 0 ;
    0 0 1 -1 0 0 0 ];
B1 = [0;0;0;-1/J4;0;0;0;];
B = [1/J1;0;0;0;0;0;0;];
C = [1 0 0 0 0 0 0];

% Coefficients of internal model
Bc = [1];Ac = [0];

% Augmented state space model combing drill-string model and internal model
AA = [A zeros(7,1);-Bc*C Ac];
BB = [B;0];
Bw = [B1;0];
UU = [zeros(7,1);Bc];
%%  disturbance described by Karnopp model (bit-rock interaction)
% Interested readers may try other friction models 
% t = 150;
if(t>50)
    WoB=110000;
else
    WoB=97347;
end

% See the paper for detailed definition
Rb=0.155575;vf=1;ucb=0.5;usb=0.8;yb=0.9;Dv = 10^-6;Tsb = WoB*Rb*usb;

Teb = c3*(x0(3)-x0(4))+k3*x0(7)-cb*x0(4);
% x4 is bit speed
if(abs(x0(4))<Dv&&abs(Teb)<=Tsb)
    ToB = Teb;
elseif (abs(x0(4))<Dv&&abs(Teb)>Tsb)
    ToB = Tsb*sign(Teb);
else
    ub=ucb+(usb-ucb)*exp(-1*yb/vf*abs(x0(4)));
    ToB = WoB*Rb*ub*sign(x0(4));
end

f = ToB;
%%
% Controller output
u = -Ks*[x0(9:15);x0(8)];

% drill-string
dy = AA*x0(1:8) + BB*u + Bw*f + UU*wd;

% state observer
de = A*x0(9:15) + B*u + G*C*(x0(1:7)-x0(9:15));

dd = [dy; de];

end
