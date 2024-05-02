function D1265065_7_8()
function result = p(n, x)
    % Base cases
    if n == 0
        result = 1;
    elseif n == 1
        result = x;
    else
        % Recursive calculation using recurrence formula
        result = ((2*n - 1) * x * p(n-1, x) - (n - 1) * p(n-2, x)) / n;
    end
end
x_values = input('x = ');
    
    % Compute P2(x) using the recursive function and analytic form
    for i = 1:length(x_values)
        x = x_values(i);
        p_recursive = p(2, x);
        p_analytic = (3*x^2 - 1) / 2;
        fprintf('P(2 , %d) = %.6f\n', x, p_analytic);
        fprintf('\n');
    end

end