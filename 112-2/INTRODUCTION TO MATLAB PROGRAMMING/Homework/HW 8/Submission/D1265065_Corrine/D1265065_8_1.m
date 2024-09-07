num_terms = 24000;
a = compute_pi(num_terms);
a
num_terms = 12000;
b = compute_pi_rearranged(num_terms);
b
c = compute_pi_fastest();
c
function a = compute_pi(num_terms)
    a = 0;
    for k = 0:num_terms-1
        a = a + ((-1)^k) / (2*k + 1);
    end
    a = 4 * a;
end

function b = compute_pi_rearranged(num_terms)
    b = 0;
    for k = 0:num_terms-1
        b = b + 1 / ((4*k + 1) * (4*k + 3));
    end
    b = 8 * b;
end

function c = compute_pi_fastest()
    c = 6 * arctan(1/8) + 2 * arctan(1/57) + arctan(1/239);
    c = 4 * c;
end

function result = arctan(x)
    result = 0;
    sign = 1;
    for n = 0:1000 % You can increase the upper limit if you need more accuracy
        term = (x^(2*n + 1)) / (2*n + 1);
        result = result + sign * term;
        sign = -sign;
    end
end
