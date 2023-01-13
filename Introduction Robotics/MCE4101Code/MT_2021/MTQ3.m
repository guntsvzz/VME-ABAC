%%Q3 
syms th1 th2 th6  
syms L1 L2 L3 L4 L5 
%bc
%th1 = pi/2; th2 = 0 ; th6 = 0 ;
%L1 = 50; L2 = 25 ; L3 = 10 ; L4 = 10 ; L5 = 5;
%de
%th1 = pi/2; th2 = pi/2 ; th6 = 0 ;
%L1 = 50; L2 = 25 ; L3 = 10 ; L4 = 10 ; L5 = 5;
%%L = link([alpha A theta D])
A0 = link([0  0 th1 L1, 0]); %%0 is revolute (and default), 1 is prismatic
A1 = link([0 L2 0 0, 1]);
A2 = link([pi L3 th2 0, 0]);
A3 = link([0 0 0 L4, 1]);
A4 = link([pi 0 th6 L5, 0]);
RRR_Assginment = robot({A0 A1 A2 A3 A4});
T03 = fkine(RRR_Assginment,[th1 L2 th2 L4 th6])
Pend = T03*[0;0;0;1]