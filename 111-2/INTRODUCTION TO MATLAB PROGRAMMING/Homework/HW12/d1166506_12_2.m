time = 0:1:6 ;
temperature = [300 150 75 35 12 5 2] ;

p = polyfit(time , temperature , 5) ;
% x = linspace(0 , 6) ;
y = polyval(p , time) ;

plot(time , temperature , 'o') ;
hold on
plot(time , y) ;
hold off