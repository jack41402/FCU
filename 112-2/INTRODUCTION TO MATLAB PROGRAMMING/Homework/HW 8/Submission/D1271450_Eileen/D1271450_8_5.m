initial_velocity = 60;
launch_angle_deg = 50;
launch_angle_rad = deg2rad(launch_angle_deg);
gravity = 9.81;
time_interval = 0.5;
time = 0;
x = 0;
y = 0;
fprintf('time       x           y \n');
while y >= 0 && time < 9.5
    x_velocity = initial_velocity * cos(launch_angle_rad);
    y_velocity = initial_velocity * sin(launch_angle_rad) - gravity * time;
    x = x_velocity * time;
    y = initial_velocity * sin(launch_angle_rad) * time - 0.5 * gravity * time^2;
    fprintf('%.1f   %9.4f   %9.4f\n', time, x, y);
    time = time + time_interval;
end
