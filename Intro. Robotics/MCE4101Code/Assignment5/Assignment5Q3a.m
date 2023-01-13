%%From Q1%%
%Find 2 possible posture solutions for end point location P(2.75,4.763,-2.33)
clear all; clc;
Xc = 2.75; Yc = 4.763; Zc = -2.33;
d1 = 2; a2 = 3; a3 = 5; d6 = 0;
D = (Xc^2+Yc^2+(Zc-d1)^2-a2^2-a3^2)/(2*a2*a3)
th3_n= atan2d(-sqrt(1-D^2),D) 
th2_n = atan2d(Zc-d1, sqrt(Xc^2+Yc^2)) - atan2d(a3*sind(th3_n), a2+a3*cosd(th3_n))
%th3_p= atan2d(sqrt(1-D^2),D) 
%th2_p = atan2d(Zc-d1, sqrt(Xc^2+Yc^2)) - atan2d(a3*sind(th3_p), a2+a3*cosd(th3_p))
th1 = atan2d(Yc,Xc);
th1rad = deg2rad(th1)
th2rad = deg2rad(th2_n);
th3rad = deg2rad(th3_n);
%%L = link([alpha A theta D])
L1 = link([pi/2 0 th1rad d1, 0]); %%0 is revolute (and default), 1 is prismatic
L2 = link([0 a2 th2rad 0, 0]);
L3 = link([0 a3 th3rad 0, 0]);
RRR= robot({L1 L2 L3}); %RRR Case1
T03 = fkine(RRR ,[th1rad th2rad th3rad])
%T03 = [0.25 0.433 0.866 2.75; 0.433 0.75 -0.5 4.76; -0.866 0.5 0 -2.3301; 0 0 0 1];
T06 = [0.397 0.433 0.8095 2.75; 0.34 0.75 -0.568 4.76; -0.853 0.5 0.1504 -2.3301; 0 0 0 1];
%Finding th4 th 5 th6
U = transpose(T03)*T06
th4_p = atan2d(U(2,3),U(1,3))
th5_p = atan2d(sqrt(1-(U(3,3))^2),U(3,3))
th6_p = atan2d(U(3,2),-U(3,1))
th4_n = atan2d(-U(2,3),-U(1,3))
th5_n = atan2d(-sqrt(1-(U(3,3))^2),U(3,3))
th6_n = atan2d(-U(3,2),U(3,1))

%%Using theta1-theta6 from Q1 then use FK to plot%%
%Positive
th4radp = deg2rad(th4_p);
th5radp = deg2rad(th5_p);
th6radp = deg2rad(th6_p);
L4p = link([-pi/2 0 th4radp 0,0]);
L5p = link([pi/2 0 th5radp 0,0]);
L6p = link([0 0 th6radp d6,0]);
Wristp = robot({L4p L5p L6p});
R36p = fkine(Wristp, [th4radp th5radp th6radp]);
T06endp = T03*R36p
Pendp = T06endp*[0;0;0;1]
%Negative
th4radn = deg2rad(th4_n);
th5radn = deg2rad(th5_n);
th6radn = deg2rad(th6_n);
L4n = link([-pi/2 0 th4radn 0,0]);
L5n = link([pi/2 0 th5radn 0,0]);
L6n = link([0 0 th6radn d6,0]);
Wristn = robot({L4n L5n L6n});
R36n = fkine(Wristn, [th4radn th5radn th6radn]);
T06endn = T03*R36n
Pendn = T06endn*[0;0;0;1]
RRRWristP = robot({L1 L2 L3 L4p L5p L6p});
RRRWristN = robot({L1 L2 L3 L4n L5n L6n});
%T = fkine(RRRWristP,[th1rad th2rad th3rad th4rad th5rad th6rad]);
%P = T*[0;0;0;1]
figure(1);
plot(RRRWristP, [th1rad th2rad th3rad th4radp th5radp th6radp]);
figure(2);
plot(RRRWristN, [th1rad th2rad th3rad th4radn th5radn th6radn]);
