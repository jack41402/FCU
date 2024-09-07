clear all;
close all;
[x, y] = meshgrid(-2:21:2,-1:21:1);
a=atan2(x,y);
z = 2 * (sqrt(x.^2+y.^2).^2).*(sin(tan(y./x).^(-1)).*cos(tan(y./x).^(-1)));
figure;
view(-180,180)
figure, meshc(z)
figure, surfc(z)




