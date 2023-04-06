P = zeros(6) ;
for i=3:6
    P(i , i-1) = 2/3 ;
    P(i-2 , i-1) = 1/3 ;
end
P(1 , 1) = 1 ;
P(6 , 6) = 1 ;
x = [1 0 0 0 0 0] ;
PFinal = P^50
XFinal = PFinal*x'