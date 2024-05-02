function D1265154_newquot_fun()
function newquot_func(f, x) 
     x = 1; 
        for i = 0:10
            h = 10^(-i);
            derivative_estimate = (f(x + h) - f(x)) / h;
            fprintf('h = %.10f, Estimated derivative = %.4f\n', h, derivative_estimate);
        end
end
    f = @(x) x.^3;
    newquot_func(f, 1);

end
