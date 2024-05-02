function D1265154_7_8()
    function result = legendre_recursive(n, x)
        if n == 0
            result = 1;
        elseif n == 1
            result = x;
        else
            result = ((2*n - 1) * x * legendre_recursive(n-1, x) - (n - 1) * legendre_recursive(n-2, x)) / n;
        end
    end

    p_2_x = input('Enter the value of x: ');
    legendre_p_2_x = legendre_recursive(2, p_2_x);
    fprintf('p(2, %d) = %.6f\n', p_2_x, legendre_p_2_x);
end
