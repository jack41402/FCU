e = -pi/2:pi/20:pi/2;
t = 0:0.2:4;
B = 2;
A = 5;
a = [exp(-0.2.*t).*sin(B.*e)+reallog(t+1)].*cos(2.*e).*cos(2.*e)
b = [asin(A.*t)+reallog(t.^2+2.*t+1)].*tan(e/2)
c = (exp(t)+sin(e))/B
