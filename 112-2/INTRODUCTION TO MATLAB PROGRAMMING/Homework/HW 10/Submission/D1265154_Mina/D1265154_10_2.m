clear all;
close all;
[x, y] = meshgrid(-2:0.1:2, -4:0.1:4);
z = 20 * y.^2 .* exp(-x.^2 - (0.5 * y.^2));
figure;
surf(x, y, z);
zlim([0 15]); 
zticks(0:5:15); 


