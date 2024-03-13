t = 0:pi/40:pi;
X(1,:) = sin(t).*cos(10*t);
X(2,:) = sin(t).*cos(12*t);
X(3,:) = sin(t).*cos(20*t);

Y(1,:) = sin(t).*sin(10*t);
Y(2,:) = sin(t).*sin(12*t);
Y(3,:) = sin(t).*sin(20*t);
Z = cos(t);
plot3(X,Y,Z,"--")