x = 3 ;
P2 = @(x) (3*(x^2)-1)/2 ;
if (abs(P2(x)-P(2 , x))<1e-6)
    fprintf("P(2 , %d) is %f\n" , x , P(2 , x)) ;
else
    fprintf("Valid false\n") ;
end

function y = P(n , x)
    if (n==0) y = 1 ;
    elseif (n==1) y = x ;
    else
        y = ((2*n-1)*x*P(n-1 , x) - (n-1)*P(n-2 , x))/n ;
    end
end