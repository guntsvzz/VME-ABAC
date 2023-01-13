%Geometric
Px = 0; Py = 7; Pz = 3;
d1= 5; a2 =3; a3= 5; d6 =0.1; 
th1 = 0; th2 = 0; th3 = 0;
th4 = 0; th5 = 0; th6 = 0;
%RRR
L1 = link([pi/2 0 th1 d1, 0]);
L2 = link([0 a2 th2 0, 0]);
L3 = link([0 a3 th3 0, 0]);
%DOF
L4 = link([-pi/2 0 th4 0, 0]);
L5 = link([pi/2 0 th5 0, 0]);
L6 = link([0 0 th6 d6, 0]);
RRR3DOFRobot = robot({L1 L2 L3 L4 L5 L6});
Position =transl(Px,Py,Pz);
IG = [0.1 -0.1 0 -0.1 0.1 0.1]; %6DOF
M = [1 1 1 1 1 1]; %6DOF
data_rad = ikine(RRR3DOFRobot, Position, IG, M)
data_deg = rad2deg(data_rad)

%Check answer
T06_values = fkine(RRR3DOFRobot, data_rad)
Pend = T06_values*[0;0;0;1]