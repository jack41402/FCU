year = [2004 2005 2006 2007 2008 2009] ;
population = [10 10.9 11.7 12.6 13.8 14.9] ;
x = linspace(2004 , 2009 , 100) ;
p = polyfit(year , log10(population) , 1) ;
y = polyval(p , x)
plot(year , population , 'o' , x , y) ;
