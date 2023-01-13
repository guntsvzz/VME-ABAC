%Chapter6 Case1
d1 = 2; a2 = 3; a3 = 5 ;
Xc = 7.75; Yc = 1.95; Zc = 1.8;
r = sqrt(Xc^2+Yc^2)
s = Zc-d1
D = (Xc^2+Yc^2+(Zc-d1)^2-a2^2-a3^2)/(2*a2*a3)

%%tan = tang in rad
%tand = tang in degree
th3 = atan2d((sqrt(1-D^2)),D)
th2 = atan2d(s, r) - atan2d(a3*sind(th3), a2+a3*cosd(th3))
%th2_DOWN = atan2d(Zc - d1,sqrt(r)) - atan2(a3*sin(-th3), (a2+a3*cos(-th3)))
th1 = atan2d(Yc,Xc)

%%For Checking
th1 = 0; th2 = 0; th3 = 0;
d1 = 2; a2 = 3; a3 = 5; 
%%L = link([alpha A theta D])
A1 = link([pi/2 0 th1 d1,  0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([0 a2 th2 0, 0]);
A3 = link([0 a3 th3 0, 0]);

CW10RB = robot({A1 A2 A3});

th1_rad = deg2rad(14.1232);
th2_rad = deg2rad(-4.2845);
th3_rad = deg2rad(4.5609);

CW10RB_PP = fkine(CW10RB,[th1_rad th2_rad th3_rad])

Pend = CW10RB_PP*[th1;th2;th3;1]
%plot(RPP,[th1 d2 d3])
