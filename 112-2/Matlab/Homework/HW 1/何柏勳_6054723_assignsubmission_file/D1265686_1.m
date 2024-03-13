t = 0:pi/500:40*pi;
xt = (5 + sin(sqrt(32)*t)).*cos(t);
yt = sin(sqrt(32) * t);
zt = (3 + cos(sqrt(32)*t)).*sin(t);

plot3(xt,yt,zt,"-.")
axis equal
xlabel('x(t)')
ylabel('y(t)')
zlabel('z(t)')
