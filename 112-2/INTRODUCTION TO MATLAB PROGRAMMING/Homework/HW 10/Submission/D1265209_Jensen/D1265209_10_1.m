a = @(x) exp(-0.2*x).*sin(2*x);
b = @(x) exp(-0.1*x).*cos(4*x);

x = 0:pi/20:5*pi;

figure; 
figure1 = plot(x, a(x), 'DisplayName', 'e^{-0.2x}sin(2x)');
hold on;
figure2 = plot(x, b(x), 'DisplayName', 'e^{-0.1x}cos(4x)');
hold off;
legend show
figure1.Color = 'Black'
figure1.LineStyle = '-'
figure1.LineWidth = 10
figure2.Color = 'Blue'
figure2.LineStyle = '--'
xlabel('x');
ylabel('Function value');
title('Quetion1');
handle = gcf
