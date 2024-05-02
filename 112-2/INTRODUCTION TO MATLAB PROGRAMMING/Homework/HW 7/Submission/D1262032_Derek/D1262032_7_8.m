fprintf("P(2 , 3) is %f\n", p(2, 3))
function y = p(n, x)
    if n==0
        y = 1;
    elseif n==1
        y = x;
    else 
        y = ((2*n-1)*x*p(n-1, x)-(n-1)*p(n-2, x))/n;
    end
end