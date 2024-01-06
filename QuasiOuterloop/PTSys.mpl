sysf := Matrix(10, 1, [[v__1],[v__2],[v__3],[gamma__alpha],[gamma__beta],[L*
m__l*sin(beta)*(cos(beta)^2*gamma__alpha^2+gamma__beta^2)/(m+m__l)],[-cos(beta)
*sin(alpha)*(cos(beta)^2*gamma__alpha^2+gamma__beta^2)*L*m__l/(m+m__l)],[(L*cos
(beta)*cos(alpha)*m__l*(cos(beta)^2*gamma__alpha^2+gamma__beta^2)+(m+m__l)*G00)
/(m+m__l)],[2*gamma__beta*gamma__alpha*sin(beta)/cos(beta)],[-cos(beta)*sin(
beta)*gamma__alpha^2]]);
sysg1 := Vector(10, [0,0,0,0,0,(m__l*cos(beta)^2+m)/m/(m+m__l),m__l*sin(beta)*
cos(beta)*sin(alpha)/m/(m+m__l),-cos(beta)*cos(alpha)*sin(beta)*m__l/m/(m+m__l)
,0,-cos(beta)/m/L]);
sysg2 := Vector(10, [0,0,0,0,0,m__l*sin(beta)*cos(beta)*sin(alpha)/m/(m+m__l),(
(m__l*cos(alpha)^2-m__l)*cos(beta)^2+m+m__l)/m/(m+m__l),cos(alpha)*sin(alpha)/m
*cos(beta)^2*m__l/(m+m__l),cos(alpha)/L/m/cos(beta),-sin(beta)*sin(alpha)/m/L])
;
sysg3 := Vector(10, [0,0,0,0,0,-cos(beta)*cos(alpha)*sin(beta)*m__l/m/(m+m__l),
cos(alpha)*sin(alpha)/m*cos(beta)^2*m__l/(m+m__l),(-cos(alpha)^2*cos(beta)^2*
m__l+m+m__l)/m/(m+m__l),sin(alpha)/L/m/cos(beta),sin(beta)*cos(alpha)/m/L]);
u__1 := ((cos(alpha)*L*(cos(alpha)^2*n3pp-cos(alpha)*sin(alpha)*n__2+
gamma__alpha^2*(-G00+n__3))*m*cos(beta)^3+3*L*gamma__beta^2*cos(alpha)*m*(-G00+
n__3)*cos(beta)+(-G00+n__3)^2*(m+m__l))*sin(beta)+2*cos(beta)^2*(-1/2*cos(beta)
^2*cos(alpha)^2*n__1+gamma__beta*(cos(alpha)*n3p+gamma__alpha*sin(alpha)*(-G00+
n__3)))*L*m)/(-G00+n__3)/cos(beta)/cos(alpha);
u__2 := (-cos(alpha)*L*m*(cos(alpha)^3*n__2+cos(alpha)^2*sin(alpha)*n3pp-n__2*
cos(alpha)+gamma__alpha^2*sin(alpha)*(-G00+n__3))*cos(beta)^4-L*cos(alpha)^2*
cos(beta)^3*sin(beta)*sin(alpha)*m*n__1-3*((2/3*n3p*gamma__alpha+1/3*n__2)*cos(
alpha)+(-G00+n__3)*(gamma__beta^2+2/3*gamma__alpha^2)*sin(alpha))*cos(alpha)*L*
m*cos(beta)^2+(-4*L*gamma__beta*gamma__alpha*sin(beta)*m*(-G00+n__3)*cos(alpha)
^2+2*L*gamma__beta*sin(beta)*cos(alpha)*sin(alpha)*m*n3p+2*(-G00+n__3)*(-1/2*(m
+m__l)*(-G00+n__3)*sin(alpha)+L*gamma__beta*gamma__alpha*sin(beta)*m))*cos(beta
)+2*L*gamma__beta^2*cos(alpha)*sin(alpha)*m*(-G00+n__3))/(-G00+n__3)/cos(beta)/
cos(alpha);
u__3 := (L*cos(alpha)^4*cos(beta)^4*m*n3pp-L*cos(beta)^3*m*(cos(beta)*sin(alpha
)*n__2-sin(beta)*n__1)*cos(alpha)^3+3*(1/3*gamma__alpha^2*(-G00+n__3)*cos(beta)
^4+((gamma__beta^2+2/3*gamma__alpha^2)*n__3+(-gamma__beta^2-2/3*gamma__alpha^2)
*G00-1/3*n3pp)*cos(beta)^2-2/3*gamma__beta*cos(beta)*sin(beta)*n3p-2/3*
gamma__beta^2*(-G00+n__3))*L*m*cos(alpha)^2-4*cos(beta)*(1/2*L*gamma__alpha*cos
(beta)*sin(alpha)*m*n3p+(-G00+n__3)*(L*gamma__beta*gamma__alpha*sin(beta)*sin(
alpha)*m-1/4*(m+m__l)*(-G00+n__3)))*cos(alpha)-2*L*gamma__alpha^2*cos(beta)^2*m
*(-G00+n__3))/(-G00+n__3)/cos(beta)/cos(alpha);
Ts := Vector(10, [p__1+L*sin(beta),v__1+gamma__beta*L*cos(beta),-sin(beta)*(G00
-n__3)/cos(beta)/cos(alpha),((n3p*cos(beta)*sin(beta)-gamma__beta*(G00-n__3))*
cos(alpha)-sin(alpha)*gamma__alpha*cos(beta)*sin(beta)*(G00-n__3))/cos(alpha)^2
/cos(beta)^2,p__2-L*sin(alpha)*cos(beta),v__2-gamma__alpha*L*cos(alpha)*cos(
beta)+gamma__beta*L*sin(alpha)*sin(beta),sin(alpha)*(G00-n__3)/cos(alpha),(-n3p
*sin(alpha)*cos(alpha)+gamma__alpha*(G00-n__3))/cos(alpha)^2,p__3+L*cos(alpha)*
cos(beta),v__3-gamma__alpha*L*sin(alpha)*cos(beta)-gamma__beta*L*cos(alpha)*sin
(beta)]);
