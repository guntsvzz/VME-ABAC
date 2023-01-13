%23 sep 2021
%Jacobian SCARA
syms th1 th2 a1 a2 d3
%%L = link([alpha A theta D])
L1 = link([0 a1 th1 0, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([pi a2 th2 0, 0]);
L3 = link([0 0 0 d3, 1]);
FirstlinkRobot = robot({L1});
SecondlinkRobot = robot({L1 L2});
ScaraRobot = robot({L1 L2 L3});
T01 = fkine(FirstlinkRobot, [th1])
T02 = fkine(SecondlinkRobot, [th1 th2])
T03 = fkine(ScaraRobot, [th1 th2 d3])
Jequation = jacob0(ScaraRobot, [th1 th2 d3]); 
%From matlab only ro find Jvalue 
%Don't use Jacob0 function to find Jequation for Exam

O1 = T01(:,4)
O2 = T02(:,4)
O3 = T03(:,4)
Z1 = T01(:,3)
Z2 = T02(:,3)
Z3 = T03(:,3)