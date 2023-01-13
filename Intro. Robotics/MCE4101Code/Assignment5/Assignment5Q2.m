%ikine function
clear all; clc;
%Geometric
Xc = 2.75; Yc = 4.763; Zc = -2.33;
d1 = 2; a2 = 3; a3 = 5; d6 = 0;
th1 = 0; th2 = 0; th3 = 0;
th4 = 0; th5 = 0; th6 = 0;
%RRR
%%L = link([alpha A theta D])
L1 = link([pi/2 0 th1 d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2 0, 0]);
L3 = link([0 a3 th3 0, 0]);
%3DOF Wrist
L4 = link([-pi/2 0 th4 0, 0]);
L5 = link([pi/2 0 th5 0, 0]);
L6 = link([0 0 th6 d6, 0]);
RRR3DOF = robot({L1 L2 L3 L4 L5 L6});
%ikine Finding theta1-theta6
Position = transl(Xc, Yc, Zc);
IG = [pi/10 -pi/150 pi/150 pi/100 -pi/100 pi/100]; %6DOF
M = [1 1 1 1 1 1]; %6DOF
Data_rad = ikine(RRR3DOF, Position, IG, M)
Data_deg = rad2deg(Data_rad)