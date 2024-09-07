T = [273, 278, 283, 288, 293, 298];
P = [4.579, 6.543, 9.209, 12.788, 17.535, 23.756];

fitType = 'poly2';
fitResult = fit(T', P', fitType);

figure;
plot(fitResult, T, P, '.');
xlabel('x');
ylabel('y');
legend('data', 'fitted curve', 'Location', 'northeast');


T_285 = feval(fitResult, 285);
T_300 = feval(fitResult, 300);

disp(['P_285 = ', num2str(T_285)]);
disp(['P_300 = ', num2str(T_300)]);

