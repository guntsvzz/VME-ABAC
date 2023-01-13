%Class Example for 2links: Tool box DH Table method
%th1 must be in rad
%syms th1 a1 th2 a2
th1 = 0; a1 = 2; th2 = 0; a2 = 3;
%%L = link([alpha A theta D])
A1 = link([0 a1 th1 0]);
A2 = link([0 a2 th2 0]);

%DH Transformation method Toolbox
TwolinksRobot = robot({A1 A2})
T02_Toolbox = fkine(TwolinksRobot, [th1 th2]) %th1 and th2 are movement variables
%Pend_Toolbox = T02_Toolbox*[0;0;0;1]
plot(TwolinksRobot, [0,0])
pause(1)
plot(TwolinksRobot, [pi/2,0])
pause(1)
plot(TwolinksRobot, [pi/2,pi/2])
pause(1)
plot(TwolinksRobot, [pi,0])
pause(1)
plot(TwolinksRobot, [3*pi/2,0])