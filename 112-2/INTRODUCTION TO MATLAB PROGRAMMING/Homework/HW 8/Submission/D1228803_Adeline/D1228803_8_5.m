V0 = 60;
angle = 50;
g = 9.81; 

radius = deg2rad(angle);

V0X = V0 * cos(radius);
V0Y = V0 * sin(radius);

T = 0;

deltaX = 0;
deltaY = 0;

fprintf('time\t  x\t\t\t  y\n');

while deltaY >= 0
   
    deltaX = V0X * T;
    deltaY = V0Y * T - 0.5 * g * T^2;
    
    if deltaY >= 0
        if T >= 3
            fprintf('%.1f\t\t%.4f\t%.4f\n', T, deltaX, deltaY);
        else
        fprintf('%.1f\t\t%.4f\t\t%.4f\n', T, deltaX, deltaY);
        end
    end
    
    T = T + 0.5;
end
