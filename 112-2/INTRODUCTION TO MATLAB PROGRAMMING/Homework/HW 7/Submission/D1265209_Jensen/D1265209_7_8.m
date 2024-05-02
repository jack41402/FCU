p2_recursive = p(2,3);
fprintf('P(2,3) is %f\n',p2_recursive);
function result = p(n,x)
    if n==0
        result = 1;
    elseif n==1
        result = x;
    else 
        result = ((2.*n-1).*x.*p(n-1,x)-(n-1).*p(n-2,x))/n;
    end
end

