years = [2004, 2005, 2006, 2007, 2008, 2009];
population = [10000000, 10900000, 11700000, 12600000, 13800000, 14900000];
p = polyfit(years, population, 2);
years_fit = linspace(2004, 2009);
population_fit = polyval(p, years_fit);
figure;
plot(years, population, 'o', 'MarkerSize', 8, 'DisplayName', 'Data'); % Original data points
hold on;
plot(years_fit, population_fit, '-', 'LineWidth', 0.5, 'DisplayName', 'Polynomial Fit'); % Polynomial curve

target_population = 20050000;
p_adjusted = p;
p_adjusted(end) = p_adjusted(end) - target_population;
estimated_years = roots(p_adjusted);
format bank;
estimated_year = estimated_years(estimated_years > 2009);
t = estimated_year
