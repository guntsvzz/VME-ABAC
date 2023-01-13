
Px = 0; Py = 7; Pz = 3;
a2 =3; a3= 5; d1= 5;
d6 = 0.1;
D = (Px^2+Py^2+(Pz-d1)^2-a2^2-a3^2)/(2*a2*a3)
th3 = atan2d(sqrt(1-D^2),D)
th2 = atan2d(Pz-d1,sqrt(Px^2+Py^2))-atan2d(a3*sind(th3),(a2+a3*cosd(th3)))
th1 = atan2d(Py,Px)

th1rad = deg2rad(th1)
th2rad = deg2rad(th2)
th3rad = deg2rad(th3)
%RRR
L1 = link([pi/2 0 th1rad d1, 0]);
L2 = link([0 a2 th2rad 0, 0]);
L3 = link([0 a3 th3rad 0, 0]);
RRR = robot({L1 L2 L3});
R03 = fkine(RRR,[th1rad th2rad th3rad])

th4rad = 0
th5rad = 0
%th6rad = 0
%DOF
L4 = link([-pi/2 0 th4rad 0, 0]);
L5 = link([pi/2 0 th5rad 0, 0]);
L6 = link([0 0 th6rad d6, 0]);
RRR3DOFRobot = robot({L4 L5 L6});

R36 = fkine(RRR3DOFRobot, [th4rad th5rad th6rad])
Position = transpose(R03)*(R03*R36)
S = solve(atan2(Position(2,1),Position(1,1))-th6rad == 0, th6rad)
th6 = rad2deg(s)
R36 = fkine(RRR3DOFRobot, [th4rad th5rad S])
T0end = round(R03*R36)
Pend = T0end*[0;0;0;1]