C := Matrix(5, 5, [[0,0,0,0,-L*m__l*sin(beta(t))*diff(beta(t),t)],[0,0,0,L*m__l
*(cos(alpha(t))*diff(beta(t),t)*sin(beta(t))+diff(alpha(t),t)*sin(alpha(t))*cos
(beta(t))),L*m__l*(diff(alpha(t),t)*sin(beta(t))*cos(alpha(t))+diff(beta(t),t)*
cos(beta(t))*sin(alpha(t)))],[0,0,0,L*m__l*(sin(alpha(t))*diff(beta(t),t)*sin(
beta(t))-diff(alpha(t),t)*cos(alpha(t))*cos(beta(t))),L*m__l*(diff(alpha(t),t)*
sin(alpha(t))*sin(beta(t))-diff(beta(t),t)*cos(beta(t))*cos(alpha(t)))],[0,0,0,
-L^2*cos(beta(t))*m__l*sin(beta(t))*diff(beta(t),t),-L^2*cos(beta(t))*m__l*sin(
beta(t))*diff(alpha(t),t)],[0,0,0,L^2*cos(beta(t))*m__l*sin(beta(t))*diff(alpha
(t),t),0]]);
Dm := Matrix(5, 5, [[m+m__l,0,0,0,L*m__l*cos(beta(t))],[0,m+m__l,0,-L*cos(beta(
t))*cos(alpha(t))*m__l,L*m__l*sin(alpha(t))*sin(beta(t))],[0,0,m+m__l,-L*sin(
alpha(t))*cos(beta(t))*m__l,-L*m__l*cos(alpha(t))*sin(beta(t))],[0,-L*cos(beta(
t))*cos(alpha(t))*m__l,-L*sin(alpha(t))*cos(beta(t))*m__l,L^2*cos(beta(t))^2*
m__l,0],[L*m__l*cos(beta(t)),L*m__l*sin(alpha(t))*sin(beta(t)),-L*m__l*cos(
alpha(t))*sin(beta(t)),0,m__l*L^2]]);
G := Vector(5, [0,0,-(m+m__l)*g,L*cos(beta(t))*sin(alpha(t))*m__l*g,L*sin(beta(
t))*cos(alpha(t))*m__l*g]);
