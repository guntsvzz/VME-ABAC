%%ClassExample6 RPR 22July 2021
%syms th1 th3 d2 
%syms d1
th1 = 0; th3 = 0; d1 = 5; d2 = 3; 
%%L = link([alpha A theta D])
A1 = link([-pi/2 0 th1 d1,  0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([0 0 0 d2, 1]);
A3 = link([0 0 th3 0, 0]);

RPP = robot({A1 A2 A3});
T03_RPP = fkine(RPP,[th1 d2 th3])
Pend_Toolbox = T03_RPP*[0;0;0;1]
%plot(RPP,[th1 d2 d3])
