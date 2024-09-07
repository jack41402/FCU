function D1265154_8_1()
function pi_approx_a = compute_pi_a(num_terms)
    pi_sum = 0;
    for n = 0:num_terms-1
        pi_sum = pi_sum + (-1)^n / (2*n + 1);
    end
    pi_approx_a = 4 * pi_sum;
end

function pi_approx_b = compute_pi_b(num_terms)
    pi_sum = 0;
    for n = 0:num_terms-1
        pi_sum = pi_sum + 1 / ((4*n+1)*(4*n+3));
    end
    pi_approx_b = 8 * pi_sum;
end

function pi_approx_c = compute_pi_c()
    arctan_8 = compute_arctan(1/8);
    arctan_57 = compute_arctan(1/57);
    arctan_239 = compute_arctan(1/239);
    pi_approx_c = 4 * (6*arctan_8 + 2*arctan_57 + arctan_239);
end

% Function to compute arctan using the given series expansion
function atan_val = compute_arctan(x)
    atan_sum = 0;
    sign = 1;
    term = x;
    n = 1;
    while abs(term) > 1e-15 % precision threshold
        atan_sum = atan_sum + sign * term;
        sign = -sign;
        n = n + 2;
        term = (x^n) / n;
    end
    atan_val = atan_sum;
end


num_terms_a = 30000;
pi_approx_a = compute_pi_a(num_terms_a);
fprintf('(a) %.4f\n', pi_approx_a);

num_terms_b = 30000; 
pi_approx_b = compute_pi_b(num_terms_b);
fprintf('(b) %.4f\n', pi_approx_b);

pi_approx_c = compute_pi_c();
fprintf('(c) %.4f\n', pi_approx_c);


end


