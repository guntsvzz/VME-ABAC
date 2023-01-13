%Class Example2_1 july 2021
P0 = [1;0;0;1]
R12 = rotz(pi)
D01 = transl(0,3,0)
T02 = D01*r2t(R12)
P2 = T02*P0