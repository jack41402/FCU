x = 0:pi/20:5*pi;
y = exp(-0.2.*x).*sin(2.*x);
z = exp(-0.1.*x).*cos(4.*x);
a = plot(y)
hold on
b = plot(z)
a.Color = 'Blue';
b.LineStyle ='--';
a.LineWidth = 2;
xlabel('X-axis')
ylabel('Y-axis')
legend('function1', 'function2')
hold off