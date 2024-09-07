x=0;
y=0;
v0=60;
time=0;
angle=deg2rad(50);

while y>=0
    fprintf("%.1f  %.4f  %.4f\n",time, x, y);
    time = time + 0.5;
    x = v0.*cos(angle).*time;
    y = v0.*sin(angle).*time-1/2.*9.81.*(time).^2;
end
