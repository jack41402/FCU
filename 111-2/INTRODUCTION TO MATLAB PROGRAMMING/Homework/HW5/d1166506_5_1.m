F = [11 , 7 , 8 , 10 , 9] ;
k = [1000 , 600 , 900 , 1300 , 700] ;

% compression x in each spring
x = F./k

% potential energy
U = (k.*x.^2)/2