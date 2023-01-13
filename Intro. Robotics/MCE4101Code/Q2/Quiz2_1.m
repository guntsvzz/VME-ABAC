%RPP + 1 DOF Wrist Mechanism
syms th1  
syms d1 d2 d3 
d1 = 2.5;

syms Px = 1.77; Py = 1.77; Pz = 2.75;
d1 = 2.5;
d2 = Pz-d1
th1 = atan2d(Py, Px)
d3 = Px/cosd(th1)

%%RPP
%%L = link([alpha A theta D])
A1 = link([0 0 0 d1, 0]); %%0 is revolute (and default), 1 is prismatic
A2 = link([pi/2 0 pi/2 1, 1]);
A3 = link([0 0 0 1, 1]);
%%1DOF Wrist Mechanism 

RPP1DOF = robot({A1 A2 A3});
T03 = fkine(RPP1DOF,[deg2rad(45) 0.2500 2.5032])
Pend = T03*[0;0;0;1]