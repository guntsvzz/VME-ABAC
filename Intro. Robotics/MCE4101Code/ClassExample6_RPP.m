%%ClassExample6 RPP 22July 2021
%syms th1 d2 d3
%syms d1
th1 = pi/2; d1 = 5; d2 = 2; d3 = 3;
%%L = link([alpha A theta D])
A1 = link([0 0 th1 d1,  0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([-pi/2 0 0 d2, 1]);
A3 = link([0 0 0 d3, 1]);

RPP = robot({A1 A2 A3});
T03_RPP = fkine(RPP,[th1 d2 d3])
Pend_Toolbox = T03_RPP*[0;0;0;1]
plot(RPP,[th1 d2 d3])
