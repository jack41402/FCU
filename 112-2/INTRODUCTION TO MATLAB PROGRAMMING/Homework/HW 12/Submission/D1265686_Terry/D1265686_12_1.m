year = 2004:2009;

population = 10^6.*[10, 10.9, 11.7, 12.6, 13.8, 14.9];

p = polyfit (year,population,2);

plot(year,population,"o",year,polyval(p,year))

syms year;
s=2*population(1);
solution=solve(p(1)*(year.^2)+p(2)*year+p(3)==s, year);
t=double(solution);
t=t(t>=2009);
fprintf("t=\n     %.2f\n", t)
xticks(2004:2009);

