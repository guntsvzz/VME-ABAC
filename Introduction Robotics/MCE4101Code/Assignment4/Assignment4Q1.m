%%RRR with no offset d = 0
d1 = 2; a2 = 3; a3 = 5 ;
Xc = 7.75; Yc = 1.95; Zc = 1.8;
r = sqrt(Xc^2+Yc^2)
s = Zc - d1
D = (Xc^2+Yc^2+(Zc-d1)^2-a2^2-a3^2)/(2*a2*a3)

th3 = atan2d((sqrt(1-D^2)),D) %%tan = tang in rad %tand = tang in degree
th2_UP = atan2d(Zc-d1, sqrt(r)) - atan2d(a3*sind(th3), a2+a3*cosd(th3))
th2_DOWN = atan2d(Zc-d1, sqrt(r)) - atan2(a3*sind(-th3), a2+a3*cosd(-th3))
th1 = atan2d(Yc,Xc)

%%For Checking
th1 = 0; th2 = 0; th3 = 0;
d1 = 2; a2 = 3; a3 = 5; 
%RRR
%%L = link([alpha A theta D])
L1 = link([pi/2 0 th1 d1,  0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2 0, 0]);
L3 = link([0 a3 th3 0, 0]);
RRRrobot = robot({L1 L2 L3});

%UP
%th1_rad = deg2rad(14.12);
%th2_rad = deg2rad(-6.897);
%th3_rad = deg2rad(4.5609);

%DOWN
th1_rad = deg2rad(14.12);
th2_rad = deg2rad(-6.897);
th3_rad = deg2rad(-3.9971);

RRR_FK = fkine(RRRrobot,[th1_rad th2_rad th3_rad])
RRR_Pend = RRR_FK*[th1;th2;th3;1]
plot(RRRrobot,[th1 th2 th3])
