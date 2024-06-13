% Given data
time = 0:1:5;
temperature = [20 25 27 28 27 25];

% Fit a 4th-degree polynomial to the data using the fit function
fitType = fittype('poly4');
[fitResult, gof] = fit(time', temperature', fitType);

% Evaluate the polynomial at the given x value
x = 3.6;
y_val = feval(fitResult, x)

% Extract SSE and R-squared from the gof structure
sse = gof.sse;
r_squared = gof.rsquare;

% Display the results
disp(['SSE: ', num2str(sse)]);
disp(['R-squared: ', num2str(r_squared)]);

% % Evaluate the polynomial at all given time points
% temperature_fit = polyval(f, time);
% 
% % Calculate the SSE (Sum of Squared Errors)
% errors = temperature - temperature_fit;
% sse = sum(errors.^2);
% 
% % Calculate the total sum of squares (SST)
% sst = sum((temperature - mean(temperature)).^2);
% 
% % Calculate the R-squared value
% r_squared = 1 - (sse / sst);