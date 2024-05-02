c = 100;
grid = @(x, y) ndgrid(-x:x/c:x, -y:y/c:y);
[x, y] = grid(10,10);
z = sqrt(x.^2 + y.^2);
mesh(x, y, z)