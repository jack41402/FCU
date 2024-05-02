result = p(2, 3);
fprintf("p(2 , 3) is %.6f", result)
function result = p(n, x)
    if n == 0
        result = 1;
    elseif n == 1
        result = x;
    else 
        result = ((2*n-1)*x*p(n-1, x)-(n-1)*p(n-2, x)) / n;
    end
end
    