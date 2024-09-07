a = 100000;
pi_a = 0;
for k = 0:a
    pi_a = pi_a + ((-1)^k) / (2*k + 1);
end
pi_a = pi_a * 4;
fprintf("a =\n")
disp(pi_a)

b = 100000;
pi_b = 0;
for k = 0:b
    pi_b = pi_b + 1 / ((4*k + 1) * (4*k + 3));
end
pi_b = pi_b * 8;
fprintf("b =\n")
disp(pi_b)


c = 100;
pi_c = 4 * (6 * c_ar(1/8, c) + 2 * c_ar(1/57, c) + c_ar(1/239, c));
fprintf("c =\n")
disp(pi_c)

function y = c_ar(x, n)
    y = 0;
    for k = 0:n 
        y = y + ((-1)^k) * (x^(2*k + 1) / (2*k + 1));
    end
end