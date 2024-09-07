year = 2004:2009;
population = [10*10^6, 10.9*10^6, 11.7*10^6, 12.6*10^6, 13.8*10^6, 14.9*10^6];

p = polyfit(year, population, 2);

fit_population = polyval(p, year);

figure;
plot(year, population, 'o');
hold on;
plot(year, fit_population, '-');


target_population = 2 * population(1);

syms x;
solution = solve(p(1)*x^2 + p(2)*x + p(3) == target_population, x);
newyear = double(solution);
newyear = newyear(newyear >= 2009);

t = sprintf('%.2f',newyear)

