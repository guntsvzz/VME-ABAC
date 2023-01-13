%%RPP + Wrist Equation
%%17 Aug 2021
% syms th1 th4 th5 th6  
% syms d2 d3 
th1 = 0, d2 = 1, d3 = 2, th4 = 0, th5 = 0, th6 = 0
d6 = 0.5
%%L = link([alpha A theta D])
%%0 is revolute (and default), 1 is prismatic
%RPP
A1 = link([0 0 th1 0, 0]);
A2 = link([-pi/2 0 0 d2, 0]);
A3 = link([0 0  0 d3, 0]);
%Wrist
A4 = link([-pi/2 0 th4 0, 0]);
A5 = link([pi/2 0 th5 0, 0]);
A6 = link([0 0  th6 d6, 0]);

%RPPRobot = robot({A1 A2 A3});
%RPPEquation = fkine(RPPRobot ,[th1 d2 d3])
%Wrist3DOF = robot({A4 A5 A6});
%WristEquation = fkine(Wrist3DOF ,[th4 th5 th6])
%FULLEquation = RPPEquation*WristEquation

FULLRobot = robot({A1 A2 A3 A4 A5 A6});
FULLEquation = fkine(FULLRobot ,[th1 d2 d3 th4 th5 th6]);
drivebot(FULLRobot,[0 1 2 0 0 0])
