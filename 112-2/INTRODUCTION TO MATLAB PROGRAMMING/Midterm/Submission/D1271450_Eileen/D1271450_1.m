D=[-pi/2:pi/20:pi/2];
t=[0:0.2:4];
a=5;
b=2;
A=(exp(-0.2*t).*sin(b*D)+log(t+1)).*(cos(2*D).*cos(2*D))
B=(((sin(a*t)).^(-1))+log((t.*t)+2*t+1)).*tan(D/2)
C=(exp(t)+sin(D))./b
