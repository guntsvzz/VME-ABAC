%%RRP with no offset d = 0
d1 = 2; a2 = 3;
Xc = 7.75; Yc = 1.95; Zc = 1.8;
r = sqrt(Xc^2+Yc^2)
s = Zc-d1
d3 = sqrt(r^2+s^2)-a2
th2 = atan2d(s,r)
th1 = atan2d(Yc,Xc) 

%RRP
%%L = link([alpha A theta D])
L1 = link([pi/2 0 0 d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([pi/2 a2 0 0, 0]);
L23 = link([pi/2 0 pi/2 0,0]); %dummy link
L3 = link([0 0 0 1, 1]); 
RRPRobot = robot({L1 L2 L23 L3});

%%For Checking
%UP
th1 = deg2rad(14.1232); 
th2 = deg2rad(-1.4336); 
d3 = 4.9941;
%DOWN
%th1 = deg2rad(14.1232); 
%th2 = deg2rad(1.4336); 
%d3 = 4.9941;

RRP_FK = fkine(RRPRobot,[th1 th2 pi/2 d3])
RRP_Pend= RRP_FK*[0;0;0;1]
plot(RRR,[th1 th2 0 d3])
