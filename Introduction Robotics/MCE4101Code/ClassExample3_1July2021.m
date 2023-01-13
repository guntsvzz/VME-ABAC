%Class Example3_1 july 2021
P0 = [0;0;0;1]
R01 = roty(pi/2)
D12 = transl(0,0,2)
R23 = rotx(pi/2)
D34 =  transl(0,0,3)
T04 = r2t(R01)*D12*r2t(R23)*D34
P04 = T04*P0