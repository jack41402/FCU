func = @(x) 1 + exp(-0.2 * x) * sin(x + 2);
[xmin, ymin] = fminbnd(func, 0, 10);
fprintf("(x,y)=\n    %.4f %.4f\n", xmin, ymin);

x = linspace(0, 10, 400);
y = arrayfun(func, x);

func_param = @(x) 1 + exp(-0.2 * x) * sin(x + 2.5);
[xmin_param, ymin_param] = fminbnd(@(x) func_param(x), 0, 10);

fprintf("(x,y)=\n    %.4f %.4f\n", xmin_param, ymin_param);

figure;
fplot(func, [0 10], 'b');
hold on;
fplot(func_param, [0 10], 'r');
hold off;

xlabel('x');
ylabel('y');
grid on;