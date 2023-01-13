%Class Example for 2links: Tool box DH Table method
%th1 must be in rad
syms th1 d1 d2 d3
%th1 = 0; a1 = 2; th2 = 0; a2 = 3;
%%L = link([alpha A theta D])
A1 = link([0 0 th1 d1,  0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([-pi/2 0 0 d2, 0]);
A3 = link([0 0 0 d3, 0]);

%DH Transformation method RPP
RPP = robot({A1 A2 A3}) %%
T03_RPP = fkine(RPP,[th1 d2 d3]) %th1 and th2 are movement variables
%Pend_Toolbox = T03_RPP*[0;0;0;1]
