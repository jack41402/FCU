years = [2004, 2005, 2006, 2007, 2008, 2009];
population = [10, 10.9, 11.7, 12.6, 13.8, 14.9].*10.^6;
y = polyfit(years,population, 2);
plot(years, population, 'o', years, polyval(y, years),'-')
t = 2009;
z = polyval(y, t);
while abs((z-2*population(1))/10^6)>10^-4
    t = t + 0.0001;
    z=polyval(y, t);

end
fprintf("t=\n%.2f", t)