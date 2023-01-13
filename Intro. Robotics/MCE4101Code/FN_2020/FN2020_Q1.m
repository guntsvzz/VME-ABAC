%RPP+1DOF
clear all; clc;
%A) DH and T0end
syms th1_1 th1_2 th4 th_2 d2_1 d2_2 d4_1 d4_2 
syms d1 d3 d5
%d1 = 2; d3 = 1.5; d5 = 0.5;
%BC) T0end
%th1_1 = 0; d2_1 = 3; d4_1 = 1.5; th4_1 = 0;

%D) Analytic Method
%POSITION1
Pend1 = [2.6; -1.5; 4.5]; th4 = 0;
%d2_1 = Pend1(3,1)-d1+d5
%th1_1 = atan2(Pend1(1,1),-Pend1(2,1))
%th1_1_deg = atan2d(Pend1(1,1),-Pend1(2,1))
%d4_1 = Pend1(1,1)/sin(th1_1)-d1+d5

%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_1 d1,0]);
L2 = link([pi/2 0 0 d2_1,1]);
L3 = link([pi/2 0 0 d3+d4_1,1]); 
L4 = link([0 0 th4 d5,0]);

iVMErobot_1 = robot({L1 L2 L3});
T03_1 = fkine(iVMErobot_1, [th1_1 d2_1 d3+d4_1]);
iVMErobot1DOF_1 = robot({L1 L2 L3 L4});
T04_1 = fkine(iVMErobot1DOF_1, [th1_1 d2_1 d3+d4_1 th4])
P0end_1 = T04_1*[0;0;0;1] 

%F) Analytic Method
%POSITION2
Pend2 = [-1.5; -2.6; 3.5]; th4 = 0;
d2_2 = Pend2(3,1)-d1+d5
th1_2 = atan2(Pend2(1,1),-Pend2(2,1))
th1_2_deg = atan2d(Pend2(1,1),-Pend2(2,1))
d4_2 = Pend2(1,1)/sin(th1_2)-d1+d5 
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_2 d1,0]);
L2 = link([pi/2 0 0 d2_2,1]);
L3 = link([pi/2 0 0 d3+d4_2,1]); %where d3d4 = d4+d3
L4 = link([0 0 th4 d5,0]);

iVMErobot_2 = robot({L1 L2 L3});
T03_2 = fkine(iVMErobot_2, [th1_2 d2_2 d3+d4_2]);
iVMErobot1DOF_2 = robot({L1 L2 L3 L4});
T04_2 = fkine(iVMErobot1DOF_2, [th1_2 d2_2 d3+d4_2 th4])
P0end_2 = T04_2*[0;0;0;1] 


%E) ikine 
position1 = transl(Pend1);
IG1 = [pi/10 0.5 1 0]; %Data given
M = [1 1 1 1 0 0]; %4DOF
Data1_rad = ikine(iVMErobot1DOF_1, position1, IG1, M)
Data1_deg = rad2deg(Data1_rad)
T0end1 = fkine(iVMErobot1DOF_1, Data1_rad)

%G) ikine 
position2 = transl(Pend2);
IG2 = [pi/10 0.5 1 0]; %Data given
M = [1 1 1 1 0 0]; %4DOF
Data2_rad = ikine(iVMErobot1DOF_2, position2, IG2, M)
Data2_deg = rad2deg(Data2_rad)
T0end2 = fkine(iVMErobot1DOF_2, Data2_rad)

%H) Polynomial trajectories, velocities amd accelerations equation
%Cubic Polynomial
t0 = 0; tf = 4;
%joint 1
q1_0 = Data1_deg(1,1); 
q1_f = Data2_deg(1,1);
v1_0 = 0; v1_f = 0;
Y1 = [q1_0;v1_0;q1_f;v1_f];
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A1 = [a1_0; a1_1; a1_2; a1_3];
A1 = inv(B1)*Y1
 
%joint 2
q2_0 = Data1_deg(1,2); 
q2_f = Data2_deg(1,2);
v2_0 = 0; v2_f = 0;
Y2 = [q2_0;v2_0;q2_f;v2_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A2 = [a2_0; a2_1; a2_2; a2_3];
A2 = inv(B2)*Y2

%joint 3
q3_0 = Data1_deg(1,3); 
q3_f = Data2_deg(1,3);
v3_0 = 0; v3_f = 0;
Y3 = [q3_0;v3_0;q3_f;v3_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A3 = [a3_0; a3_1; a3_2; a3_3];
A3 = inv(B2)*Y3

%joint 4
q4_0 = Data1_deg(1,4); 
q4_f = Data2_deg(1,4);
v4_0 = 0; v4_f = 0;
Y4 = [q4_0;v4_0;q4_f;v4_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A4 = [a2_0; a2_1; a2_2; a2_3];
A4 = inv(B2)*Y4
