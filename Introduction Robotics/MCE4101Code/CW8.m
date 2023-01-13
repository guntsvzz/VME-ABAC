%%CW 8 Chapter 6 19 AUG 2021
%A
syms th1 th4 
syms d1 d2 d3 d4
%%B
%th1 = 0, d1 = 0, d2 = 10, d3 = 5, d4 = 0.5, th4 = 0
%%C
%th1 = pi/2, d2 = 10, d3 = 5, d4 = 0.5, th4 = 0
%%D
%th1 = pi/2, d2 = 10, d3 = 5, d4 = 0.5, th4 = pi/2
%%L = link([alpha A theta D])
%%0 is revolute (and default), 1 is prismatic
A1 = link([0 0 th1 d1, 0]);
A2 = link([-pi/2 0 0 d2, 1]);
A3 = link([0 0 0 d3, 1]);
%A34 = link([-pi/2 0 0 0, 0]);
A4 = link([0 0 th4 d4, 0]);
CW8Robot = robot({A1 A2 A3 A4});
CW8Robotequation = fkine(CW8Robot ,[th1 d2 d3 d4])
%Pend = CW8Robotequation*[0;0;0;1]

plot(CW8Robot ,[0 10 5 0])
pause(1)
plot(CW8Robot ,[pi/2 10 5 0])
pause(1)
plot(CW8Robot ,[pi/2 10 5 pi/2])
pause(1)

