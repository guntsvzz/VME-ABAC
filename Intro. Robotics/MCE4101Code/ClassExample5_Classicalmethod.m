%Class Example for 2links: classical method
%th1 must be in rad
syms th1 a1 th2 a2
%th = 3*pi/2; a1 =2; th2 = 0; a2=3;
R01 = rotz(th1);
D12 = transl(a1,0,0);
R23 = rotz(th2);
D34 = transl(a2,0,0);
T04 = r2t(R01)*D12*r2t(R23)*D34
Pend = T04*[0;0;0;1]