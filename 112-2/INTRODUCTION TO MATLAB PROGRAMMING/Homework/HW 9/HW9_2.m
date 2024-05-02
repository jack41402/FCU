x = -2:0.1:2;
y = -4:0.1:4;
z = @(x, y) 20.*y.^2.*exp(-x.^2-0.5.*y.^2);

[X, Y] = meshgrid(x, y);
Z = z(X, Y);
surf(X, Y, Z)