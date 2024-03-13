t = 20:1000/100:1000*pi;
xt = (5 + cos(sqrt(90)*t)).*cos(t);
yt = sin(sqrt(32) * t);
zt = (5 + cos(sqrt (30)*t)).*sin(t);
p = plot3(xt,yt,zt)
axis equal
xlabel('x(t)')
ylabel('y(t)')
zlabel('z(t)')
p.LineStyle = "--"