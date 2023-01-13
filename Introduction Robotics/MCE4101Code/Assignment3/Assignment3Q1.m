%RPP + 1 DOF Wrist Mechanism 
syms th1 th4 
syms d1 d2 d3 d4
%%RPP
%%L = link([alpha A theta D])
A1 = link([0 0 th1 d1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([-pi/2 0 0 d2, 1]);
A3 = link([0 0 0 d3, 1]);
%%1DOF Wrist Mechanism 
A4 = link([0 0 th4 d4, 0]);

RPP1DOF = robot({A1 A2 A3 A4});
RPP1DOFRobotequation = fkine(RPP1DOF,[th1 d2 d3 d4])
Pend = RPP1DOFRobotequation*[0;0;0;1]

%plot(RPP1DOF, [0 10 5 0])
%pause(1)
%plot(RPP1DOF, [pi/2 10 5 0])
%pause(1)
%plot(RPP1DOF, [pi/2 10 5 pi/2])
%pause(1)

