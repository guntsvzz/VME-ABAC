%%EXTRA CLASS
%%26 SEP 2021
%DHTable
d1 = 2; d6 = 0;
a2 = 3; a3 = 5; 
th1 = 0; th2 = 0; th3 = 0;
th4 = 0; th5 = 0; th6 = 0;
%%L = link([alpha A theta D])
L1 = link([pi/2 0 th1 d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2 0, 0]);
L3 = link([0 a3 th3 0, 0]);
L4 = link([-pi/2 0 th4 0, 0]); 
L5 = link([pi/2 0 th5 0, 0]);
L6 = link([0 0 th6 d6, 0]);
RRR3DOF = robot({L1 L2 L3 L4 L5 L6});
%ikine
Location1 = transl(2.75,4.763,-2.33);
Location2 = transl(-3,4.8,-2.33);
IG1 = [pi/10 -pi/150 pi/150 pi/100 -pi/100 pi/100];
IG2 = [pi/10 -pi/150 pi/150 pi/100 -pi/100 pi/100];
M = [1 1 1 1 1 1]; %6DOF
Data1_rad = ikine(RRR3DOF, Location1, IG1, M);
Data1_deg = rad2deg(Data1_rad)
Data2_rad = ikine(RRR3DOF, Location2, IG2, M);
Data2_deg = rad2deg(Data2_rad)

%Check answer
T06_P1 = fkine(RRR3DOF, Data1_rad);
P1_check = T06_P1*[0;0;0;1]
T06_P2 = fkine(RRR3DOF, Data2_rad);
P2_check = T06_P2*[0;0;0;1]

%To obtain the coefficient
%In case acceleration is not controlled
%Joint 1 :
t0 = 0; tf = 2;
N1 = [60;0;122;0]; 
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A1 = inv(B1)*N1

%Joint 2 :
t0 = 0; tf = 2;
N2 = [0;0;73;0]; 
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A2 = inv(B2)*N2

%Joint 3 :
%Joint 4 :
%Joint 5 : No movement
%Joint 6 :