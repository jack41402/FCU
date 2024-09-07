clc;clear all
% Example usage(a):
terms = 30000;
pi_approx = compute_pi_a(terms);
disp(['a=', num2str(pi_approx)]);

% Example usage(b):
terms = 15000; % fewer terms are needed compared to (a)
pi_approx = compute_pi_b(terms);
disp(['b=', num2str(pi_approx)]);

% Example usage(c):
pi_approx = compute_pi_fast();
disp(['c=', num2str(pi_approx)]);

%(a)
function pi_approx = compute_pi_a(terms)
    pi_sum = 0;
    for k = 0:terms-1
        pi_sum = pi_sum + ((-1)^k)/(2*k+1);
    end
    pi_approx = 4 * pi_sum;
end
%(b)
function pi_approx = compute_pi_b(terms)
    pi_sum = 0;
    for k = 0:terms-1
        pi_sum = pi_sum + 1/((4*k+1)*(4*k+3));
    end
    pi_approx = 8 * pi_sum;
end

%(c)
function pi_approx = compute_pi_fast()
    pi_approx =4*( 6 * arctan_series(1/8, 100000) + 2 * arctan_series(1/57, 100000) + arctan_series(1/239, 100000));
end

function result = arctan_series(x, terms)
    result = 0;
    sign = 1;
    for k = 0:terms-1
        term = (x^(2*k+1))/(2*k+1);
        result = result + sign * term;
        sign = -sign;
    end
end









