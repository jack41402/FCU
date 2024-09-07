X = -2 : 0.1 : 2;
Y = -4 : 0.1 : 4;

[x,y]=meshgrid(X,Y);
z = 20 .* y.*y .* exp(-x.^2-0.5.*y.^2);

surf(x,y,z);