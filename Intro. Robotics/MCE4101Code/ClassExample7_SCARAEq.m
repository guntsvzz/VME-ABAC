%%SCARA
%%17 Aug 2021
% syms a1 a2 d3 
% syms th1 th2 th4 
% syms d4
a1 = 1, a2 = 2, d3 = 1, th1 = 0,th2 = 0,th4 = 0,d4 = 0.5
%%L = link([alpha A theta D])
%%0 is revolute (and default), 1 is prismatic
A1 = link([0 a1 th1 0, 0]);
A2 = link([pi a2 th2 0, 0]);
A3 = link([0 0  0 d3, 1]);
A4 = link([0 0 th4 d4, 0]);

% RPPRobot = robot({A1 A2 A3});
% RPPEquation = fkine(RPPRobot ,[th1 a2 d3 ]);
% Wrist1DOF = robot({A4});
% WristEquation = fkine(Wrist1DOF ,[th4]);
% FULLEquation = RPPEquation*WristEquation

RPP1DOFWristEquation = robot({A1 A2 A3 A4});
drivebot(RPP1DOFWristEquation)


