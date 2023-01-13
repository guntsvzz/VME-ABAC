%%Assignment2_2 
syms th1 th2 ht3
syms L1 L2 L3
%b
%th1 = 0; th2 = 0; th3 = 0; 
%L1 = 1; L2 = 2; L3 = 3;
%c
%th1 = 0; th2 = pi/2; th3 = 0; 
%L1 = 1; L2 = 2; L3 = 3;
%%L = link([alpha A theta D])
A1 = link([pi/2 L1 th1 0, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([0 L2 th2 0, 0]);
A3 = link([0 L3 th3 0, 0]);

RRR_Assginment = robot({A1 A2 A3});
T03 = fkine(RRR_Assginment,[th1 th2 th3])
Pend_Toolbox = T03*[0;0;0;1]

plot(RRR_Assginment,[0 0 0])
pause(1)
plot(RRR_Assginment,[pi/2 0 0])
pause(1)
plot(RRR_Assginment,[pi 0 0])
pause(1)
plot(RRR_Assginment,[pi pi/2 0])
pause(1)