clear all; clc;
%using ikine function to find theta1-theta4
a1 = 3; a2 = 5; d1 = 5; d4 = 1;
Xc = 7.5; Yc = 2; Zc = 3.5;
th1 = 0; th2 = 0; th4 = 0; d3 = 0;
%SCARA(RRP) + 1DOF
%%L = link([alpha A theta D])
L1 = link([0 a1 th1 d1, 0]); %0 is revolute (and default), 1 is prismatic
L2 = link([pi a2 th2 0, 0]);
L3 = link([0 0 d3 0, 1]);
L4 = link([0 0 th4 d4, 0]);
SCARA1DOFRobot = robot({L1 L2 L3 L4});
%%4 DOF Wrist %ikine
Position = transl(Xc, Yc, Zc)
IG = [pi/10 0 0 pi/10];
M = [1 1 1 1 0 0]; %4 DOF
Data_rad = ikine(SCARA1DOFRobot, Position, IG, M)
Data_deg = rad2deg(Data_rad)

%Check answer with FK
SCARA1DOFRobot.name = 'SCARA';
T03 = fkine(SCARA1DOFRobot, [Data_rad])
Pend = T03*[0;0;0;1]
plot(SCARA1DOFRobot, Data_rad)

