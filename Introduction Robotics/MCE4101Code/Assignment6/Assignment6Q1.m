%RPP
clear all; clc;
%A) DH and T0end
syms th1_1 th1_2 d2_1 d2_2 d3_1 d3_2
d1 = 0.5;
%A) Analytic Method
%POSITION1
Pend1 = [0; 0.2; 0.5]; 
Xc_1 = 0; Yc_1 =0.2; Zc_1 = 0.5;
d2_1 = Zc_1-d1
th1_1 = atan2(-Xc_1,Yc_1)
th1_1_deg = atan2d(-Xc_1,Yc_1)
d3_1 = Yc_1/cosd(th1_1)
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_1 d1,0]);
L2 = link([-pi/2 0 0 d2_1,1]);
L3 = link([0 0 0 d3_1,1]); 
iVMErobot_1 = robot({L1 L2 L3});
T03_1 = fkine(iVMErobot_1, [th1_1 d2_1 d3_1])
P0end_1 = T03_1*[0;0;0;1] 

%POSITION2
Pend2 = [1; 1.2; 0.5]; 
Xc_2 = 1; Yc_2 =1.2; Zc_2 = 0.5;
d2_2 = Zc_2-d1
th1_2 = atan2(-Xc_2,Yc_2)
th1_2_deg = atan2d(-Xc_2,Yc_2)
d3_2 = Yc_2/cosd(th1_2)
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_2 d1,0]);
L2 = link([-pi/2 0 0 d2_2,1]);
L3 = link([0 0 0 d3_2,1]); 
iVMErobot_2 = robot({L1 L2 L3});
T03_2 = fkine(iVMErobot_2, [th1_2 d2_2 d3_2])
P0end_2 = T03_2*[0;0;0;1] 

%B) Polynomial trajectories, velocities amd accelerations equation
%Cubic Polynomial
t0 = 0; tf = 2;
%joint 1
q1_0 = th1_1; 
q1_f = th1_2;
v1_0 = 0; v1_f = 0;
Y1 = [q1_0;v1_0;q1_f;v1_f];
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A1 = [a1_0; a1_1; a1_2; a1_3];
A1 = inv(B1)*Y1
 
%joint 2
q2_0 = d2_1;
q2_f = d2_2;
v2_0 = 0; v2_f = 0;
Y2 = [q2_0;v2_0;q2_f;v2_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A2 = [a2_0; a2_1; a2_2; a2_3];
A2 = inv(B2)*Y2

%joint 3
q3_0 = d3_1;
q3_f = d3_2;
v3_0 = 0; v3_f = 0;
Y3 = [q3_0;v3_0;q3_f;v3_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A3 = [a3_0; a3_1; a3_2; a3_3];
A3 = inv(B2)*Y3