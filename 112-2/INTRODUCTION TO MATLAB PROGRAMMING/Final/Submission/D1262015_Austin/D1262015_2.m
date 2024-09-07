% Task 2: Curve Fitting
X = [0 1 2 3 4 5];
Y = [20 25 27 28 27 25];

% Best fitting with order n (choose n = 3 for example)
n = 4;
p = polyfit(X, Y, n);

% Predict the value at x = 3.6
x_pred = 3.6;
y_pred = polyval(p, x_pred);

% Calculate SSE and R-squared
Y_fit = polyval(p, X);
SSE = sum((Y - Y_fit).^2);
TSS = sum((Y - mean(Y)).^2);
R_square = 1 - SSE/TSS;

% Display results
fprintf('y = \n   %.4f\n', y_pred);
fprintf('SSE: %.6f\n', SSE);
fprintf('R-squared: %.4f\n', R_square);

% Comments on SSE and R-squared
% SSE indicates the sum of the squared differences between the observed and predicted values.
% R-squared represents the proportion of variance explained by the model.