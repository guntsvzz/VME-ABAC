%classwork10  Inv Analystic RPP
%Px =3.5; Py = 0; Pz = 2.5
Px = 1; Py = 1.732; Pz = 2
L1 = 0.5; L2 = 1.5;
d2 = Pz-L1;
th1 = atan2d(Py, Px);
d3 = Px/cosd(th1)-L2;

%Check answer With FK
%DH Table
%%L = link([alpha A theta D])
A1 = link([0 0 0 L1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([pi/2 0 pi/2 1, 1]);
A3 = link([0 0 0 1, 1]);  %where L2d3 = L2+d3 
ClassRobot = robot({A1 A2 A3});
T03 = fkine(ClassRobot,[deg2rad(th1) d2 L2+d3])
Pend = T03*[0;0;0;1]