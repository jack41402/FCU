angle=-(pi/2):pi/20:pi/2;
t=0:0.2:4;
A=5;
B=2;


a=(exp(-0.2.*t).*sin(B.*angle)+log(t+1)).*(cos(2.*angle)).^2

b=(asin(A.*t)+log(t.^2+2*t+1)).*tan(angle/2)

c=(exp(t)+sin(angle))./B