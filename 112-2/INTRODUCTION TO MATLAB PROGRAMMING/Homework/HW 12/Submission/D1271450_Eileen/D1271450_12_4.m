T = [273; 278; 283; 288; 293; 298]; 
P = [4.579; 6.543; 9.209; 12.788; 17.535; 23.756];
coefficients = polyfit(1./T, log(P), 2);
f = @(x) exp(polyval(coefficients, 1./x));
T_range = linspace(min(T), max(T), 100);
P_fit = f(T_range);
plot(T, P, '.', T_range, P_fit)
xlabel('x')
ylabel('y')
legend('data', 'fitted curve')
T_285 = 284.9533;
T_300 = 299.7083;
P_285 = f(T_285);
P_300 = f(T_300);
fprintf('T_285 = \n   %.4f\n', P_285)
fprintf('T_300 = \n    %.4f', P_300)
