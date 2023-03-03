% 定義方程式
f1 = @(x) exp(-x).*cos(x);
f2 = @(x) exp(-x).*sin(x);
f3 = @(x) sin(x)./(x+1);
f4 = @(x) 4*cos(x) + 3*sin(x);

% 繪製 y = e^(-x)cos(x)
x = -pi:pi/10:pi;
y1 = f1(x);
plot(x, y1);
title('y = e^{-x}cos(x)');

% 繪製 y = e^(-x)sin(x)
y2 = f2(x);
figure;
plot(x, y2);
title('y = e^{-x}sin(x)');

% 繪製 y = sin(x)/(x+1)
y3 = f3(x);
figure;
plot(x, y3);
title('y = sin(x)/(x+1)');

% 繪製 y = 4cos(x) + 3sin(x)
y4 = f4(x);
figure;
plot(x, y4);
title('y = 4cos(x) + 3sin(x)');
