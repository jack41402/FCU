function compute_investment_value()
    A = 1000; % initial amount
    r = 0.04; % interest rate (as a decimal)
    k = 10;   % number of years

    n = 1;
    V_values = zeros(1, 20); % preallocate array to store V values
    for i = 1:20
        V = A * (1 + r / n)^(n * k);
        V_values(i) = V;
        n = n * 2; % double n for the next iteration
    end

    % Compute value using A * exp(r * k)
    V_exp = A * exp(r * k);
    V = V
    exponential_form = V_exp
end
