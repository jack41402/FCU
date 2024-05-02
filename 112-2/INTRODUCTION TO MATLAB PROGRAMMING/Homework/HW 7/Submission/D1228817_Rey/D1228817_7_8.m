p=poly(2, 3);

fprintf("p(2, 3) is %f", p)

function Y=poly(n, x)

    if n==0
        Y=1;
    elseif n==1
        Y=x;
    elseif n==2
        Y=(3*x^2-1)/2;
    else 
        (n+1)*poly(n+1, x)-(2*n+1)*poly(n, x)+n*poly(n-1, x);
    
    end
end

