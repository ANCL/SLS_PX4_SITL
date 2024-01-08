clc;clear;
%%
%translational 
p1_0 = 2;  p2_0 = 2; p3_0 = 0; 
v1_0 = 0;  v2_0 = 0; v3_0 = 0;

%Rotational
phi = 0; theta = 0; psi = 0;
omega1_0 = 0; omega2_0 = 0; omega3_0 = 0; 

% Pendulum
alpha_0 = 0*pi/180; beta_0 = 0*pi/180;
alpha_dt_0 = 0; beta_dt_0 = 0;

%Initial States
IC1= [p1_0;  p2_0;  p3_0;  alpha_0;  beta_0; phi; theta; psi; v1_0;  v2_0;  v3_0;  alpha_dt_0; beta_dt_0; omega1_0; omega2_0; omega3_0];

% Params of m_Q,m_L and L
M1 = [1.6, 0.16, 1];
M = [1.535, 0.1, 1];

%QSFA Control Gains Based on LQR
A6 = [0 1 0 0 0 0; 0 0 1 0 0 0 ; 0 0 0 1 0 0  ; 0 0 0 0 1 0 ; 0 0 0 0 0 1 ; 0 0 0 0 0 0];
B6 = [0;0;0;0;0;1];

A2 = [0 1;0 0];
B2 = [0;1];

Q0 = 10*diag(ones(6,1));
Q0(1,1) = 100000;Q0(2,2)=10000;Q0(3,3)=10000;
R0 = diag(0.01*ones(1,1));
Q = diag(ones(2,1));
Q(1,1) = 10;
R = diag(0.1*ones(1,1));
[Kv6,S,e] = lqr(A6,B6,Q0,R0);
[Kv2,S,e] = lqr(A2,B2,Q,R);

point = [0,0,0];

%%
%LQR Control Gains for the Linearized System
m=1.535;mp=0.1;L=1;G=10;J__1=0.03;J__2=0.03;J__3=0.03;
m0=M1(1);mp0=M1(2);L0=M1(3);
LinA = [0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1; 0 0 0 0 -G 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 G 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 -(m0 + mp0) * G / m0 / L0 0 (m0 + mp0) * G / m0 / L0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 -(m0 + mp0) * G / m0 / L0 0 (m0 + mp0) * G / m0 / L0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0; 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0;];

LinB = [0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; 0 0 0 0; -0.1e1 / (m0 + mp0) 0 0 0; 0 0 0 0; 0 0 0 0; 0 0.1e1 / J__1 0 0; 0 0 0.1e1 / J__2 0; 0 0 0 0.1e1 / J__3;];

[K,S,e] = lqr(LinA,LinB,diag(100*ones(16,1)),0.1*diag(ones(4,1)));

%%
%Sim for QSFA, LQR and DEA
tic
[t1,x1]=ode45(@(t,x)FullQuasi0(t,x,Kv2,Kv6,M1), [0,40],IC1);

toc
%%
%Load Position p_L for QSFA
h10 = [];
h20 = [];
h30 = [];
U0 = [];
for i = 1:size(x1)
h10 = [h10;x1(i,1) ];
h20 = [h20;x1(i,2) ];
h30 = [h30;x1(i,3) ];
U0 = [U0;QuasiController(x1(i,:),Kv2,Kv6,M1,point)'];
end
h0 = [h10,h20,h30];


%%
% Plot Control Input \ubar and \tau
h(3) = figure;
hold on;
plot(t1,U0(:,1),'r','LineWidth',2); set(gca,'LineWidth',2); box on; grid on;
xlim([0 8])
xlabel('time (s)')
ylabel('$\bar{u}$ (N)','Interpreter',"latex")


% saveas(h(3),'HControlInput','epsc')


%%
%Plot Confuguration States
h(4) = figure; hold on;
plot(t1,x1(:,1),'r','LineWidth',2); set(gca,'LineWidth',2); box on; grid on;
xlim([0 8])
xlabel('time (s)')
ylabel('$p_{L1}$ (m)','Interpreter',"latex")
