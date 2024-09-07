format bank
year = 2004:1:2009;

population = [10, 10.9, 11.7, 12.6, 13.8, 14.9];

cofficient = polyfit(log10(population), year, 1);
t = polyval(cofficient, log10(20))

plot(year, population.*1e6 , 'o',  year, population.*1e6);
