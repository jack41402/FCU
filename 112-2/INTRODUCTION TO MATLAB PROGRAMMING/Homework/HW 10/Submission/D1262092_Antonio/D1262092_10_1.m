% (a) 
x = 0:pi/20:5*pi;
y1 = sin(2*x).*exp(-0.2*x);
y2 = cos(4*x).*exp(-0.1*x);
figure;
hold on;
plot(x, y1, 'DisplayName', 'fuction1');
plot(x, y2, 'DisplayName', 'function2');
hold off;

% (b)
xlabel('X-axis');
ylabel('Y-axis');
title('Question1');

% (c) 
h = get(gca, 'Children');
set(h(1), 'Color', 'b', 'LineStyle', '--', 'LineWidth', 2);
set(h(2), 'Color', 'r', 'LineStyle', ':', 'LineWidth', 1.5);

% (d) 
legend show;