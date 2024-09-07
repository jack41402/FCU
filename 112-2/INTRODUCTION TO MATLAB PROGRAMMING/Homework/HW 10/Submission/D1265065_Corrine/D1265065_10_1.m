% Define the range of x values
x = 0:pi/20:5*pi;

% Define the functions
y1 = exp(-0.2*x).*sin(2*x);
y2 = exp(-0.1*x).*cos(4*x);

% Plot the functions
fig = figure;
plot(x, y1, 'b', 'LineWidth', 2.5); % Plot y1 with blue color and thicker line
hold on; % Hold the current plot
plot(x, y2, 'r--', 'LineWidth', 2.5); % Plot y2 with red color and dashed line
hold off; % Release the hold on the plot

% (b) Edit mode to insert x-label, y-label, title, and legend
xlabel('X-axis');
ylabel('Y-axis');
title('Question 1');
legend('function1', 'function2', 'Location', 'best');
%legend=右上角圖例
%legend('show') legend('off')
% (c) Use Figure properties editor to change line properties
% You can do this manually in the figure window.

% (d) Use handle of the graphic object to change line properties
% Get handles to the lines
hLines = findobj(fig, 'Type', 'Line');

% Change line properties
set(hLines(1), 'Color', [0, 0, 1]); % Change y1 line color to light blue
set(hLines(2), 'Color', [1, 0, 1]);
set(hLines(1), 'LineStyle', '-.');
set(hLines(2), 'LineStyle', '--'); % Change y2 line style to dash-dot
