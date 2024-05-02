s = (-pi/2):pi/20:(pi/2);
t = 0:0.2:4;
i = 1:10;
x = 5;
y = 2;
a = (exp(-0.2.*t).*sin(y.*s)+log(t+1)).*(cos(2.*s)).^2
b = (asin(x.*t)+log(t.^2+2.*t+1)).*tan(s./2)
c = (exp(t)+sin(s))./y






