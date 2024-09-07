
% Part (a)
x = 0:pi/20:5*pi;
y1 = exp(-0.2*x) .* sin(2*x);
y2 = exp(-0.1*x) .* cos(4*x);

figure;
hold on;
line1=plot(x, y1, 'b', 'LineWidth', 1.5);
line2=plot(x, y2, 'r--', 'LineWidth', 1.5);
hold off;

% Part (b)
xlabel('X-axis');
ylabel('Y-axis');
legend('function 1', 'function 2');

% Part (c)

set(line1, 'Color', 'c', 'LineStyle', '--', 'LineWidth', 2); % Change line properties
set(line2, 'Color', 'b', 'LineStyle', '--', 'LineWidth', 2); % Change line properties

% Part (d)
line1.Color = 'm'; % Change color
line2.LineStyle = '-.'; % Change line style
line1.LineWidth = 1.2; % Change line width

