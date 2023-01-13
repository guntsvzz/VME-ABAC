%Assignment1Q4
P0 = [1;0;0;1]
T01 = rotz(-pi/2)
T12 = transl(-3,0,0)
T23 = roty(-pi/2)
T34 = rotx(pi/2)
T45 = rotz(-pi/2)
T05F = T12*(r2t(T45)*r2t(T34)*r2t(T23)*r2t(T01))
P5F = T05F*P0