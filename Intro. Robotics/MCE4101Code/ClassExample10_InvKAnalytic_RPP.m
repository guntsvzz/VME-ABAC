%%Chapter 6 Inv Analystic RPP
%%ClassExample9_RPP robot with Inv K by analytic
%%30 Aug 2021
%syms th1 d2 dL3
%syms L1 
L1 = 0.5; th1 = 0; d2 = 1; dL3=1;
%%L = link([alpha A theta D])
A1 = link([0 0 th1 L1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([pi/2 0 pi/2 d2, 1]);
A3 = link([0 0 0 dL3, 1]); %where dL3 = L2+d3
RPPRobot = robot({A1 A2 A3});
%RPPEquation = fkine(RPPRobot,[th1 d2 dL3])

%%Check
RPPEquation = fkine(RPPRobot,[0 2 1.5+2])
RPP_Endpoint = RPPEquation*[0;0;0;1]

%atan2d(0,3.5)

