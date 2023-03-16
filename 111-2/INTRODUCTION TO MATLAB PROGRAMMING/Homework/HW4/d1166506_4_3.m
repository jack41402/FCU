% (a)
a = @(x , a) log(x+x^2+a^2) ;

% (b)
b = @(t) (exp(3*t)+t^2*sin(4*t))*(cos(3*t)^2) ;

% (c)
c = @(x) 4*atan(x) ;

% (d)
d = @(x , y) sec(x)^2 + cot(y) ;

% (e)
e = @(x , a) acot(abs(x/a)) ;

A = a(1 , 2) ;
B = b(1) ;
C = c(1) ;
D = d(1 , 2) ;
E = e(1 , 2) ;

format("bank") ;
fprintf("A=%f\nB=%f\nC=%f\nD=%f\nE=%f\n" , A , B , C , D , E) ;