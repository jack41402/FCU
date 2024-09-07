clc;
clear all;

% Data
x = (0:5)';
y = [20 25 27 28 27 25]';

% Fit a polynomial curve
n = 4; % Order of polynomial
fitType = fittype(['poly' num2str(n)]);
[curveFit, gof] = fit(x, y, fitType);%gof=goodness of fit

% Predict the value 
x_pred = 3.6;
y_pred = feval(curveFit, x_pred);

% Calculate fitted values
y_fit = feval(curveFit, x);

% Calculate SSE 
SSE = sum((y - y_fit).^2);

% R-square 
R_square = gof.rsquare;

% Display the results
y=y_pred
fprintf('SSE: %.6f\n', SSE);
fprintf('R-squared: %.4f\n', R_square);
