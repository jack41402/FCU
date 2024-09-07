v0 = 60; 
theta = 50;
g = 9.81; 
theta_rad = deg2rad(theta); 
T = 2 * v0 * sin(theta_rad) / g;

t = 0:0.5:T;

x = v0 * cos(theta_rad) * t;
y = v0 * sin(theta_rad) * t - 0.5 * g * t.^2;

disp('time         x          y');
for i = 1:length(t)
    fprintf('%.1f %10.4f %10.4f\n', t(i), x(i), y(i));
end
