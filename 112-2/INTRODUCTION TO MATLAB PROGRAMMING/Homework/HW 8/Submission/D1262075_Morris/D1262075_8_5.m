initial_velocity = 60; 
launch_angle = 50; 
g = 9.81;
theta = deg2rad(launch_angle);
v0x = initial_velocity * cos(theta);
v0y = initial_velocity * sin(theta);
t_flight = (2 * v0y) / g;
time_interval = 0.5;
t = 0;
fprintf('Time\t\t x \t\t    y\n')
while t <= t_flight
    x = v0x * t;
    y = v0y * t - 0.5 * g * t^2;
    fprintf('%.4f \t%8.4f \t%8.4f\n', t, x, y)
    t = t + time_interval;
end
