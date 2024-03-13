t = 0:pi/500:pi;
X(1,:) = sin(t).*cos(5*t);
X(2,:) = sin(t).*cos(6*t);
X(3,:) = sin(t).*cos(10*t);

Y(1,:) = sin(t).*sin(2*t);
Y(2,:) = sin(t).*sin(3*t);
Y(3,:) = sin(t).*sin(5*t);

Z = cos(t);

plot3(X,Y,Z,"-.")