format short

theta = -pi/2:pi/20:pi/2;
t = 0:0.2:4;
x = 5;
y = 2;

a = (exp(-0.2.*t).*sin(y.*theta)+log(t+1)).*((cos(2.*theta)).^2)
z = (((sin(x.*t)).^(-1))+log((t.^2)+(2.*t)+1)).*(tan(theta./2));
b = complex(z)
c = (exp(t)+sin(theta))./y