P = @(t) (197273000)./(1+exp(-0.03134.*(t-1913.25))) ;
actual = [3929000 5308000 7240000 9638000 12866000 17069000 23192000 31443000 38558000 50156000 62948000 75995000 91972000 105711000 122775000 131669000 150697000] ;
t = 1790:10:1950 ;
plot(t , P(t) , 'b-' , 'LineWidth' , 3) ;
title('USA population')
ylabel('population')
hold on
plot(t , actual , 'LineStyle', 'none' , 'Marker', '^' , 'LineWidth' , 2)
legend('logistic' , 'actual')