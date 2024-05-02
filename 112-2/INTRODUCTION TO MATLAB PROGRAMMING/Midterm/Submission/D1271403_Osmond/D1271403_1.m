h = -pi/2:pi/20:pi/2;
t= 0:0.2:4;
A = 5;
B = 2;
a = (exp(-0.2*t).*sin(h*B)+ln(t+1)).*(cos(2*h)).^2
b = ((sin(A*t)).^(-1)+ln(t.^2+2*t+1)).*tan(h/2)
c = (exp(t)+sin(h))/B