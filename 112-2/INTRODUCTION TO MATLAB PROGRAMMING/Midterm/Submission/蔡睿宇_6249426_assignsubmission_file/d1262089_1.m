clear all
clc
x=-pi/2:pi/20:pi/2;
t=0:0.2:4;
a=5;
b=2;
%(a)
f=@(x,t) (exp(-0.2.*t).*sin(b.*x)+log(t+1)).*cos(2*x).^2;
f(x,t)
%(b)
g=@(x,t) (asin(a.*t)+log(t.^2+2.*t+1)).*tan(x/2);
g(x,t)
%(c)
h=@(x,t) (exp(t)+sin(x))./b;
h(x,t)



