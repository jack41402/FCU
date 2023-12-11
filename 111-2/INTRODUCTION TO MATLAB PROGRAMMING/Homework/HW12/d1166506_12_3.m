time = 0:0.5:4 ;
voltage = [100 62 38 21 13 7 4 2 3] ;

p = polyfit(time , voltage , 8) ;
% x = linspace(0 , 4) ;
y = polyval(p , time) ;

plot(time , voltage , 'o') ;
hold on
plot(time , y) ;
hold off