%%Assignment2Q4
syms th1 th2  
syms d1 d2  
%bc
%L1 = 1; L2 = 2;
%%L = link([alpha A theta D])
A1 = link([-pi/2 0 0 d1,1]);
A2 = link([0 0 0 d2,1]);

RRR_Assginment = robot({A1 A2});
T03 = fkine(RRR_Assginment,[d1 d2])  
Pend = T03*[0;0;0;1]