%23 sep 2021
%Jacobian 2links
syms th1 th2 a1 a2
%%L = link([alpha A theta D])
L1 = link([0 a1 th1 0, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2 0, 0]);
FirstlinkRobot = robot({L1});
TwolinkRobot = robot({L1 L2});
T01 = fkine(FirstlinkRobot, [th1])
T02 = fkine(TwolinkRobot, [th1 th2])
O1 = T01(:,4)
O2 = T02(:,4)
Z1 = T01(:,3)
Z2 = T02(:,3)