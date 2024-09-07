y = 1;
t = 0;
fprintf("time      x           y\n");
while(1)
    x = 60.*cos(50./180.*pi).*t;
    if(60.*sin(50./180.*pi).*t - 0.5.*9.81.*t.^2<0)
        break
    else
        y = 60.*sin(50./180.*pi).*t - 0.5.*9.81.*t.^2;
        fprintf("%.1f %10.4f  %10.4f\n", t, x, y);
        t = t + 0.5;
    end    
end