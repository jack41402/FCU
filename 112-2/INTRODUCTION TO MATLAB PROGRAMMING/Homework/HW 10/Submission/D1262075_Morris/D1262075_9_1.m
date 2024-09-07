a = @(x) exp(-0.2*x).*sin(2*x);
b = @(x) exp(-0.1*x).*cos(4*x);

x = 0:pi/20:5*pi;

figure; 
a = plot(x, a(x), 'DisplayName', 'function1');
hold on;
b = plot(x, b(x), 'DisplayName', 'function2' );
hold off;
a.Color = 'red';
a.LineStyle = ':';
a.LineWidth = 10;
b.Color = 'black';
b.LineStyle = '-';
b.LineWidth = 5;
legend show;
xlabel('x');
ylabel('Function value');
title('Quetion1');
handle = gcf
