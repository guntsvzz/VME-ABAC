%Chapter 9 
%ClassExample 13 2link manipulator
clear all; clc;
%14 sep 2021
%DH Table
th1 = 0; th2 = 0;
a1 =1; a2= 2;
q0 = [3;0;0];
qf = [2;2;0];

%Inverse Kinematics
%%L = link([alpha A theta D])
L1 = link([0 a1 th1 0, 0]); %%0 is revolute (and default), 1 is prismatic  
L2 = link([0 a2 th2 0, 0]);
TwolinksRobot = robot({L1 L2});
%ikine
position_initial = transl(q0);
position_final = transl(qf);
IC_initial = [0 0];         %%will be given in the exam
IC_final = [pi/10 -pi/10];  %%will be given in the exam
M = [1 1 0 0 0 0]; %2 DOF
%Q = ikine(ROBOT, T, Q, M)
Data_Pinitial = ikine(TwolinksRobot, position_initial, IC_initial, M);
Data_Pinitial_degree = rad2deg(Data_Pinitial)
Data_Pfinal = ikine(TwolinksRobot, position_final, IC_final, M);
Data_Pfinal_degree = rad2deg(Data_Pfinal)

%%To check answer
T02_initial = fkine(TwolinksRobot, Data_Pinitial);
P0 = T02_initial*[0;0;0;1]
T02_final = fkine(TwolinksRobot, Data_Pfinal);
P0 = T02_final *[0;0;0;1]

%Path Equation
%cubic or quintic may said in exam
%Joint 1 Cubic
q1_0 = Data_Pinitial_degree(1,1); 
q1_f = Data_Pfinal_degree(1,1); 
v1_0 = 0; v1_f = 0;
t0 = 0; tf = 2;
Y1 = [q1_0;v1_0;q1_f;v1_f];
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A1 = [a1_0;a1_1;a1_2;a1_3];
A1 = inv(B1)*Y1

%Joint 2 Cubic
q2_0 = Data_Pinitial_degree(1,2); 
q2_f = Data_Pfinal_degree(1,2); 
v2_0 = 0;
v2_f = 0;
Y2 = [q2_0;v2_0;q2_f;v2_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A2 = [a2_0;a2_1;a2_2;a2_3];
A2 = inv(B2)*Y2

%%Joint 1 trajectory equations
for i = 1:201 %10 datas
t(i) = i/100 
q1(i) = (54.7*t(i)^2) - (18.2*t(i)^3);
v1(i) = 109.4*t(i) - 54.6*t(i)^2
at1(i) = 109.4 - 109.2*t(i)
end

figure(1);
subplot(3,1,1)
plot(t,q1)
title('Trajectory equation for Joint1')
ylabel('Th1')
axis([0 2 0 80])
grid on;
subplot(3,1,2)
plot(t,v1)
ylabel('v1')
axis([0 2 0 60])
grid on;
subplot(3,1,3)
plot(t,at1)
ylabel('a1')
axis([0 2 -200 200])
xlabel('Time')
grid on;

%%Joint 2 trajectory equations
for ii = 1:201 %10 datas
t(ii) = ii/100 
q2(ii) = (-31.06*t(ii)^2) + (10.35*t(ii)^3);
v2(ii) = -62.12*t(ii) + 31.05*t(ii)^2
at2(ii) = -62.12 + 62.1*t(ii)
end

figure(2);
subplot(3,1,1)
plot(t,q2)
title('Trajectory equation for Joint2')
ylabel('Th2')
axis([0 2 -50 0])
grid on;
subplot(3,1,2)
plot(t,v2)
ylabel('v2')
axis([0 2 -50 0])
grid on;
subplot(3,1,3)
plot(t,at2)
ylabel('a2')
axis([0 2 -100 100])
grid on;
xlabel('Time')



