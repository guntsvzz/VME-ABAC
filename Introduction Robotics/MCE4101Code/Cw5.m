%CW5
P0 = [1;0;0;1]
R01 = roty(-pi/2)
D12 = transl(0,0,-3)
R23 = rotx(pi/2)
T03 = r2t(R01)*D12*r2t(R23)
P03 = T03*P0