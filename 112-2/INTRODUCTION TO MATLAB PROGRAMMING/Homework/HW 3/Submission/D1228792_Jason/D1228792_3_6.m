c = 1000;
grid = @(x, y) ndgrid(-x : x/c : x, -y :y/c: y);
[x, y] = grid(15, 15);
z = sqrt(x.^2 + y.^2);
mesh(x, y, z)