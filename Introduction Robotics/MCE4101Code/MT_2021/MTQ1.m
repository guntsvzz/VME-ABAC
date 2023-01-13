%%Q1
%syms L1 L2 L3 L5
L1 = 50 ; L2 = 25 ; L3 = 10 ; L5 = 5;
L4= 10;
P0 = [0;0;0;1]
T01 = transl(0,0,L1)
T11 = rotz(-pi/2)
T12 = transl(L2,0,0)
T22 = transl(L3,0,0)
T23 = rotz(pi/2)
T34 = transl(0,0,-L4)
T44 = transl(0,0,-L5)
T45 = roty(pi)
T05C = T01*r2t(T11)*T12*T22*r2t(T23)*T34*T44*r2t(T45)
P5C = T05C*P0
