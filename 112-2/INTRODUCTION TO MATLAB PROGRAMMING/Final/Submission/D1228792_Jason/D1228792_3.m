close all;clear all;
tiledlayout(1,2)
[x ,y] = meshgrid(-2:0.2:2,-1:0.1:1);
z = Zernike(x,y);
ax1 = nexttile;
surf(x,y,z);
view([180 12]);
ax2 = nexttile;
mesh(x,y,z);

