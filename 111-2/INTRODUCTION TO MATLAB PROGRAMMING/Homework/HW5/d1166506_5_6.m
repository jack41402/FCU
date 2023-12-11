V = 10 ;
h = @(r) (3*V)/(pi*(r^2)) ;
A = @(r) pi*r*sqrt(r^2+(h(r)^2)) ;
r = fminbnd(A , 0 , 2) 
A = A(r)
h = h(r)