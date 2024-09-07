format bank
year = 2004:1:2009;
population = [10, 10.9, 11.7, 12.6, 13.8, 14.9];
p = polyfit(log10(population), year, 1);

% y = mx + b
% x = (y-b)/m
polyval(p, log10(20))


format bank
plot(year, population*1e6, 'o', year, population*1e6)
k = polyval(p,log10(population));
plot(year,population,'o',k,population)


