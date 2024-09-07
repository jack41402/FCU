x = linspace(-2, 2, 21);
y = linspace(-1, 1, 21);
[x y] = Zernike(x, y)

Zernike = (2*(p.^2))*sin(theta);
[p, theta] = meshgrid(x, y);

figure;
mesh(X, Y, Zernike);
title('Mesh Plot of z(x,y)');
xlabel('x');
ylabel('y');
zlabel('z');

azimuth_angles = -180:180/10:180;
elevation_angle = 180/12;

figure;
surf(X, Y, Zernike);
xlabel('x');
ylabel('y');
zlabel('z');
title('Rotating Surface Plot of z(x,y)');
shading interp;

for az = azimuth_angles
    view(az, elevation_angle);
    pause(0.1);
end

