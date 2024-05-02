for n = 0: 20
    fprintf("%3d %7d\n", n, fib(n));
end

function result = fib(n)
    if n == 0 || n == 1
        result = 1;
    else
        result = fib(n-1) + fib(n-2);
    end    
end