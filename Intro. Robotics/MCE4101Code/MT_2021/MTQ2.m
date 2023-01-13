%%Q2
%syms L1 L2 L3 L5
L1 = 50 ; L2 = 25 ; L3 = 10 ; L5 = 5 ;
L4= 10;
P0 = [0;0;0;1]
T01 = transl(0,0,L1)
T11 = rotz(-pi/2)
T12 = transl(0,-L2,0)
T22 = transl(0,-L3,0)
T23 = rotz(pi/2)
T34 = transl(0,0,-L4)
T44 = transl(0,0,-L5)
T45 = roty(pi)
%tran*rot
T05F = T44*T34*T22*T12*r2t(T45)*r2t(T23)*r2t(T01)
P5F = T05C*P0
