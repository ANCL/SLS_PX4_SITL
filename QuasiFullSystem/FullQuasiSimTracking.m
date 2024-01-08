clc;clear;
%%
%Reference trajecotry
T = 16; t = linspace(0,10*T,1000);
T = 16;r1 = 3; r2 = 1.5; r3=0.5;
TParam = [100,3,1.5,0.5];
p1r = r1*sin(2*pi*t/T);
p2r = r2*sin(4*pi*t/T);
p3r = -9 + r3*sin(2*pi*t/T);

%translational 
p1_0 = 1;  p2_0 = 1; p3_0 = -9; 
% v1_0 = r1*2*pi/T;  v2_0 = r2*4*pi/T; v3_0 = r3*2*pi/T;
v1_0 = 0;  v2_0 = 0; v3_0 = 0;

%Rotational
phi = 0; theta = 0; psi = 0;
omega1_0 = 0; omega2_0 = 0; omega3_0 = 0; 

% Pendulum
alpha_0 = 0*pi/180; beta_0 = 0;
alpha_dt_0 = 0; beta_dt_0 = 0;

%Initial States for UAV SLS
IC1= [p1_0;  p2_0;  p3_0;  alpha_0;  beta_0; phi; theta; psi; v1_0;  v2_0;  v3_0;  alpha_dt_0; beta_dt_0; omega1_0; omega2_0; omega3_0];

M1 = [1.6, 0.16, 1];

A6 = [0 1 0 0 0 0; 0 0 1 0 0 0 ; 0 0 0 1 0 0  ; 0 0 0 0 1 0 ; 0 0 0 0 0 1 ; 0 0 0 0 0 0];
B6 = [0;0;0;0;0;1];

A2 = [0 1;0 0];
B2 = [0;1];

Q0 = 10*diag(ones(6,1));
Q0(1,1) = 100;Q0(2,2)=100;Q0(3,3)=10;
R0 = diag(ones(6,1));

Q = 5*diag(ones(2,1));
R = diag(ones(1,1));
[Kv6,S,e] = lqr(A6,B6,Q0,R);
[Kv2,S,e] = lqr(A2,B2,Q,R);

%%
%Sim for QSFA and DEA
[t1,x1]=ode45(@(t,x)FullQuasi1(t,x,Kv2,Kv6,M1), [0,40],IC1);

%Load Position p_L for QSFA
h10 = [];
h20 = [];
h30 = [];
U0 = [];
for i = 1:size(x1)
h10 = [h10;x1(i,1) ];
h20 = [h20;x1(i,2) ];
h30 = [h30;x1(i,3) ];
U0 = [U0;QuasiControllerTrack(x1(i,:),t1(i),Kv2,Kv6,M1,TParam)'];
end
h0 = [h10,h20,h30];

%%
% Plot Tracking Errors

h(2) = figure;  hold on;

plot(t1,h0(:,1)-(r1*sin(2*pi*t1/T) + 1),'r','LineWidth',2);set(gca,'LineWidth',2); box on; grid on; 
xlim([0 40])
xlabel('time (s)')
ylabel('$p_{L1}-y_{r1}$ (m)','Interpreter',"latex")


%%
% Plot Control Input \ubar and \tau
h(3) = figure;

hold on;
plot(t1,U0(:,1),'r','LineWidth',2); set(gca,'LineWidth',2); box on; grid on;
xlim([0 40])
xlabel('time (s)')
ylabel('$\bar{u}$ (N)','Interpreter',"latex")


%%
%Plot Confuration States
h(4) = figure; hold on;

plot(t1,x1(:,1),'r','LineWidth',2); set(gca,'LineWidth',2); box on; grid on;
xlim([0 40])
xlabel('time (s)')
ylabel('$p_{L1}$ (m)','Interpreter',"latex")
