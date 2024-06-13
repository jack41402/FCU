x = 0 : 0.0004 : 1;
B1 = @(x) 1*x.^(0);
B2 = @(x) 1 + x;
B3 = @(x) 1 + 3.*x + x.^2;
B4 = @(x) 1 + 6.*x + 7.*x.^2 + x.^3;

plot(x, B1(x), '-', 'DisplayName', 'B1(x)'); hold on
plot(x, B2(x), '--', 'DisplayName', 'B2(x)') 
plot(x, B3(x), ':', 'DisplayName', 'B3(x)') 
plot(x, B4(x), '-.', 'DisplayName', 'B4(x)')
legend show

handle_B3 = findobj('DisplayName', 'B3(x)');
set(handle_B3, 'Color', 'm');    % Change color to magenta
set(handle_B3, 'LineWidth', 2);  % Change line width to 2
set(handle_B3, 'LineStyle', '-');% Change line type to solid