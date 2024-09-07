% Define the range of x and y values
x = -2:0.1:2;
y = -4:0.1:4;

% Create a grid of points
[X, Y] = meshgrid(x, y);

% Define the function
Z = 20 .* Y.^2 .* exp(-(X.^2) - 0.5*(Y.^2));

% Plot the surface
figure;
surf(X, Y, Z);
