pi_estimate = 0;
terms = 100000;
for i = 0:terms-1
    pi_estimate = pi_estimate + ((-1) ^ i) / (2 * i + 1);
end
a = pi_estimate * 4

pi_estimate = 0;
for i = 0:terms
    pi_estimate = pi_estimate + (1 / ((4*i + 1) * (4*i + 3)));
end
b = pi_estimate*8


c = compute_pi_machin(terms)

function pi_estimate = compute_pi_machin(terms)
    function arctan_val = arctan(x, terms)
        arctan_val = 0;
        sign = 1;
        for n = 0:terms-1
            arctan_val = arctan_val + sign * (x^(2*n+1)) / (2*n+1);
            sign = -sign;
        end
    end
    arctan1_8 = arctan(1/8, terms);
    arctan1_57 = arctan(1/57, terms);
    arctan1_239 = arctan(1/239, terms);

    pi_estimate = 4 * (6 * arctan1_8 + 2 * arctan1_57 + arctan1_239);
end