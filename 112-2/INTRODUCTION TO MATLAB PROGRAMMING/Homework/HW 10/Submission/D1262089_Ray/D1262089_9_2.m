% Define the grid
[x, y] = meshgrid(-2:0.1:2, -4:0.1:4);

% Define the function
z = 20 .* y.^2 .* exp(-x.^2 - 0.5 * y.^2);

% Plot the surface
surf(x, y, z);

