theta = -pi/2 : pi/20 : pi/2;
t = 0:0.2:4;
a = 5;
b = 2;
A = ((exp(-0.2.*t)).*sin(b*theta)+reallog(t+1)).*(cos(2.*theta)).^2
B = ((sin(a.*t)).^-1 + reallog(sqrt(t) + 2.*t +1)).*tan(theta./2)
C = (exp(t) + sin(theta))./b