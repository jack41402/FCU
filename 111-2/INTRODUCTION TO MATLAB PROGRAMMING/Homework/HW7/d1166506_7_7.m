W = 400 ;
Lb = 3 ;
Lc = 5 ;
T = @(D) (Lb*Lc*W)./(D.*sqrt(Lb^2-D.^2)) ;

D = 0:0.0001:3 ;
format bank
[temp , index] = min(T(D)) ;
fprintf("Min = %.4f\n" , D(index)) ;
plot(D , T(D)) ;
axis([0 3 0 200000])