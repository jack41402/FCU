theta=[-pi/2:pi/20:pi/2];
t=[0:0.2:4];
a=5;
b=2;
c=(exp(-0.2.*t).*sin(b.*theta)+log(t+1)).*cos(2.*theta).^2
d=(asin(a.*t)+log(t.^2+t.*2+1)).*tan(theta/2)
e=(exp(t)+sin(theta))/b
