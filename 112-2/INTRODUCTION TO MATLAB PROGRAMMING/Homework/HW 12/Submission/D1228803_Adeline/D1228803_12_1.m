years = [2004 2005 2006 2007 2008 2009];
population = [10 10.9 11.7 12.6 13.8 14.9];

P = polyfit(years, population, 2);

years_fit = linspace(2004, 2009, 100);
population_fit = polyval(P, years_fit);

figure;
plot(years, population, 'o', 'MarkerSize', 6, 'DisplayName', 'Data');
hold on;
plot(years_fit, population_fit, '-', 'LineWidth', 0.8, 'DisplayName', 'Fitted Curve');

target_population = 20.06;
coefficients = P;
coefficients(end) = coefficients(end) - target_population;
estimated_year = roots(coefficients);

realistic_year = estimated_year(estimated_year > 2009 & estimated_year < 2100);
if ~isempty(realistic_year)
    fprintf('t = \n\t\t%.2f\n', realistic_year);
else
    fprintf('Not found in the given range.\n');
end
