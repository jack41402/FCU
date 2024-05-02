fun = @(x) 1 + exp(-0.2*x) .* sin(x + 2);
x_values = linspace(0, 10, 1000); 
y_values = fun(x_values);

c = 2.5; 
fun_parametric = @(x) 1 + exp(-0.2*x) .* sin(x + c);
x_lower = 0;
x_upper = 10;


[x_min, y_min] = fminbnd(fun, x_lower, x_upper)
[x_min_parametric, y_min_parametric] = fminbnd(fun_parametric, x_lower, x_upper)

figure;
hold on;
fplot(fun, [0, 10]);
fplot(fun_parametric, [0, 10]);
scatter(x_min, y_min, 50, 'r', 'filled');
scatter(x_min_parametric, y_min_parametric, 50, 'r', 'filled'); 
xlabel('x');
ylabel('y');

legend('y = 1 + exp(-0.2x) * sin(x + 2)', 'y = 1 + exp(-0.2x) * sin(x + c) (c = 2.5)', 'Minimum Point (1)', 'Minimum Point (2)', 'Location', 'northwest');
hold off;


