function result = D1265154_7_5()
    function result = my_exp_taylor(x)
        n = 0;
        term = 1;
        result = term;
        while abs(term) >= 1e-6
            n = n + 1;
            term = term * x / n;
            result = result + term;
        end
    end
x = input('x=');
exp_result = exp(x);
fprintf('exp(%d) = %f\n', x, exp_result);

end
