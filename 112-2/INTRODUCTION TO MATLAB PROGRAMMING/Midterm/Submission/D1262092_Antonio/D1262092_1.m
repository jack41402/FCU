angle=-pi/2:pi/20:pi/2;
t=0:0.2:4;
A=5;
B=2;
%(a)
a=(2.71828182.^(-0.2*t).*sin(B*angle)+log(t+1)).*cos(2*angle).^2
%(b)
b=(sin(A.*t)+log(t.^2+2*t+1)).*tan(angle./2)
%(c)
c=(2.71828182.^t+sin(angle))/B
