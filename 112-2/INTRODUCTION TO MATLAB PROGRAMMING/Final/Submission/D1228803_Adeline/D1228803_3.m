%D1228803_3

[x, y] = meshgrid(-2:0.2:2, -1:0.1:1);
p = sqrt(x.^2 + y.^2);
theta = atan(y./x);
Z = 2 * p.^2 * sin(theta).*cos(theta);

figure;
grid on;
mesh(Z);
figure;
grid on;
surface(x, y, Z);
%meshc(Z)
%plot3(x, y, Z);

%el = 15;

surface(x, y, Z) = view(-180:180/10:180, 180/12);

grid on;