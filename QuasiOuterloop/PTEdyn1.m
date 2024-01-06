function xdot=PTEdyn1(t,x,Kv,M)
m=1.6;ml=0.16;L=0.7;G00=10;
% m0=M(1);ml0=M(2);L0=M(3);
% Ts1 = [x(3) + L0 * cos(x(4)) * cos(x(5)) x(8) - x(9) * L0 * sin(x(4)) * cos(x(5)) - x(10) * L0 * cos(x(4)) * sin(x(5))];
% 
% yr = [0.15e1 * sin(pi * t / 0.8e1) 0.1875000000e0 * pi * cos(pi * t / 0.8e1) -0.2343750000e-1 * pi ^ 2 * sin(pi * t / 0.8e1) -0.2929687500e-2 * pi ^ 3 * cos(pi * t / 0.8e1) 0.3662109375e-3 * pi ^ 4 * sin(pi * t / 0.8e1) 0.75e0 * sin(pi * t / 0.4e1) 0.1875000000e0 * pi * cos(pi * t / 0.4e1) -0.4687500000e-1 * pi ^ 2 * sin(pi * t / 0.4e1) -0.1171875000e-1 * pi ^ 3 * cos(pi * t / 0.4e1) 0.2929687500e-2 * pi ^ 4 * sin(pi * t / 0.4e1) -0.10e1 + 0.5e0 * sin(pi * t / 0.8e1) 0.6250000000e-1 * pi * cos(pi * t / 0.8e1) -0.7812500000e-2 * pi ^ 2 * sin(pi * t / 0.8e1) -0.9765625000e-3 * pi ^ 3 * cos(pi * t / 0.8e1) 0.1220703125e-3 * pi ^ 4 * sin(pi * t / 0.8e1)];
% 
% n3 = yr(13) - Kv(1,1)*(Ts1(2)-yr(12)) - Kv(1,2)*(Ts1(1)-yr(11));
% n3p = yr(14) - Kv(1,1)*(n3-yr(13)) - Kv(1,2)*(Ts1(2)-yr(12));
% n3pp = yr(15) - Kv(1,1)*(n3p-yr(14)) - Kv(1,2)*(n3-yr(13));
% Ts = [x(1) + L0 * sin(x(5)) x(6) + x(10) * L0 * cos(x(5)) -sin(x(5)) * (G00 - n3) / cos(x(5)) / cos(x(4)) ((n3p * cos(x(5)) * sin(x(5)) - x(10) * (G00 - n3)) * cos(x(4)) - sin(x(4)) * x(9) * cos(x(5)) * sin(x(5)) * (G00 - n3)) / cos(x(4)) ^ 2 / cos(x(5)) ^ 2 x(2) - L0 * sin(x(4)) * cos(x(5)) x(7) - x(9) * L0 * cos(x(4)) * cos(x(5)) + x(10) * L0 * sin(x(4)) * sin(x(5)) sin(x(4)) * (G00 - n3) / cos(x(4)) (-n3p * sin(x(4)) * cos(x(4)) + x(9) * (G00 - n3)) / cos(x(4)) ^ 2];
% 
% n1 = yr(5) - Kv(2,1)*(Ts(4)-yr(4)) - Kv(2,2)*(Ts(3)-yr(3)) - Kv(2,3)*(Ts(2)-yr(2)) - Kv(2,4)*(Ts(1)-yr(1));
% n2 = yr(10) - Kv(3,1)*(Ts(8)-yr(9)) - Kv(3,2)*(Ts(7)-yr(8)) - Kv(3,3)*(Ts(6)-yr(7)) - Kv(3,4)*(Ts(5)-yr(6));
F = [x(6); x(7); x(8); x(9); x(10); L * ml * sin(x(5)) * (cos(x(5)) ^ 2 * x(9) ^ 2 + x(10) ^ 2) / (m + ml); -cos(x(5)) * sin(x(4)) * (cos(x(5)) ^ 2 * x(9) ^ 2 + x(10) ^ 2) * L * ml / (m + ml); (L * ml * cos(x(4)) * cos(x(5)) * (cos(x(5)) ^ 2 * x(9) ^ 2 + x(10) ^ 2) + (m + ml) * G00) / (m + ml); 0.2e1 * x(10) * x(9) * sin(x(5)) / cos(x(5)); -cos(x(5)) * sin(x(5)) * x(9) ^ 2;];

G0 = [0 0 0; 0 0 0; 0 0 0; 0 0 0; 0 0 0; (ml * cos(x(5)) ^ 2 + m) / m / (m + ml) ml * sin(x(4)) * cos(x(5)) * sin(x(5)) / m / (m + ml) -cos(x(5)) * sin(x(5)) * cos(x(4)) * ml / m / (m + ml); ml * sin(x(4)) * cos(x(5)) * sin(x(5)) / m / (m + ml) ((ml * cos(x(4)) ^ 2 - ml) * cos(x(5)) ^ 2 + m + ml) / m / (m + ml) cos(x(4)) * sin(x(4)) / m * cos(x(5)) ^ 2 * ml / (m + ml); -cos(x(5)) * sin(x(5)) * cos(x(4)) * ml / m / (m + ml) cos(x(4)) * sin(x(4)) / m * cos(x(5)) ^ 2 * ml / (m + ml) (-cos(x(4)) ^ 2 * cos(x(5)) ^ 2 * ml + m + ml) / m / (m + ml); 0 cos(x(4)) / L / cos(x(5)) / m sin(x(4)) / L / cos(x(5)) / m; -cos(x(5)) / m / L -sin(x(5)) * sin(x(4)) / m / L sin(x(5)) * cos(x(4)) / m / L;];

% u1 = ((cos(x(4)) * L0 * (cos(x(4)) ^ 2 * n3pp - cos(x(4)) * sin(x(4)) * n2 + x(9) ^ 2 * (-G00 + n3)) * m0 * cos(x(5)) ^ 3 + 0.3e1 * L0 * x(10) ^ 2 * cos(x(4)) * m0 * (-G00 + n3) * cos(x(5)) + (-G00 + n3) ^ 2 * (m0 + ml0)) * sin(x(5)) + 0.2e1 * L0 * m0 * (-cos(x(5)) ^ 2 * cos(x(4)) ^ 2 * n1 / 0.2e1 + (cos(x(4)) * n3p + x(9) * sin(x(4)) * (-G00 + n3)) * x(10)) * cos(x(5)) ^ 2) / (-G00 + n3) / cos(x(5)) / cos(x(4));
% 
% u2 = (-cos(x(4)) * L0 * m0 * (cos(x(4)) ^ 3 * n2 + cos(x(4)) ^ 2 * sin(x(4)) * n3pp - n2 * cos(x(4)) + x(9) ^ 2 * sin(x(4)) * (-G00 + n3)) * cos(x(5)) ^ 4 - L0 * cos(x(5)) ^ 3 * cos(x(4)) ^ 2 * sin(x(5)) * sin(x(4)) * m0 * n1 - 0.3e1 * cos(x(4)) * L0 * m0 * ((0.2e1 / 0.3e1 * x(9) * n3p + n2 / 0.3e1) * cos(x(4)) + (x(10) ^ 2 + 0.2e1 / 0.3e1 * x(9) ^ 2) * sin(x(4)) * (-G00 + n3)) * cos(x(5)) ^ 2 + (-0.4e1 * L0 * x(10) * x(9) * sin(x(5)) * m0 * (-G00 + n3) * cos(x(4)) ^ 2 + 0.2e1 * L0 * x(10) * sin(x(5)) * cos(x(4)) * sin(x(4)) * m0 * n3p + 0.2e1 * (-(m0 + ml0) * (-G00 + n3) * sin(x(4)) / 0.2e1 + L0 * x(10) * x(9) * sin(x(5)) * m0) * (-G00 + n3)) * cos(x(5)) + 0.2e1 * L0 * x(10) ^ 2 * cos(x(4)) * sin(x(4)) * m0 * (-G00 + n3)) / (-G00 + n3) / cos(x(5)) / cos(x(4));
% 
% u3 = (L0 * cos(x(5)) ^ 4 * cos(x(4)) ^ 4 * m0 * n3pp - L0 * cos(x(5)) ^ 3 * m0 * (cos(x(5)) * sin(x(4)) * n2 - sin(x(5)) * n1) * cos(x(4)) ^ 3 + 0.3e1 * (x(9) ^ 2 * (-G00 + n3) * cos(x(5)) ^ 4 / 0.3e1 + ((x(10) ^ 2 + 0.2e1 / 0.3e1 * x(9) ^ 2) * n3 + (-x(10) ^ 2 - 0.2e1 / 0.3e1 * x(9) ^ 2) * G00 - n3pp / 0.3e1) * cos(x(5)) ^ 2 - 0.2e1 / 0.3e1 * x(10) * cos(x(5)) * sin(x(5)) * n3p - 0.2e1 / 0.3e1 * x(10) ^ 2 * (-G00 + n3)) * L0 * m0 * cos(x(4)) ^ 2 - 0.4e1 * (L0 * x(9) * cos(x(5)) * sin(x(4)) * m0 * n3p / 0.2e1 + (L0 * x(10) * x(9) * sin(x(5)) * sin(x(4)) * m0 - (m0 + ml0) * (-G00 + n3) / 0.4e1) * (-G00 + n3)) * cos(x(5)) * cos(x(4)) - 0.2e1 * L0 * x(9) ^ 2 * cos(x(5)) ^ 2 * m0 * (-G00 + n3)) / (-G00 + n3) / cos(x(5)) / cos(x(4));

param = [1.6, 0.16, 0.7, 10];

u=TracController(x,Kv,param,t);


xdot=F + G0*u;
end
