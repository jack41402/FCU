x = 0 :pi/20 :5*pi;

f = @(x) exp(-0.2 .* x) .* sin(2 .* x);

plot(x,f(x));

hold on;

p = @(x) exp(-0.1 .* x) .* cos(4 .* x);

plot(x,p(x));

w = plot(x,f(x));
w.LineStyle = '--';
w. Color = 'm';
w. LineWidth = 3;

u = plot(x,p(x));
u. LineStyle = '-.';
u. Color = 'b';
u. LineWidth = 3;


title('Question 1');
xlabel('X-axis');
ylabel('Y-axis');