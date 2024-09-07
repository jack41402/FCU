clc;clear all
A = 1000; % Initial amount invested
r = 0.04; % Nominal annual interest rate (4%)
k = 10;   % Number of years

V_limit = A * exp(r * k); % Limiting value using the formula Ae^rk
disp(V_limit)
n = 1; % Initial number of compounding periods per year
V = zeros(1, 20); 


for i = 1:20
    V(i) = A * (1 + r/n)^(n*k); % Compute V for each value of n
    if abs(V_limit - V(i)) < 1e-4 % Check if the difference is within epsilon
        break; % If it's within epsilon, stop the loop
    end
    n = n * 2; % Double the number of compounding periods
end


% Display the values of V and the corresponding n

fprintf("%.4e",V(i))

