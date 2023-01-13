%CW9 Chapter 6
a1 = 3; a2 = 5;
Px = -7.75; Py = -1.95;
D = (Px^2+Py^2-a1^2-a2^2)/(2*a1*a2)
th2 = atan2d((sqrt(1-D^2)),D) 
%%tan = tang in rad
%tand = tang in degree

th1aUP = atan2d(Py,Px);
th1bUP = atan2d(a2*sind(th2),(a1+a2*cosd(th2)));
%UP = Positive DOWN = Negative
th1aDOWN = atan2d(Py,Px);
th1bDOWN = atan2d(a2*sind(-th2),(a1+a2*cosd(-th2)));

th1_armUP = th1aUP - th1bUP
th1_armDOWN = th1aDOWN - th1bDOWN