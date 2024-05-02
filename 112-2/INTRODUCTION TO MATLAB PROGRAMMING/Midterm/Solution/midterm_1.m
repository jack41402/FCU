theta = -pi/2:pi/20:pi/2;
t = 0:0.2:4;
a = 5;
b = 2;

% (a)
(exp(-0.2.*t).*sin(b.*theta)+log(t+1)).*cos(2.*theta).^2

% (b)
(asin(a.*t)+log(t.^2+2.*t+1)).*tan(theta./2)

%(c)
(exp(t)+sin(theta))./b