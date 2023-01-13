clc; clear all;
%using ikine function to find theta1-theta4
syms th1 th2 d3 
Xc = 7.5; Yc = 2; Zc = 3.5;
a1 = 3; a2 = 5; d1 = 5; d4 = 1;
%Geometric
d3 = d1-d4-Zc
D = (Xc^2+Yc^2-a1^2-a2^2)/(2*a1*a2)
th2_deg = atan2d(sqrt(1-D^2),D)
th2_rad = deg2rad(th2_deg)
th1_deg = atan2d(Yc,Xc)-atan2d(a2*sin(th2_rad),a1+a2*cos(th2_rad))
th1_rad = deg2rad(th1_deg)
th3 = 0
th4 = 0
%%Using theta1-theta4 fromQ4 then use FK to plot%%
%SCARA(RRP) + 1DOF
L1 = link([0 a1 th1_rad d1,0]);
L2 = link([pi a2 th2_rad 0,0]);
L3 = link([0 0 0 d3,1]);
L4 = link([0 0 th4 d4,0]);
RRPwrist = robot({L1 L2 L3 L4});
T04 = fkine(RRPwrist, [th1_rad th2_rad d3 0])
Pend = T04*[0;0;0;1]
%plot(RRPwrist,[th1_rad th2_rad d3 0])