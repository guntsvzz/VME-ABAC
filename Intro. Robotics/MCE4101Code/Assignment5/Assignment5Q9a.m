%Find possible posture solutions for end point location P(1.5,2.75,5)
syms d2 th1rad d3 d3L2
Px = 1.5; Py = 2.75; Pz = 5;
L1 = 2.5; L2 =0; L6 = 0.15;
T03 = [0.866 0 0.5 1.5; 0.5 0 0.866 2.5981; 0 1 0 5; 0 0 0 1];
d2 = 5-L1
th1 = atan2d(2.5981,Px)
d3 = (Px)/cosd(th1)-L2
d3L2 = d3+L2
th1_rad = deg2rad(th1);
%RRP
A1 = link([0 0 th1_rad L1,0]);
A2 = link([pi/2 0 pi/2 d2,1]);
A3 = link([0 0 0 d3L2,1]); %where dL3 = L2+d3
RPPRobot = robot ({A1 A2 A3});
T03 = fkine(RPPRobot, [th1_rad d2 d3L2])
T06 = [-1 -0 0 1.5; 0 -0 1 2.75; 0 1 0 5; 0 0 0 1]
U = transpose(T03)*T06
%Positive
th4_p = atan2d(U(2,3),U(1,3))
th5_p = atan2d(sqrt(1-(U(3,3))^2),U(3,3))
th6_p = atan2d(U(3,2),-U(3,1))
th4rad = deg2rad(th4_p);
th5rad = deg2rad(th5_p);
th6rad = deg2rad(th6_p);

%Negative
th4_n = atan2d(-U(2,3),-U(1,3))
th5_n = atan2d(-sqrt(1-(U(3,3))^2),U(3,3))
th6_n = atan2d(-U(3,2),U(3,1))
th4radn = deg2rad(th4_n);
th5radn = deg2rad(th5_n);
th6radn = deg2rad(th6_n);

%%Using theta1-theta6 fromQ7 then use FK to plot%%
A4p = link([-pi/2 0 th4rad 0,0]);
A5p = link([pi/2 0 th5rad 0,0]);
A6p = link([0 0 th6rad L6,0]);
Wristp = robot({A4p A5p A6p});
R36p = fkine(Wristp, [th4rad th5rad th6rad]);
T0endp = T03*R36p
Pendp = T0endp*[0;0;0;1]

A4n = link([-pi/2 0 th4radn 0,0]);
A5n = link([pi/2 0 th5radn 0,0]);
A6n = link([0 0 th6radn L6,0]);
Wristn = robot({A4n A5n A6n});
R36n = fkine(Wristn, [th4radn th5radn th6radn]);
T0endn = T03*R36n
Pendn = T0endn*[0;0;0;1]

RRRWristp = robot({A1 A2 A3 A4p A5p A6p});
RRRWristn = robot({A1 A2 A3 A4n A5n A6n});
%figure(1);
%plot(RRRWristp, [th1_rad d2 d3L2 th4rad th5rad th6rad]);
%figure(2);
%plot(RRRWristn, [th1_rad d2 d3L2 th4radn th5radn th6radn]);