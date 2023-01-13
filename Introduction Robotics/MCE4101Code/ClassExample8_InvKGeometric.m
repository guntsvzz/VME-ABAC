%%Chapter 6
%%ClassExample 8 Inverse Kinematic with Geometric 
%Variables
a1 = 3; a2 = 5;
Px = 7.5; Py = 2;
D = (Px^2+Py^2-a1^2-a2^2)/(2*a1*a2)
th2 = atand((sqrt(1-D^2))/D) 
%%tan = tang in rad
%tand = tang in degree

th1aUP = atand(Py/Px);
th1bUP = atand(a2*sind(th2)/(a1+a2*cosd(th2)));
%UP = Positive DOWN = Negative
th1aDOWN = atand(Py/Px);
th1bDOWN = atand(a2*sind(-th2)/(a1+a2*cosd(-th2)));

th1_armUP = th1aUP - th1bUP
th1_armDOWN = th1aDOWN - th1bDOWN