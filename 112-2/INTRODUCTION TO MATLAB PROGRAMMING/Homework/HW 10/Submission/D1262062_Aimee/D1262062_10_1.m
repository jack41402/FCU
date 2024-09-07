x = 0:pi/20:5*pi;
y1 = exp(-0.2*x) .* sin(2*x);
y2 = exp(-0.1*x) .* cos(4*x);

fig = figure;
plot(x, y1, 'b');
hold on;
plot(x, y2, 'r');
hold off;

xlabel('X-axis');
ylabel('Y-axis');
title('Question 1');

legend('function 1', 'function 2', 'Location', 'best');
grid on;

lines = findobj(fig, 'Type', 'Line');
set(lines(1), 'LineStyle', '-.', 'Color', [0 0 1], 'LineWidth', 2); % First plot settings
set(lines(2), 'LineStyle', '- -', 'Color', [1 0 1], 'LineWidth', 2); % Second plot settings
