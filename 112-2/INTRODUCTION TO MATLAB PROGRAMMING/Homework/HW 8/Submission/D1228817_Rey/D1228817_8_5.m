x=0;
y=0;
time=0;
v0=60;

fprintf("time       x            y\n");
while y>=0

    fprintf("%.1f       %.4f      %4.4f\n", time, x, y);
    time=time+0.5;
    y=(v0*sin(deg2rad(50)))*time-0.5*(9.8*(time^2));
    x=(v0*time*cos(deg2rad(50)));
end
