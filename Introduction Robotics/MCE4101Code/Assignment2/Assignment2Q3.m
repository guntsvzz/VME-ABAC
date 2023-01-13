%%Assignment2_3 
syms th1 th2 th3 
syms d1 
syms a2 a3
%b
%th1 = pi/2; th2 = 0 ; th3 = 0 ;
%d1 = 3; a2 = 2; a3 = 1.5;
%c
th1 = 0; th2 = pi/6 ; th3 = -pi/9 ;
d1 = 3; a2 = 2; a3 = 1.5;
%%L = link([alpha A theta D])
A0 = link([0 0 pi/2 0, 0]);
A1 = link([pi/2 0 th1 d1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([0 a2 th2 0, 0]);
A3 = link([0 a3 th3 0, 0]);

RRR_Assginment = robot({A0 A1 A2 A3});
T03 = fkine(RRR_Assginment,[pi/2 th1 th2 th3])
Pend = T03*[0;0;0;1]