[x y] = meshgrid(-2:0.1:2,-4:0.1:4 );
z = 20.*y.^2.*exp(-x.^2-0.5.*y.^2);
surf(x,y,z);