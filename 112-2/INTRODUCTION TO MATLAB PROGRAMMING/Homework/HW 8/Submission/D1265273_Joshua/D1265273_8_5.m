g = 9.81;
a = 50;
x= @(t) v*cos(deg2rad(a))*t;
y= @(t) v*sin(deg2rad(a))*t - 0.5*g*(t^2);
v = 60;
t = 0;
fprintf('time  x      y\n')
while y(t)>=0
    fprintf('%3.1f  %3.4f  %3.4f\n', t, x(t), y(t))
    t = t+0.5;
end
