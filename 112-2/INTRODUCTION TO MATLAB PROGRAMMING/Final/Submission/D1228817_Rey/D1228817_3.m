x=-2:1/5:2;
y=-1:1/5:1;

[X, Y]=meshgrid(x, y);

Z=Zernike(X, Y);

mesh(X, Y, Z);
surf(X, Y, Z);

