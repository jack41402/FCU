x = -2:0.1:2;
y = -4:0.1:4;
[X,Y] = meshgrid(x,y);
Z = 20 .* Y.^2 .* exp(-X.^2 - 0.5 .* Y.^2);
surf(x,y,Z);