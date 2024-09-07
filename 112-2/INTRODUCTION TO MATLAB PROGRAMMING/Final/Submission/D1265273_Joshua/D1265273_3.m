clear all;
x = -2:4/21:2;
y = -1:2/21:1;
[X, Y] = meshgrid(x, y);
z = Zernike(X, Y);
surf(x,y,z)

mesh(x,y,z)

%view(180/10, 180/12);