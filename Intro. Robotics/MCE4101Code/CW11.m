%CW11
%InvGeometric
d1 = 5; a2 = 2;
Xc = 2.5; Yc = 1; Zc = 6;
r = sqrt(Xc^2+Yc^2)
s = Zc - d1
d3 = sqrt(Xc^2+Yc^2+(Zc-d1)^2)-a2
th2 = atan2d(Zc-d1, sqrt(Xc^2+Yc^2))
th1 =  atan2d(Yc, Xc) 

%%L = link([alpha A theta D])
L1 = link([pi/2 0 0 d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([pi/2 a2 0 0, 0]);
L23 = link([pi/2 0 pi/2 0,0]); %dummy link
L3 = link([0 0 0 1, 1]); 
RRPRobot = robot({L1 L2 L23 L3});
%From geometric
th1 = deg2rad(21.8014); 
th2 = deg2rad(20.3745); 
d3 = 0.8723;
T03 = fkine(RRPRobot,[th1 th2 pi/2 d3])
T03_Endpoint = T03*[0;0;0;1]

%Checking 
%th1_1 = 21.8; th2_1 = 20.37;
%T01 = rotz(th1_1*pi/180);
%T12 = transl(0,0,5);
%T23 = roty(-th2_1*pi/180);
%T34 = transl(2,0,0);
%T45 = transl(d3,0,0);
%T05 =r2t(T01)*T12*r2t(T23)*T34*T45
%Pend = T05*[0;0;0;1]