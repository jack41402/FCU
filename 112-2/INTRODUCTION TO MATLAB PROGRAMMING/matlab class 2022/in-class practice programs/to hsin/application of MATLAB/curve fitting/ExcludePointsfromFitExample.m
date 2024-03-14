%% Exclude Points from Fit  
% Load some data and fit a custom equation specifying points to exclude.
% Plot the results.   

% Copyright 2015 The MathWorks, Inc.


%% 
% Load data and define a custom equation and some start points. 
[x, y] = titanium;

gaussEqn = 'a*exp(-((x-b)/c)^2)+d'
startPoints = [1.5 900 10 0.6]  

%% 
% Create two fits using the custom equation and start points, and define
% two different sets of excluded points, using an index vector and an expression.
% Use |Exclude| to remove outliers from your fit. 
f1 = fit(x',y',gaussEqn,'Start', startPoints, 'Exclude', [1 10 25])
f2 = fit(x',y',gaussEqn,'Start', startPoints, 'Exclude', x < 800)  

%% 
% Plot both fits. 
plot(f1,x,y)
title('Fit with data points 1, 10, and 25 excluded')

figure
plot(f2,x,y)
title('Fit with data points excluded such that x < 800')   

