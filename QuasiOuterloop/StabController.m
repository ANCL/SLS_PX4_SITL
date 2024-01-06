function u=StabController(x,Kv,param,setpoint)
m=param(1);m__l=param(2);L=param(3);G00=param(4);
m0 = m; ml0 = m__l; L0 = L;
Ts1 = [x(3) + L0 * cos(x(4)) * cos(x(5)) x(8) - x(9) * L0 * sin(x(4)) * cos(x(5)) - x(10) * L0 * cos(x(4)) * sin(x(5))];

n3 = -Kv(1,1)*(Ts1(2)) - Kv(1,2)*(Ts1(1)-setpoint(3));
n3p = -Kv(1,1)*(n3) - Kv(1,2)*(Ts1(2));
n3pp = - Kv(1,1)*(n3p) - Kv(1,2)*(n3);
Ts = [x(1) + L0 * sin(x(5)) x(6) + x(10) * L0 * cos(x(5)) -sin(x(5)) * (G00 - n3) / cos(x(5)) / cos(x(4)) ((n3p * cos(x(5)) * sin(x(5)) - x(10) * (G00 - n3)) * cos(x(4)) - sin(x(4)) * x(9) * cos(x(5)) * sin(x(5)) * (G00 - n3)) / cos(x(4)) ^ 2 / cos(x(5)) ^ 2 x(2) - L0 * sin(x(4)) * cos(x(5)) x(7) - x(9) * L0 * cos(x(4)) * cos(x(5)) + x(10) * L0 * sin(x(4)) * sin(x(5)) sin(x(4)) * (G00 - n3) / cos(x(4)) (-n3p * sin(x(4)) * cos(x(4)) + x(9) * (G00 - n3)) / cos(x(4)) ^ 2];

n1 = - Kv(2,1)*(Ts(4)) - Kv(2,2)*(Ts(3)) - Kv(2,3)*(Ts(2)) - Kv(2,4)*(Ts(1)-setpoint(1));
n2 = - Kv(3,1)*(Ts(8)) - Kv(3,2)*(Ts(7)) - Kv(3,3)*(Ts(6)) - Kv(3,4)*(Ts(5)-setpoint(2));
u1 = ((cos(x(4)) * L0 * (cos(x(4)) ^ 2 * n3pp - cos(x(4)) * sin(x(4)) * n2 + x(9) ^ 2 * (-G00 + n3)) * m0 * cos(x(5)) ^ 3 + 0.3e1 * L0 * x(10) ^ 2 * cos(x(4)) * m0 * (-G00 + n3) * cos(x(5)) + (-G00 + n3) ^ 2 * (m0 + ml0)) * sin(x(5)) + 0.2e1 * L0 * m0 * (-cos(x(5)) ^ 2 * cos(x(4)) ^ 2 * n1 / 0.2e1 + (cos(x(4)) * n3p + x(9) * sin(x(4)) * (-G00 + n3)) * x(10)) * cos(x(5)) ^ 2) / (-G00 + n3) / cos(x(5)) / cos(x(4));

u2 = (-cos(x(4)) * L0 * m0 * (cos(x(4)) ^ 3 * n2 + cos(x(4)) ^ 2 * sin(x(4)) * n3pp - n2 * cos(x(4)) + x(9) ^ 2 * sin(x(4)) * (-G00 + n3)) * cos(x(5)) ^ 4 - L0 * cos(x(5)) ^ 3 * cos(x(4)) ^ 2 * sin(x(5)) * sin(x(4)) * m0 * n1 - 0.3e1 * cos(x(4)) * L0 * m0 * ((0.2e1 / 0.3e1 * x(9) * n3p + n2 / 0.3e1) * cos(x(4)) + (x(10) ^ 2 + 0.2e1 / 0.3e1 * x(9) ^ 2) * sin(x(4)) * (-G00 + n3)) * cos(x(5)) ^ 2 + (-0.4e1 * L0 * x(10) * x(9) * sin(x(5)) * m0 * (-G00 + n3) * cos(x(4)) ^ 2 + 0.2e1 * L0 * x(10) * sin(x(5)) * cos(x(4)) * sin(x(4)) * m0 * n3p + 0.2e1 * (-(m0 + ml0) * (-G00 + n3) * sin(x(4)) / 0.2e1 + L0 * x(10) * x(9) * sin(x(5)) * m0) * (-G00 + n3)) * cos(x(5)) + 0.2e1 * L0 * x(10) ^ 2 * cos(x(4)) * sin(x(4)) * m0 * (-G00 + n3)) / (-G00 + n3) / cos(x(5)) / cos(x(4));

u3 = (L0 * cos(x(5)) ^ 4 * cos(x(4)) ^ 4 * m0 * n3pp - L0 * cos(x(5)) ^ 3 * m0 * (cos(x(5)) * sin(x(4)) * n2 - sin(x(5)) * n1) * cos(x(4)) ^ 3 + 0.3e1 * (x(9) ^ 2 * (-G00 + n3) * cos(x(5)) ^ 4 / 0.3e1 + ((x(10) ^ 2 + 0.2e1 / 0.3e1 * x(9) ^ 2) * n3 + (-x(10) ^ 2 - 0.2e1 / 0.3e1 * x(9) ^ 2) * G00 - n3pp / 0.3e1) * cos(x(5)) ^ 2 - 0.2e1 / 0.3e1 * x(10) * cos(x(5)) * sin(x(5)) * n3p - 0.2e1 / 0.3e1 * x(10) ^ 2 * (-G00 + n3)) * L0 * m0 * cos(x(4)) ^ 2 - 0.4e1 * (L0 * x(9) * cos(x(5)) * sin(x(4)) * m0 * n3p / 0.2e1 + (L0 * x(10) * x(9) * sin(x(5)) * sin(x(4)) * m0 - (m0 + ml0) * (-G00 + n3) / 0.4e1) * (-G00 + n3)) * cos(x(5)) * cos(x(4)) - 0.2e1 * L0 * x(9) ^ 2 * cos(x(5)) ^ 2 * m0 * (-G00 + n3)) / (-G00 + n3) / cos(x(5)) / cos(x(4));

u = [u1;u2;u3];
end
