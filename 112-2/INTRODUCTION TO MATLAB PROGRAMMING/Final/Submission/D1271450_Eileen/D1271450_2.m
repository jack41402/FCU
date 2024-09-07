X = [0;1;2;3;4;5]; 
Y = [20;25;27;28;27;25];
coefficients = polyfit(1./X, log(Y), 2);
f = @(x) exp(polyval(coefficients, 1./x)); 
T_range = linspace(min(X), max(X), 100); 
P_fit = f(T_range);
plot(T, P, '.', T_range, P_fit) 
xlabel('Temperature (K)') 
ylabel('Pressure (atm)') 
legend('Data', 'Fitted curve') 
T_range = linspace(min(X), max(X), 100);
P_fit = f(T_range);
T_285 = 3.6;
P_285 = fit(T_285);
SSE==fittype(P_285);
R-squared==fit(P_285);
fprintf('y=\n%.4f\n', P_285)
fprintf('SSE: %.6f\n', SSE)
fprintf('R-squared: %.4f\n', R-squared)
