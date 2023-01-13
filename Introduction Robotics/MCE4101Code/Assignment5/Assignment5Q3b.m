%%FromQ2%%
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

%%Using theta1-theta6 fromQ2 then use FK to plot%%
%th1=1.0472; th2=-62.8318; th3=99.4837; 
%th4=-69.6386; th5=-1.5708; th6=31.9395;
L1 = link([pi/2 0 Data_rad(1,1) d1,0]);
L2 = link([0 a2 Data_rad(1,2) 0,0]);
L3 = link([0 a3 Data_rad(1,3) 0,0]);
L4 = link([-pi/2 0 Data_rad(1,4) 0,0]);
L5 = link([pi/2 0 Data_rad(1,5) 0,0]);
L6 = link([0 0 Data_rad(1,6) d6,0]);
RRRandWrist = robot({L1 L2 L3 L4 L5 L6});
T0end = fkine(RRRandWrist, Data_rad)
Pend = T0end*[0;0;0;1]
plot(RRRandWrist,Data_rad)