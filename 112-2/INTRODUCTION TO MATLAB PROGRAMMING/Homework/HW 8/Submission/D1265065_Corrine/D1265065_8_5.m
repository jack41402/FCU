
compute_projectile_motion();
function compute_projectile_motion()
    % Constants
    initial_velocity = 60; % m/s
    launch_angle = 50; % degrees
    g = 9.81; % acceleration due to gravity (m/s^2)
    
    % Convert launch angle to radians
    launch_angle_rad = deg2rad(launch_angle);
    
    % Calculate horizontal and vertical components of initial velocity
    v0x = initial_velocity * cos(launch_angle_rad);
    v0y = initial_velocity * sin(launch_angle_rad);
    
    % Initialize time and position variables
    t = 0;
    x = 0;
    y = 0;
    
    fprintf('time      x          y\n');
    % Loop until the projectile hits the ground
    while y >= 0
        fprintf('%.1f   %8.4f   %8.4f\n', t, x, y);
        % Compute time in the air
        t = t + 0.5;
        
        % Compute horizontal and vertical displacements
        x = v0x * t;
        y = v0y * t - 0.5 * g * t^2;
    end
end
