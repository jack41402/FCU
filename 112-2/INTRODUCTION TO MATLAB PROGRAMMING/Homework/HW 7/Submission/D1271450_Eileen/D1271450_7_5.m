function D1271450_7_5
function result = exp_taylor(x)
    result = 1;  
    term = 1;  

    n = 1;
    while abs(term) >= 1e-6  
        term = term * x / n;  
        result = result + term;  
        n = n + 1; 
    end
end

x_values = input('Enter the value of x:') 
for i = 1:numel(x_values)
    x = x_values(i);
    exact_result = exp(x);
    fprintf('x = %d,  Exact: %.6f\n', x, exact_result);
end
end
