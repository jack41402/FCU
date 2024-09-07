year = 2004 : 1 :2009;
population = [10, 10.9, 11.7, 12.6, 13.8, 14.9];
population = population*10^6;
p = polyfit(log10(population),year,1);
t = polyval(p,log10(20*10^6))
k = polyval(p,log10(population));
plot(year,population,'o',k,population)