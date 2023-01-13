%Class Example for 2links: Tool box DH Table method
%th1 must be in rad
syms th1 a1 th2 a2 th3 a3
%th1 = 0; a1 = 2; th2 = 0; a2 = 3;
%%L = link([alpha A theta D])
A1 = link([0 a1 th1 0]);
A2 = link([0 a2 th2 0]);
A3 = link([0 a3 th3 0]);

%DH Transformation method Toolbox
ThreelinksRobot = robot({A1 A2 A3})
T03_Toolbox = fkine(ThreelinksRobot, [th1 th2 th3]) %th1 and th2 are movement variables
%Pend_Toolbox = T03_Toolbox*[0;0;0;1]
