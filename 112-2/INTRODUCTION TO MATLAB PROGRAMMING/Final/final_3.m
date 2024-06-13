% Define the x and y ranges
x = linspace(-2, 2, 21);
y = linspace(-1, 1, 21);

% (a) Create a meshgrid
[X, Y] = meshgrid(x, y);

% Calculate Z using the Zernike function
Z = Zernike(X, Y);

% (b) plot the surface
mesh(X, Y, Z);

% Define the elevation and azimuth angles
elevation_angle = 180 / 12;
azimuth_angles = linspace(-180, 180, 10);

% Rotate the surface plot
for azimuth_angle = azimuth_angles
    view(azimuth_angle, elevation_angle);
    pause(0.5); % Pause to visualize the rotation
end