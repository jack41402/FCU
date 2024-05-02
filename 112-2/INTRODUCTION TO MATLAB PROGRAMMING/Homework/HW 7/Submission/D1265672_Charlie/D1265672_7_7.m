for n = 0:20
    fprintf('%5d  %5d\n', n, f(n));
end

function result = f(n)
    if n == 0 || n == 1
        result = 1;
    else
        result = f(n-1) + f(n-2);
    end
end