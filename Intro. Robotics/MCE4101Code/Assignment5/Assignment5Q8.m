clear all; clc;
%Find possible posture solutions for end point location P(1.5,2.75,5) using ikine
Px = 1.5; Py = 2.75; Pz = 5;
L1= 2.5; L2 =0; L6 = 0.15; 
th1 = 0; th2 = 0; th3 = 0;
th4 = 0; th5 = 0; th6 = 0;
d2 = 5-L1
th1 = atan2d(2.5981,Px)
d3 = (Px)/cosd(th1)-L2
%d6 = 5; d3 = 5; d2 = 1; 
d6 = 0 ; d3L2 = L2+d3; 
%RPP
A1 = link([0 0 th1 L1, 0]);
A2 = link([pi/2 0 pi/2 d2, 1]);
A3 = link([0 0 0 d3L2, 1]);
%3DOF
A4 = link([-pi/2 0 th4 0, 0]);
A5 = link([pi/2 0 th5 0, 0]);
A6 = link([0 0 th6 d6, 0]);
RPP3DOFRobot = robot({A1 A2 A3 A4 A5 A6});
%ikine
position = transl(Px, Py, Pz);
Q = [0.1 0.5 0 0 0 0];
M = [1 1 1 1 1 1];
Data_rad = ikine(RPP3DOFRobot, position, Q, M)
Data_deg = rad2deg(Data_rad)
plot(RPP3DOFRobot,Data_rad)