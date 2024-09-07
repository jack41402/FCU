[x, y] = meshgrid(-2:0.1:2, -4:0.1:4);

z = 20 .* y.^2 .* exp((-x.^2) - 0.5 .* y.^2);

surf(z);

title('Surface Plot of z = 20y^2e^{-x^2} - 0.5y^2');