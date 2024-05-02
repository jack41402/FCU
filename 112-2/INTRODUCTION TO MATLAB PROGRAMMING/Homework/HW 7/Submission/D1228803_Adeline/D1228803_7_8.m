function D1228803_7_8()
    function y = p(n, x)
        if n == 0
            y = 1;
        elseif n == 1
            y = x;
        else
            y = ((2 * n - 1) * x * p(n-1, x) -(n-1) * p(n - 2, x)) / n;
        end
         
    end
    n = input('n = ');
    x = input('x = ');
    result = p(n, x);
    fprintf('P(%d, %d) is %.6f\n', n, x, result);
end