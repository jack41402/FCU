function D1265154_7_7()
function result = fibonacci_recursive(n)
    if n == 0
        result = 1;
    elseif n == 1 || n == 2
        result = 1;
    else
        result = fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
    end
end
    fprintf('Fibonacci numbers from F0 to F20:\n');
    for n = 0:20
        fprintf('F(%d) = %d\n', n, fibonacci_recursive(n));
    end

end