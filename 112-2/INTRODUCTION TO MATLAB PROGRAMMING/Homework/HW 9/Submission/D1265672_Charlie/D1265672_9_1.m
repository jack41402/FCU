x = 0:pi/20:5*pi; 
y1 = exp(-0.2 * x) .* sin(2 * x); 
y2 = exp(-0.1 * x) .* cos(4 * x); 

figure;
h1 = plot(x, y1);
h1.Color='m'; 
h1.LineStyle='--'; 
h1.LineWidth=4;
hold on; 
h2 = plot(x, y2); 
hold off; 
h2.Color='blue'; 
h2.LineStyle='-.'; 
h2.LineWidth=4;

xlabel('X-axis'); 
ylabel('Y-axis'); 
title('Question 1');
legend('function 1', 'function 2'); 