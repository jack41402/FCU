v=60;
ang=50*pi/180;
g=9.81;
t=0;
y=0;
fprintf("time      x          y   \n")
while y>=0
    vx=v*cos(ang);
    vy=v*sin(ang);
    y=vy*t-0.5*g*(t^2);
    if y>=0
        fprintf("%.1f  %9.4f  %9.4f\n", t, vx*t, y)
    end
    t=t+0.5;
end