%RPP+1DOF
clear all; clc;
syms th1 th2 th5 
syms L1 L2 L3 L4 L5
%Given Data
L1 = 100; L2 = 40; L3 = 15; L5 = 5;
%th5 = 0;
%D) when %th1 = pi/2; th2 = 0; L4 = 5; th5 = 0;
%F) when %th1 = 0; th2 = pi/2; L4 = 10; th5 = 0;
%SCARA(RRP) + 1DOF
%%L = link([alpha A theta D])
A1 = link([0 L2 th1 L1,0]);
A2 = link([-pi/2 L3 th2 0,0]);
A3 = link([pi 0 0 L4+L5,1]); 
A4 = link([0 pi th5 0,0]);
RPP_1 = robot({A1});
RPP_2 = robot({A1 A2});
RPP_3 = robot({A1 A2 A3});
RPP_4 = robot({A1 A2 A3 A4});
T01 = fkine(RPP_1, [th1]);
T02 = fkine(RPP_2, [th1 th2]);
T03 = fkine(RPP_3, [th1 th2 L4+L5]);
T04 = fkine(RPP_4, [th1 th2 L4+L5 th5]);
Jequation = jacob0(RPP_4, [th1 th2 L4+L5 th5])
%A)
O1 = T01(:,4)
O2 = T02(:,4)
O3 = T03(:,4)
O4 = T04(:,4)
Z1 = T01(:,3)
Z2 = T02(:,3)
Z3 = T03(:,3)
Z4 = T03(:,3)
