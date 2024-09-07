clc;
clear all;

x = 0:0.004:1;


% Calculate Bell polynomials Bn(x) for n = 0 to 3
B0 = BellPolynomial(0, x);
B1 = BellPolynomial(1, x);
B2 = BellPolynomial(2, x);
B3 = BellPolynomial(3, x);

% Plotting
figure;
plot(x, B0, 'r-','LineStyle', '-', 'LineWidth', 2);
hold on;
plot(x, B1, 'g-','LineStyle', '- ',  'LineWidth', 2);
plot(x, B2, 'b-','LineStyle', '.', 'LineWidth', 2);
plot(x, B3, 'm-','LineStyle', '-.', 'LineWidth', 2);

% Add labels and legend

legend('B1(x)', 'B2(x)', 'B3(x)', 'B4(x)');

hold off;

set(line3, 'Color', 'c', 'LineStyle', '--', 'LineWidth', 2); % Change line properties

% Define a function to recursively calculate Bell polynomials
function B = BellPolynomial(n, x)
    if n == 0
        B = 1;  % Base case: B0(x) = 1
    else
        B = 0;
          BellPolynomial(0, x)=1;
        for k = 0:n-1
            binomial_coeff = factorial(n-1) ./ (factorial(k) .* factorial(n-1 - k));
            B = B + binomial_coeff .* BellPolynomial(k, x) * x.^(n - k);
        end
    end
end