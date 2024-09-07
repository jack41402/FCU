z = 2.*p.^2.*sin(u).*cos(u);
p = (x.^2+y.^2).^(0.5);
atan(y./x);
x = -2:0.2:2;
y= -1:0.1:1;
[x, y] =meshgrid(x, y);
surf(x, y, z)
c = Zernike(z,u)
view(-180:180/10:180);