%RPP+1DOF
clear all; clc;
syms th1 th2 th4 
syms d1 d2 d3 d4 d5
th4 = 0;
%Given Data
d1 = 2; d3 = 1.5; d5 = 0.5;
%th4 = 0;
%D) when
%th1 = 0; d2 = 3; d4 = 1.5; th4 = 0;
%F) when
th1 = pi/2; d2 = 3; d4 = 1.5; th4 = 0;

%SCARA(RRP) + 1DOF
%%L = link([alpha A theta D])
L1 = link([0 0 th1 d1,0]);
L2 = link([pi/2 0 0 d2,1]);
L3 = link([pi/2 0 0 d3+d4,1]); 
L4 = link([0 0 th4 d5,0]);

RPP_1 = robot({L1});
RPP_2 = robot({L1 L2});
RPP_3 = robot({L1 L2 L3});
RPP_4 = robot({L1 L2 L3 L4});
T01 = fkine(RPP_1, [th1]);
T02 = fkine(RPP_2, [th1 d2]);
T03 = fkine(RPP_3, [th1 d2 d3+d4]);
T04 = fkine(RPP_4, [th1 d2 d3+d4 th4]);
Jequation = jacob0(RPP_4, [th1 d2 d3+d4 th4])

%A)
O1 = T01(:,4)
O2 = T02(:,4)
O3 = T03(:,4)
O4 = T04(:,4)
Z1 = T01(:,3)
Z2 = T02(:,3)
Z3 = T03(:,3)
Z4 = T03(:,3)
