%Chapter 9 
%ClassExample 14 Jtraj
clear all;
clc;
%21 sep 2021
%DH Table
th1 = 0; th2 = 0;
a1 =1; a2= 2;
q0 = [3;0;0];
qf = [2;2;0];
%Inverse Kinematics
%%0 is revolute (and default), 1 is prismatic
%%L = link([alpha A theta D])
L1 = link([0 a1 th1 0, 0]); 
L2 = link([0 a2 th2 0, 0]);
TwolinksRobot = robot({L1 L2});

position_initial = transl(q0);
position_final = transl(qf);
IC_initial = [0 0];
IC_final = [pi/10 -pi/10]; %%will be given in the exam
M = [1 1 0 0 0 0]; %2 DOF
%Q = ikine(ROBOT, T, Q, M)
Data_Pinitial = ikine(TwolinksRobot, position_initial, IC_initial, M);
Data_Pinitial_degree = rad2deg(Data_Pinitial)
Data_Pfinal = ikine(TwolinksRobot, position_final, IC_final, M);
Data_Pfinal_degree = rad2deg(Data_Pfinal)

t = [0:1:11] 
Q = jtraj(Data_Pinitial,Data_Pfinal,t)
for i = 1:10
    Q1(i) = Q(i,1);
    Q2(i) = Q(i,2);
    figure(1)
    plot(TwolinksRobot,[Q1(i),Q2(i)])
    pause(0.1)
end