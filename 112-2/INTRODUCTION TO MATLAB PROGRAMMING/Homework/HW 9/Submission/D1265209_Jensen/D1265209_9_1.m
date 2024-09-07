a = @(x) exp(-0.2*x).*sin(2*x);
b = @(x) exp(-0.1*x).*cos(4*x);

x = 0:pi/20:5*pi;

figure; 
plot(x, a(x), 'DisplayName', 'e^{-0.2x}sin(2x)', 'LineStyle', '-.');
hold on;
plot(x, b(x), 'DisplayName', 'e^{-0.1x}cos(4x)');
hold off;
legend show;
xlabel('x');
ylabel('Function value');
title('Plot of the functions e^{-0.2x}sin(2x) and e^{-0.1x}cos(4x)');
handle = gcf
