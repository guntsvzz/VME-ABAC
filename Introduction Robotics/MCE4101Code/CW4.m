%%Q1 for CW4
P0a = [0;2;0];
th1 = deg2rad(120);
th2 = deg2rad(-30);
R01 = rotx(th1)
P1 = R01*P0a

R02 = rotx(th2)
P2 = R02*P0

%%Q2 for CW4
P0b = [0;0;2];
th3 = deg2rad(-30);
th4 = deg2rad(50);
R03 = rotx(th3)
P3 = R03*P0b

R04 = rotx(th4)
P4 = R04*P0b

%%Q3 for Cw4
P0c = [0;2;0];
th3 = deg2rad(-90);
th12 = deg2rad(90)
R03 = rotx(th3)
R12 = R01*P0c
P2c = R03*P0c


