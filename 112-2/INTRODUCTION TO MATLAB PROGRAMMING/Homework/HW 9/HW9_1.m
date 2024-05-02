x = 0:pi/20:5*pi;
y1 = @(x) exp(-0.2.*x).*sin(2.*x);
y2 = @(x) exp(-0.1.*x).*cos(4.*x);

% (a) plot figures
f = figure
figure1 = plot(x, y1(x));
hold on
figure2 = plot(x, y2(x));

% (b) x-label, y-label, title, legend
xlabel("X-axis")
ylabel("Y-axis")
title("Question 1")
legend("function1", "function2")

% (d) the handle of the graphic object
figure1.LineStyle = "--";
figure1.LineWidth = 2;
figure1.Color = "Red";

figure2.LineStyle = "-.";
figure2.LineWidth = 2;
figure2.Color = "Blue";

f = gcf; % Gets the handle to the current figure
lines = findobj(f, 'Type', 'Line'); % Find all line objects in the current figure
set(lines(2), 'Color', 'magenta'); % Change the color of the first plotted function assuming it's the second in the list
