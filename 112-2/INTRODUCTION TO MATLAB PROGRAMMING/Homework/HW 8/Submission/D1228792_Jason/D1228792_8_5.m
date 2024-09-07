x = 0;
y = 0;
time =0;
fprintf("time      x           y\n")
while(y >= 0)
    fprintf("%.1f %10.4f  %10.4f\n",time,x,y)
    time = time + 0.5;
    x = 60 .* cos(50 ./ 180 .* pi) .* time;
    y = 60 .* sin(50 ./ 180 .* pi) .* time + 1/2 .* -9.81 .* (time) .^ 2;
end

