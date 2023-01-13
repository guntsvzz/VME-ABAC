%RPP+1DOF
clear all; clc;
%A) DH and T0end
syms th1_1 th1_2 th2_1 th2_2 th5_1 th5_2
syms L1 L2 L3 L4_1 L4_2 L5
%Given Data
L1 = 100; L2 = 40; L3 = 15; L5 = 5;
%th1_1 = 0; th2_1 = 0; L4_1 = 40; th5_1 = 0; 
%th1_2 = 0; th2_2 = 0; L4_2 = 40; th5_2 = 0; 

%C) th1_1 = 0; th2_1  = 0; L4_1  = 40; th5_1  = 0;
%D) th1_1 = pi/2; th2_1  = 0; L4_1  = 40; th5_1  = 0;

%G) Analytic Method
%POSITION1
Pend1 = [27.5; -47.6; 55]; th5 = 0;
%d2_1 = Pend1(3,1)-d1+d5
%th1_1 = atan2(Pend1(1,1),-Pend1(2,1))
%th1_1_deg = atan2d(Pend1(1,1),-Pend1(2,1))
%d4_1 = Pend1(1,1)/sin(th1_1)-d1+d5

%DH Table1
%%L = link([alpha A theta D])
A1 = link([0 0 th1_1 L1,0]);
A2 = link([-pi/2 L2+L3 th2_1 0,0]);
A3 = link([pi 0 0 L4_1+L5,1]); 
A4 = link([0 pi th5_1 0,0]);
iVMErobot_1 = robot({A1 A2 A3});
T03_1 = fkine(iVMErobot_1, [th1_1 th2_1 L4_1+L5]);
iVMErobot1DOF_1 = robot({A1 A2 A3 A4});
T04_1 = fkine(iVMErobot1DOF_1, [th1_1 th2_1 L4_1+L5 th5_1])
P0end_1 = T04_1*[0;0;0;1] 

%H) ikine 
Pend2 = [42.1; 33; 55]; 
position2 = transl(Pend2);
IG2 = [pi/10 pi/10 10 0]; %Data given
M = [1 1 1 1 0 0]; %4DOF
Data2_rad = ikine(iVMErobot1DOF_2, position2, IG2, M)
Data2_deg = rad2deg(Data2_rad)
T0end2 = fkine(iVMErobot1DOF_2, Data2_rad)

%DH Table2
%%L = link([alpha A theta D])
A1 = link([0 0 th1_2 L1,0]);
A2 = link([-pi/2 L2+L3 th2_2 0,0]);
A3 = link([pi 0 0 L4_2+L5,1]); 
A4 = link([pi 0 th5_2 0,0]);
iVMErobot_2 = robot({A1 A2 A3});
T03_2 = fkine(iVMErobot_2, [th1_2 th2_2 L4_2+L5]);
iVMErobot1DOF_2 = robot({A1 A2 A3 A4});
T04_2 = fkine(iVMErobot1DOF_2, [th1_2 th2_2 L4_2+L5 th5_2])
P0end_2 = T04_2*[0;0;0;1] 

%E) ikine 
Pend1 = [27.5; -47.6; 55];
position1 = transl(Pend1);
IG1 = [-pi/10 -pi/10 10 0]; %Data given
M = [1 1 1 1 0 0]; %4DOF
Data1_rad = ikine(iVMErobot1DOF_1, position1, IG1, M)
Data1_deg = rad2deg(Data1_rad)
T0end1 = fkine(iVMErobot1DOF_1, Data1_rad)

%i) Polynomial trajectories, velocities amd accelerations equation
%Cubic Polynomial
t0 = 0; tf = 3;
%joint 1
q1_0 = th1_1
q1_f = th1_2
v1_0 = 0; v1_f = 0;
Y1 = [q1_0;v1_0;q1_f;v1_f];
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A1 = inv(B1)*Y1 %A1 = [a1_0; a1_1; a1_2; a1_3];
%joint 2
q2_0 = th2_1 
q2_f = th2_2
v2_0 = 0; v2_f = 0;
Y2 = [q2_0;v2_0;q2_f;v2_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A2 = inv(B2)*Y2 %A2 = [a2_0; a2_1; a2_2; a2_3];
%joint 3
q3_0 = L4_1+L5
q3_f = L4_2+L5
v3_0 = 0; v3_f = 0;
Y3 = [q3_0;v3_0;q3_f;v3_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A3 = inv(B2)*Y3 %A3 = [a3_0; a3_1; a3_2; a3_3];
%joint 4
q4_0 = th5_1 
q4_f = th5_2
v4_0 = 0; v4_f = 0;
Y4 = [q4_0;v4_0;q4_f;v4_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A4 = inv(B2)*Y4 %A4 = [a2_0; a2_1; a2_2; a2_3];

