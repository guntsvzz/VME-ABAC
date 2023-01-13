%Class Example for 2links: DH Table method
%th1 must be in rad
%syms th1 a1 th2 a2
th1 = 3*pi/2; a1 =2; th2 = 0; a2=3;

%Link1 
R1_1 = rotz(th1);
D1_2 = transl(0,0,0);
D1_3 = transl(a1,0,0);
R1_4 = rotx(0);
A1 = r2t(R1_1)*D1_2*D1_3*r2t(R1_4);

%Link1 
R2_1 = rotz(th2);
D2_2 = transl(0,0,0);
D2_3 = transl(a2,0,0);
R2_4 = rotx(0);
A2 = r2t(R2_1)*D2_2*D2_3*r2t(R2_4);

%DH Transformation method
T02 = A1*A2
Pend = T02*[0;0;0;1]