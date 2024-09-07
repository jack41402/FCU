X = [0 1 2 3 4 5];
Y = [20 25 27 28 27 25];

n = 4;
p = polyfit(X, Y, n);

x_pred = 3.6;
y_pred = polyval(p, x_pred);
Y_fit = polyval(p, X);

SSE = sum((Y - Y_fit).^2);
TSS = sum((Y - mean(Y)).^2);
R_square = 1 - SSE/TSS;

fprintf('y = \n   %.4f\n', y_pred);
fprintf('SSE: %.6f\n', SSE);
fprintf('R-squared: %.4f\n', R_square);