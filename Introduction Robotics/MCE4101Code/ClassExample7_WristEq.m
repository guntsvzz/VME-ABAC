%%Wrist Equation
%%17 Aug 2021
syms th4 th5 th6  
syms d6
%%L = link([alpha A theta D])
%%0 is revolute (and default), 1 is prismatic
A4 = link([-pi/2 0 th4 0, 0]);
A5 = link([pi/2 0 th5 0, 0]);
A6 = link([0 0  th6 d6, 0]);
Wrist3DOF = robot({A4 A5 A6});
WristEquation = fkine(Wrist3DOF ,[th4 th5 th6])
%%Pend = WristEquation *[0;0;0;1]