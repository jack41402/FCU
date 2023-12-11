v = 60 ;
rad = deg2rad(50) ;
x = @(t) v*cos(rad).*t ;
y = @(t) v*sin(rad).*t - 0.5*9.81.*t.^2 ;
t = 0 ;
fprintf("time horizontal distance vertical distance\n") ;
while y(t)>=0
    disp([t x(t)     y(t)])
    t = t + 0.5 ;
end

