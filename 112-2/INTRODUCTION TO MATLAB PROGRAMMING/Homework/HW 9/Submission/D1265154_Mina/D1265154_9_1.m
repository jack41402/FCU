clear all; close all;
x = 0:pi/20:4*pi;
plot(x, exp(-0.2*x) .* sin(2*x), '--r')
hold on
plot(x, exp(-0.1*x) .* cos(4*x), '--b')  
hold off
a = get(gca, 'child');
a(2).LineStyle = '--';
a(2).LineWidth = 2.0;
title('Question 1');
xlabel('X-axis');
ylabel('Y-axis');
legend('Function 1', 'Function 2');
set(a(2), 'Color', 'magenta'); 
