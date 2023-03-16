clc;clear;
k = 1 ;
w1 = @(R) sqrt(k-R.^2./4) ;
y = @(R , t) exp(-(R./2).*t).*sin(w1(R).*t) ;
t = [0:0.1:10] ;

for R=0:0.5:2
    f = y(R , t) ;
    plot(t , f);
    hold on;
end
title("Oscillation") ;