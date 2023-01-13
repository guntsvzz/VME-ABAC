%Class Example 1 july 2021
P0 = [1;0;0;1]
R01 = rotz(pi)
D12 = transl(0,3,0)
T02 = r2t(R01)*D12
P2 = T02*P0