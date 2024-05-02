x = input("x = \n    ");
custom_exp = exp_taylor(x);

fprintf('The result of exponential function is %f\n', custom_exp);

function e_approx = exp_taylor(x)
    term = 1;  
    e_approx = term; 
    n = 1; 
    
    while term >= 1e-6
        term = term * x / n; 
        e_approx = e_approx + term; 
        n = n + 1; 
    end
end