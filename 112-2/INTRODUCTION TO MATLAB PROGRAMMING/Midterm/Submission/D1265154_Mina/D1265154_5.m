radius = R;
width = 2*R;
lendth = L;

fun = width*lendth + radius^2 *pi./2;
area  = 2000;
fun=area;

 price_1 = 50;
 price_2 = 40;
 total= price_1+price_2;


R = 0.01;
L = 0.01;
[R_min] = fminbnd(fun,total,R)
[L_min] = fminbnd(fun,total,L)

min_cost = sum(R_min,L_min)
