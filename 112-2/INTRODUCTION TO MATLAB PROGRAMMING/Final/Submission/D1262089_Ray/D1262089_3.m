clc;
clear all;

x = linspace(-2, 2, 21);
y = linspace(-1, 1, 21);
[X, Y] = meshgrid(x, y);
elevation_angle = 180 / 12;
azimuth_angles = -180:180/10:180;

% Calculate z using the Zernike 
Z = Zernike(X, Y);

% plot the mesh
figure
mesh(X, Y, Z);

% Plot the surface and rotate
figure;
surf(X, Y, Z);
while true
    for azimuth_angle = azimuth_angles
        view(azimuth_angle, elevation_angle);
        pause(0.1);
    end
end












