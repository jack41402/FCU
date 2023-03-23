L = 10 ;
W = 100 ;
T = 1000 ;
EI = 1e4 ;
a = sqrt(T/EI) ;
y = @(x) (W*EI/(T^2)).*((cosh(a*(L/2-x))/cosh(a*L/2))-1)+((W.*x.*(L-x))./(2*T)) ;
x = 0:L ;

plot(x , y(x))
