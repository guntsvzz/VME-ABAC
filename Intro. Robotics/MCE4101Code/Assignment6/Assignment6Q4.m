clear all; clc;
syms th1 th2 a1 a2 d1 d3
%th1 = 0; th2 = 0;
%B When 
%a1 = 3; a2 =5; d1 =5;  d3 = 1;
%SCARA(RRP) + 1DOF
L1 = link([0 a1 th1 d1,0]);
L2 = link([pi a2 th2 0,0]);
L3 = link([0 0 0 d3,1]);
RRP_1 = robot({L1});
RRP_2 = robot({L1 L2});
RRP_3 = robot({L1 L2 L3});
T01 = fkine(RRP_1, [th1])
T02 = fkine(RRP_2, [th1 th2])
T03 = fkine(RRP_3, [th1 th2 d3])
O1 = T01(:,4)
O2 = T02(:,4)
O3 = T03(:,4)
Z1 = T01(:,3)
Z2 = T02(:,3)
Z3 = T03(:,3)
%Jvalue = jacob0(RRP_3,[th1 th2 d3])
%B When 
Jvalue = jacob0(RRP_3,[degtorad(20) degtorad(-10) 1])