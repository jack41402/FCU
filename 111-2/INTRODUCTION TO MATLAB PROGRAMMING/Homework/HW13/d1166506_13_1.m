timespan = [0 10] ;
x0 = [1 2 5] ; % initial conditions 
[t , x] = ode23(@diff , timespan , x0) ; 

plot(t , x(: , 1))

function vdot = diff(t , x)
vdot(1) = 1 * x(2) ; 
vdot(2) = 1 * x(3) ; 
vdot(3) = -12 * x(1) - 14 * x(2) - 7 * x(3) + 10 ;
vdot = vdot' ;
end