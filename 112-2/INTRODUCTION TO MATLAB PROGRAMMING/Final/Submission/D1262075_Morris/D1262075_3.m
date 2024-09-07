[x y] = meshgrid(-2:0.2:2,-1:0.1:1 );
z = Zernike(x,y);
surf(z(x,y));
%mesh;