x = 0 : pi/20 : 5*pi;
F1 = @(x) exp(-0.2.*x) .* sin(2.*x);
F2 = @(x) exp(-0.1.*x) .* cos(4.*x);
a = plot(x,F1(x))
hold on;
b = plot(x,F2(x))
a.Color = 'red';
b.LineStyle = "-";
b.LineWidth = 3;
xlabel('X')
ylabel('Y')
title('Question 1')
legend
hold off
