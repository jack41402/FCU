x = -2:0.2:2;
y = -1:0.1:1;   
[X, Y] = meshgrid(x, y);

Z = Zernike(X, Y);

mesh(x,y,Z)
surface(X, Y, Z)

function z = Zernike(x, y) 
q = sqrt(x.^2 + y.^2);
    a = atan2(y, x);
    z = 2 * q.^2 .* sin(a) .* cos(a);
end