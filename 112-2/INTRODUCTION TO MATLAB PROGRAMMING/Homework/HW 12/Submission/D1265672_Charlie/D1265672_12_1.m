years = 2004:2009;
populations = 10^6.*[10 10.9 11.7 12.6 13.8 14.9];

p = polyfit(years, populations, 2);

pf = polyval(p, years);

plot(years, populations, 'o'); 
hold on;
plot(years, pf, '-'); 

syms years;
s=2*populations(1);
ans=solve(p(1)*(years.^2)+p(2)*years+p(3)==s,years);
y=double(ans);
y=y(y>=2009);
fprintf("T = %.2f", y);
xticks(2004:2009);