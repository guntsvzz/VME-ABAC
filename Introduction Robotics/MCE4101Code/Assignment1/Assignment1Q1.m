%Assignment1Q1
P0 = [1;0;0;1]
T01 = rotz(pi/2)
T12 = transl(3,0,0)
T23 = roty(pi/2)
T34 = transl(0,0,-2)
T45 = rotz(-pi/2)
T04C = r2t(T01)*T12*r2t(T23)*T34
P4C = T04C*P0
