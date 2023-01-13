%%ClassExample6 RPR 22July 2021
%syms th1 th3 d2 
%syms d1
d1 = 3; d2 = 5; 
%%L = link([alpha A theta D])
A1 = link([-pi/2 0 0 d1,  1]); %%0 is revolute (and default), 1 is prismatic
A2 = link([0 0 0 d2, 1]);

PP = robot({A1 A2});
T02_PP = fkine(PP,[d1 d2])
Pend_Toolbox = T02_PP*[0;0;0;1]
%plot(RPP,[th1 d2 d3])
