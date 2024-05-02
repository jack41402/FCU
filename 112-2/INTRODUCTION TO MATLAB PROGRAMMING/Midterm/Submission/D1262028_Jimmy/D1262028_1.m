theta = (-pi/2):(pi/20):(pi/2);
t = 0:0.2:0.4;
A = 5;
B = 2;

%a
a = (exp(-0.2.*t).*sin(B.*theta) + log(t+1)).*cos(2.*theta)

%b
b = (asin(A.*t)+log(t.^2 + 2.*t + 1)).*tan(theta/2)

%c
c = (exp(t)+sin(theta))/B