%CW7
P0 = [1;0;0;1]
T01 = roty(-pi/2)
T12 = transl(0,0,-3)
T23 = rotx(pi/2)
T34 = transl(0,3,0)
T04F = T34*T12*[r2t(T23)*r2t(T01)]
P04F = T04F*P0