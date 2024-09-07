x = 0:pi/20:5 * pi;

y1 = exp(-0.2 * x).*sin(2 * x);
y2 = exp(-0.1 * x).*cos(4 * x)

figure;
plot(x, y1, '--m', 'LineWidth', 2); 
hold on; 
plot(x, y2, '-.b', 'LineWidth', 2);
hold off;

xlabel('X-axis');
ylabel('Y-axis');
title('Question 1');
legend('function1', 'function2');
ax = gca;
