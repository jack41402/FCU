x = 0:pi/20:5*pi;
y = exp(-0.2.*x).*sin(2.*x);
z = exp(-0.1.*x).*cos(4.*x);
a = plot(y)
hold on 
b = plot(z)
title('Question 1')
a.Color = 'green';
b.LineStyle = ":";
b.LineWidth = 4;
xlabel('X-axis')
ylabel('Y-axis')
legend
hold off

