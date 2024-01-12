sysf := Matrix(16, 1, [[v__1],[v__2],[v__3],[gamma__alpha],[gamma__beta],[(sin(
phi)*sin(theta)*omega__2+cos(phi)*sin(theta)*omega__3+omega__1*cos(theta))/cos(
theta)],[cos(phi)*omega__2-sin(phi)*omega__3],[(sin(phi)*omega__2+cos(phi)*
omega__3)/cos(theta)],[-L*sin(beta)*m*(cos(beta)^2*gamma__alpha^2+gamma__beta^2
)/(m+m__p)],[cos(beta)*sin(alpha)*m*(cos(beta)^2*gamma__alpha^2+gamma__beta^2)*
L/(m+m__p)],[1/(m+m__p)*(-L*cos(beta)^3*cos(alpha)*m*gamma__alpha^2-L*cos(beta)
*cos(alpha)*m*gamma__beta^2+G*m+G*m__p)],[2*gamma__beta*gamma__alpha*sin(beta)/
cos(beta)],[-gamma__alpha^2*cos(beta)*sin(beta)],[-omega__2*omega__3*(J__2-J__3
)/J__1],[omega__1*omega__3*(J__1-J__3)/J__2],[-omega__1*omega__2*(J__1-J__2)/
J__3]]);
sysg := Matrix(16, 4, [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0
,0],[0,0,0,0],[0,0,0,0],[(sin(beta)*cos(beta)*sin(alpha)*cos(phi)*sin(theta)*
sin(psi)-sin(beta)*cos(beta)*cos(alpha)*cos(phi)*cos(theta)-sin(beta)*cos(beta)
*sin(alpha)*cos(psi)*sin(phi)+cos(beta)^2*cos(phi)*sin(theta)*cos(psi)+cos(beta
)^2*sin(phi)*sin(psi)-cos(phi)*sin(theta)*cos(psi)-sin(phi)*sin(psi))/(m+m__p),
0,0,0],[1/(m+m__p)*cos(beta)*(cos(beta)*cos(alpha)^2*cos(phi)*sin(theta)*sin(
psi)+sin(beta)*sin(alpha)*cos(phi)*sin(theta)*cos(psi)-cos(beta)*cos(alpha)^2*
cos(psi)*sin(phi)+cos(beta)*cos(alpha)*sin(alpha)*cos(phi)*cos(theta)+sin(beta)
*sin(alpha)*sin(psi)*sin(phi)-cos(beta)*cos(phi)*sin(theta)*sin(psi)+cos(beta)*
cos(psi)*sin(phi)),0,0,0],[-1/(m+m__p)*cos(beta)*cos(alpha)*(-cos(beta)*sin(
alpha)*cos(phi)*sin(theta)*sin(psi)+sin(beta)*cos(phi)*sin(theta)*cos(psi)+cos(
beta)*cos(alpha)*cos(phi)*cos(theta)+cos(beta)*sin(alpha)*cos(psi)*sin(phi)+sin
(beta)*sin(psi)*sin(phi)),0,0,0],[(-cos(alpha)*cos(phi)*sin(theta)*sin(psi)+cos
(alpha)*cos(psi)*sin(phi)-sin(alpha)*cos(phi)*cos(theta))/L/cos(beta)/m,0,0,0],
[(((cos(phi)*sin(theta)*sin(psi)-sin(phi)*cos(psi))*sin(alpha)-cos(theta)*cos(
alpha)*cos(phi))*sin(beta)+cos(beta)*(cos(phi)*sin(theta)*cos(psi)+sin(phi)*sin
(psi)))/m/L,0,0,0],[0,1/J__1,0,0],[0,0,1/J__2,0],[0,0,0,1/J__3]]);
