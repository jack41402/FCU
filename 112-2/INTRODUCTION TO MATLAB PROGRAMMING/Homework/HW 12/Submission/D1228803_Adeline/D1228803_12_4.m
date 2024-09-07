T = [273 278 283 288 293 298];
P = [4.579 6.543 9.209 12.788 17.535 23.756];

X = 1 ./ T;
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
plot(T, P, '.', 'MarkerSize', 8, 'DisplayName', 'Data');
hold on;
plot(T_fit, P_fit, '-', 'LineWidth', 0.8, 'Color', 'r', 'DisplayName', 'Fitted Curve');

xlabel('x');
ylabel('y');
legend show;

%T_estimate = [285, 300];
T_estimate = [284.9532, 299.7083];
X_estimate = 1 ./ T_estimate;
Y_estimate = a * X_estimate.^2 + b * X_estimate + c;
P_estimate = exp(Y_estimate);

fprintf('T_285 = \n\t%.4f\n', P_estimate(1));
fprintf('T_300 = \n\t%.4f\n', P_estimate(2));

