v0 = 60;
angle = 50;
g = 9.81; 

angle_rad = deg2rad(angle);

v0x = v0 * cos(angle_rad);
v0y = v0 * sin(angle_rad);

total_time = (2 * v0y) / g;

time_interval = 0.5;

time = 0;
x = 0;
y = 0;

fprintf('time\t  x\t\t\t  y\n');

while time <= total_time
    x = v0x * time;
    y = v0y * time - 0.5 * g * time^2;
    fprintf('%.1f\t%10.4f\t%10.4f\n', time, x, y);
    time = time + time_interval;
end
