%Chapter 8 
%class exmaple 2 links to solve by ikine
Px = 7.5; Py = 2; Pz = 0;
a1 = 3; a2 = 5;
%DH Table
%%L = link([alpha A theta D])
L1 = link([0 a1 0 0, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 0 0, 0]);
TwoLinks = robot({L1 L2});
%ikine
Position = transl(Px, Py, Pz);
Q = [0 0]; %given in examination
M = [1 1 0 0 0 0]; %2 DOF
Data = ikine(TwoLinks, Position, Q, M)
Data_deg = rad2deg(Data)

%Check answer with FK
T03 = fkine(TwoLinks, [Data])
Pend = T03*[0;0;0;1]