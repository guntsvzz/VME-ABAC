%RPP + 1 DOF Wrist Mechanism 
sym d1
%d1 = 2; 
syms Px Py Pz
%Px = 1.25; Py = 1.5; Pz = 3.25;
d2 = Pz-d1
th1 = atan2d(Py, Px)
d3 = Px/cosd(th1)



