z = @(x , y) x.^2 - y.^2 ;
[x , y] = meshgrid(0:0.25:5) ;
figure
mesh(z(x , y))