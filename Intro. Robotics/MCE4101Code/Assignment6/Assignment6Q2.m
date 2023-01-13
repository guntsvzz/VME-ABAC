%RPP
clear all; clc;
%A) DH and T0end
syms th1_1 th1_2 d2_1 d2_2 d3_1 d3_2
th1_1 = 0; th1_2 = 0; d2_1 = 0; d2_2 = 0; d3_1 = 0; d3_2= 0; 
d1 = 0.5;
%A) Analytic Method
%POSITION1 
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_1 d1,0]);
L2 = link([-pi/2 0 0 d2_1,1]);
L3 = link([0 0 0 d3_1,1]); 
iVMErobot_1 = robot({L1 L2 L3});
%POSITION2 
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 0 th1_2 d1,0]);
L2 = link([-pi/2 0 0 d2_2,1]);
L3 = link([0 0 0 d3_2,1]); 
iVMErobot_2 = robot({L1 L2 L3});
%ikine POSITION1
P0 = [0;0.2;0.5]; %Xc;Yc;Zc
position1 = transl(P0);
IG1 = [0 0 0]; %Data given
M = [1 1 1 0 0 0]; %3DOF
Data1_rad = ikine(iVMErobot_1, position1, IG1, M);
Data1_deg = rad2deg(Data1_rad);
%ikine POSITION2
P1 = [1;1.2;0.5]; %Xc;Yc;Zc
position2 = transl(P1);
IG2 = [pi 0 0]; %Data given
M = [1 1 1 0 0 0]; %3DOF
Data2_rad = ikine(iVMErobot_2, position2, IG2, M);
Data2_deg = rad2deg(Data2_rad);

%B) Fina trajextory data using jtraj
%POSITION
t = [0:0.1:2]; 
Q_02 = jtraj(Data1_rad,Data2_rad,t)
for i = 1:21
    Q_02_1(i) = Q_02(i,1);
    Q_02_2(i) = Q_02(i,2);
    Q_02_3(i) = Q_02(i,3);
    figure(1);
    plot(iVMErobot_1,[Q_02_1(i),Q_02_2(i),Q_02_3(i)])
    pause(0.1);
end
