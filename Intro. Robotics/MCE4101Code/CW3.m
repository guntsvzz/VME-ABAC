clc; clear all;
P0 = [0;2;0];
theta1_deg = -130;
theta1_rad = deg2rad(theta1_deg);
theta2_deg = -240;
theta2_rad = deg2rad(theta2_deg);

R01 = rotx(theta1_rad)
P1 = R01*P0

R02 = rotx(theta2_rad)
P2 = R02*P0