x = -2 : 0.4 : 2;
y = -1 : 0.2 : 1;
[X,Y] = meshgrid(x,y);
p = (X.^2 + Y.^2).^0.5;
seta = atan(Y./X);
z = 2.*p.^2.*sin(seta).*cos(seta);
surf(x,y,z)
view([-180,180], 15)