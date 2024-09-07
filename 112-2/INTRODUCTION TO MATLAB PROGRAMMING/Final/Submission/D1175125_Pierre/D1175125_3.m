x_vals = linspace(-2, 2, 21); 
y_vals = linspace(-1, 1, 21); 

[X, Y] = meshgrid(x_vals, y_vals);

theta = atan2(Y, X);
rho = sqrt(X.^2 + Y.^2);

Z = Zernike(theta, rho);

figure;
surf(X, Y, Z);
xlabel('X');
ylabel('Y');
zlabel('Z');
grid on;
view(3);

elevation_angle = 180 / 12;

for az = -180:180/10:180
    view([az, elevation_angle]);
    pause(0.1); 
end
