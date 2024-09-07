T = [273, 278, 283, 288, 293, 298];
P = [4.579, 6.543, 9.209, 12.788, 17.535, 23.756];
X = 1./ T;
Y = log(P);
fit_result = polyfit(X, Y, 2);
a = fit_result(1);
b = fit_result(2);
c = fit_result(3);
T_fit = linspace(min(T), max(T), 100);
X_fit = 1 ./ T_fit;
Y_fit = a * X_fit.^2 + b * X_fit + c;
P_fit = exp(Y_fit);
figure;
plot(T, P, '.', 'MarkerSize', 8, 'DisplayName', 'Data'); % Original data points
hold on;
plot(T_fit, P_fit, '-', 'LineWidth', 0.5, 'DisplayName', 'Polynomial Fit'); % Polynomial curve
legend('data', 'fitted curve');
xlabel('x');
ylabel('y');
format short;
T_estimate = [284.9532, 299.7083];
X_estimate = 1 ./ T_estimate;
Y_estimate = a * X_estimate.^2 + b * X_estimate + c;
P_estimate = exp(Y_estimate); 
T_285 = P_estimate(1)
T_300 = P_estimate(2)

