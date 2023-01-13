%%Quiz1F
P0 = [0;0;1;1]
T01 = roty(-pi/2)
T12 = transl(2,0,0)
T23 = rotx(pi/2)
T34 = rotz(pi/2)
T45 = transl(0,0,-2)
T05F = T45*T12*r2t(T34)*r2t(T23)*r2t(T01)
P5F = T05F*P0