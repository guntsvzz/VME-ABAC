%%Assignment2_1 
syms th1 
syms d1 d2 d3
%b
%th1 = 0; 
%d1 = 1; d2 = 1; d3 = 2;
%%L = link([alpha A theta D])
A1 = link([0 0 th1 d1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([-pi/2 0 0 d2, 1]);
A3 = link([0 0 0 d3, 1]);

RRR_Assginment = robot({A1 A2 A3});
%b
T03 = fkine(RRR_Assginment,[th1 d2 d3])
%c
Pend = T03*[0;0;0;1]