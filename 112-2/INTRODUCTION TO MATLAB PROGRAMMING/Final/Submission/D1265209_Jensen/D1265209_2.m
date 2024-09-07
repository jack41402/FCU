T = [0, 1, 2, 3, 4, 5];
P = [20, 25, 27, 28, 27, 25];

fitType = 'poly4';
[fitResult, gof] = fit(T', P', fitType);

y = feval(fitResult, 3.6);
fprintf('y = \n');
disp(y);
fprintf('SSE: %f\n', gof.sse);
fprintf('R-square: %f\n', gof.rsquare);





