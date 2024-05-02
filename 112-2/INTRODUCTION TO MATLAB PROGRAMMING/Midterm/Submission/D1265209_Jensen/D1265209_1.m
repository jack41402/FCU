an = -pi/2:pi/20:pi/2;
t = 0:0.2:4;
a1 = 5;
b1 = 2;

a = (exp(-0.2.*t).*sin(b1.*an)+log(t+1)).*(cos(2.*an)).^(2)

b2 = (((sin(a1.*t).^(-1))+log(t.^(2)+2.*t+1)).*tan(an/2));

b = roots(b2)


c = (exp(t)+sin(an))/b1