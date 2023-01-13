%RRP + 3 DOF Wrist Mechanism 
syms th1 th2 th4 th5 th6
syms d1 d2 d3 d4 d5 d6
syms a1 a2 
%%RRP
%%L = link([alpha A theta D])
A1 = link([0 a1 th1 0, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([pi a2 th2 0, 0]);
A3 = link([0 0 0 d3, 1]);
%%3DOF Wrist Mechanism 
A4 = link([-pi/2 0 th4 0, 0]);
A5 = link([pi/2 0 th5 0, 0]);
A6 = link([0 0 th6 d6, 0]);

RRP3DOF = robot({A1 A2 A3 A4 A5 A6});
RRP3DOFRobotequation = fkine(RRP3DOF ,[th1 th2 d3 th4 th5 th6])
Pend = RRP3DOFRobotequation*[0;0;0;1]

%plot(RRP3DOF, [0 10 5 0 0 0])
%pause(1)
%plot(RRP3DOF, [pi/2 10 5 0 0 0])
%pause(1)
%plot(RRP3DOF, [pi/2 10 5 pi/2 0 0])
%pause(1)

