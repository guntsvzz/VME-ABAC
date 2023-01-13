%Chapter 8.5 
%TO Test RRR with 3DOF wrist to solve by ikine
Px = 7.75; Py = 1.95; Pz = 1.5;
a2 = 3; a3 = 5; d1 = 2;
%DH Table %%RRR
%%L = link([alpha A theta D])
L1 = link([pi/2 0 th d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2 0, 0]);
L3 = link([0 a3 th3 0, 0]);
RRRRobot = robot({L1 L2 L3});
%%3 DOF Wrist %ikine
Position = transl(Px, Py, Pz)
Q = [0 0];
M = [1 1 0 0 0 0]; %2 DOF
Data = ikine(RRRRobot, Position, Q, M)
Data_deg = rad2deg(Data)