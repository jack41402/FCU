x = -2:0.1:2;
y = -4:0.1:4;
[x, y] = meshgrid(x, y);
Z = 20*y.^2 .* exp(-x.^2 - (0.5.*y.^2));
surf(X, Y, Z);