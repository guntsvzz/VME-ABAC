%Find possible posture solutions for end point location P(1.5,2.75,5)
clc; clear all;
Px = 1.5; Py = 2.75; Pz = 5;
L1 = 2.5; L2 =0; L6 = 0.15; 
T03 = [0.866 0 0.5 1.5; 0.5 0 0.866 2.5981; 0 1 0 5; 0 0 0 1];
d2 = 5-L1
th1 = atan2d(2.5981,Px)
d3 = (Px)/cosd(th1)-L2
d3L2 = d3+L2;
th1_rad = deg2rad(th1);
%RPP
%%L = link([alpha A theta D])
A1 = link([0 0 th1_rad L1,0]);
A2 = link([pi/2 0 pi/2 d2,1]);
A3 = link([0 0 0 d3L2,1]); %where dL3 = L2+d3
RPPRobot = robot ({A1 A2 A3});
T03 = fkine(RPPRobot, [th1_rad d2 d3L2])
T06 = [-1 -0 0 1.5; 0 -0 1 2.75; 0 1 0 5; 0 0 0 1]
U = transpose(T03)*T06
%Positive
th4_p = atan2d(U(2,3),U(1,3))
th5_p = atan2d(sqrt(1-(U(3,3))^2),U(3,3))
th6_p = atan2d(U(3,2),-U(3,1))
th4rad = deg2rad(th4_p);
th5rad = deg2rad(th5_p);
th6rad = deg2rad(th6_p);
%Negative
th4_n = atan2d(-U(2,3),-U(1,3))
th5_n = atan2d(-sqrt(1-(U(3,3))^2),U(3,3))
th6_n = atan2d(-U(3,2),U(3,1))
th4radn = deg2rad(th4_n);
th5radn = deg2rad(th5_n);
th6radn = deg2rad(th6_n);

