g = 9.81; 
initial_velocity = 60; 
angle = 50; 
v0x = initial_velocity * cosd(angle); 
v0y = initial_velocity * sind(angle); 
time_of_flight = (2 * v0y) / g;
time_interval = 0.5;
t = 0;
x = 0; 
y = 0;
fprintf('Time     x           y\n');
while y >= 0 && t <= 9.0
    x = v0x * t;
    y = v0y * t - 0.5 * g * t^2;
    fprintf('%0.1f     %0.4f      %8.4f\n', t, x, y); % Adjusted format specifier for y
    t = t + time_interval;
end
