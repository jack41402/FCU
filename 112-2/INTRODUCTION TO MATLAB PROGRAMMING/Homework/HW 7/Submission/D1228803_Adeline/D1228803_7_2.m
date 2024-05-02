f = @(x) 1 + exp(-0.2*x) * sin(x + 2);
[x_min, y_min] = fminbnd(f, 0, 10);
fprintf('(x, y) = \n(%.4f, %.4f)\n', x_min, y_min);

fplot(f, [0, 10]);
hold on;
title('Plot of y = 1 + exp(-0.2*x) * sin(x + 2)');
xlabel('x');
ylabel('y');
grid on;

f_parametric = @(x, c) 1 + exp(-0.2*x) * sin(x + c);
c = 2.5;
[x_min_parametric, y_min_parametric] = fminbnd(@(x) f_parametric(x, c), 0, 10);
fprintf('(x, y) =\n (%.4f, %.4f)\n', x_min_parametric, y_min_parametric);
fplot(@(x) f_parametric(x, c), [0, 10], 'Color', [1, 0.5, 0]);
title(['Plot of y = 1 + exp(-0.2*x) * sin(x + ' num2str(c) ')']);
xlabel('x');
ylabel('y');
grid on;