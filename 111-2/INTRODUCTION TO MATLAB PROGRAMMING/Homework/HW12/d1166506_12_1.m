format compact
year = 2004:1:2009 ;
population = [10 10.9 11.7 12.6 13.8 14.9] ;

x = year - 2000 ;
p = polyfit(x , log10(population) , 1)

% y=mx+b
b = 10^p(2) ;
m = p(1) ;
y = b.*(10.^(m.*x));

format bank
t = 2000+(log10(20)-log10(b))/m

plot(year , population*1e6 , 'o') ;
hold on
plot(year, y*1e6);
hold off