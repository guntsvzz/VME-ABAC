%Class Example 4 fixed frame 6 july 2021
P0 = [1;0;0]
T01 = roty(pi/2)
T12 = rotz(pi/2)
T02 = T01*T12
P2 = T02*P0