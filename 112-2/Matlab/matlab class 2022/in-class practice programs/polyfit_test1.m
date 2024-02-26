%% Use Centering and Scaling to Improve Numerical Properties
% 
%%
% Create a table of population data for the years 1750 - 2000 and
% plot the data points.

% Copyright 2015 The MathWorks, Inc.

year = (1750:25:2000)';
pop = 1e6*[791 856 978 1050 1262 1544 1650 2532 6122 8170 11560]';
T = table(year, pop)
plot(year,pop,'o')
%%
% Use |polyfit| with three outputs to fit a 5th-degree polynomial using
% centering and scaling, which improves the numerical properties of the
% problem. |polyfit| centers the data in |year| at 0 and scales it to have
% a standard deviation of 1, which avoids an ill-conditioned Vandermonde
% matrix in the fit calculation.
[p,~,mu] = polyfit(T.year, T.pop, 5);
% Use |polyval| with four inputs to evaluate |p| with the scaled years,
% |(year-mu(1))/mu(2)|. Plot the results against the original years.
%  mu = (1.87500.0829)  1.0e+03 
f = polyval(p,year,[],mu);
hold on
plot(year,f)
hold off

