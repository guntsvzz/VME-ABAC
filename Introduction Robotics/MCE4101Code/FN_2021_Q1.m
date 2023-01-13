%Final Q1
clear all; clc;
%Path Equation
%%Joint 1 cubic
q1_0 = 0 
q1_f = 60;
v1_0 = 0; 
v1_f = 5.5;
t0 = 0; tf = 2;
Y1 = [q1_0;v1_0;q1_f;v1_f];
B1 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
%A1 = [a1_0;a1_1;a1_2;a1_3];
A1 = inv(B1)*Y1
%Joint 2
q2_0 = 20;
q2_f = 60;
v2_0 = 5.5;
v2_f = 0;
Y2 = [q2_0;v2_0;q2_f;v2_f];
B2 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A2 = inv(B2)*Y2
%Joint 3
q3_0 = 60;
q3_f = 0;
v3_0 = 0;
v3_f = 0;
Y3 = [q3_0;v3_0;q3_f;v3_f];
B3 = [1 t0 t0^2 t0^3; 0 1 2*t0 3*t0^2; 1 tf tf^2 tf^3; 0 1 2*tf 3*tf^2];
A3 = inv(B3)*Y3

%%Joint 1 trajectory equations
for i = 1:3 %10 datas
t1(i) = i/10;
q1(i) = (42.25*t1(i)^2) - (13.625*t1(i)^3)
v1(i) = 84.45*t1(i) - 40.875*t1(i)^2
at1(i) = 84.45 - 81.75*t1(i)
end

%%Joint 2 trajectory equations
for ii = 3:5 %10 datas
t2(ii) = ii/10;
q2(ii) = 20 + 5.5*t2(ii) + 24.5*t2(ii)^2 - 8.625*t2(ii)^3
v2(ii) = 5.5 + 49*t2(ii)- 25.875*t2(ii)^2
at2(ii) = 49 - 51.75*t2(ii)
end

%%Joint 3 trajectory equations
for iii = 5:7 %10 datas
t3(iii) = iii/10;
q3(iii) = 60 - 45*t3(iii)^2 + 15*t3(iii)^3
v3(iii) = -90*t3(iii) + 45*t3(iii)^2
at3(iii) = -90 + 90*t3(iii)
end

figure(1);
subplot(3,1,1)
title('Trajectory equation for Joint1')
plot(t1,q1,t2,q2,t3,q3)
ylabel('Th1')
axis([0 2 0 80])
grid on;
subplot(3,1,2)
plot(t1,v1,t2,v2,t3,v3)
ylabel('v1')
axis([0 2 0 60])
grid on;
subplot(3,1,3)
plot(t1,at1,t2,at2,t3,at3)
ylabel('a1')
axis([0 2 -100 100])
xlabel('Time')
grid on;



