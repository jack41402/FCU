% main.m

% Define x and y values
x_vals = linspace(-2, 2, 21); 
y_vals = linspace(-1, 1, 21); 
[X, Y] = meshgrid(x_vals, y_vals);
theta = atan2(Y, X);
rho = sqrt(X.^2 + Y.^2);
Z = Zernike(theta, rho);


figure;
mesh(X, Y, Z);
title('Mesh Plot of Zernike Function');
figure;
surf(X, Y, Z);
xlabel('X');
ylabel('Y');
zlabel('Z');
grid on;
view(3);



% Rotate the azimuth angle
for az = -180:180/10:180
    view([az, 180/12]);
    pause(0.1); % Pause to visualize the rotation
end
