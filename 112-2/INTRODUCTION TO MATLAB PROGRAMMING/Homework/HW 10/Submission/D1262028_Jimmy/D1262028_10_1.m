x = 0:pi/20:5*pi;
y1 = exp(-0.2*x) .* sin(2*x);
y2 = exp(-0.1*x) .* cos(4*x);

figure;
f1 = plot(x, y1, '-r', 'LineWidth', 1.5); 
hold on;
f2 = plot(x, y2, '--b', 'LineWidth', 1.5);
xlabel('X-axis'); 
ylabel('Y-axis'); 
title('Question 1'); 
legend('function 1', 'function 2'); 
hold off;

f1.LineStyle = ":";
f2.LineStyle = "--";
