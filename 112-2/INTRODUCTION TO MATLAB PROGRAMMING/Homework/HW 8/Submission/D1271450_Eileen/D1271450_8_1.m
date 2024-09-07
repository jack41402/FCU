num_terms_a = 25000;
a = 0;
for k = 0:num_terms_a-1
    term = (-1)^k / (2*k + 1);
    a = a + term;
end
a = 4 * a
num_terms_b = 100000;

b = 0;

for k = 0:num_terms_b-1
    term = (-1)^k / (2*k + 1);
    b =b + term;
end

b = 4 * b
c = 4 * (6 * atan(1/8) + 2 * atan(1/57) + atan(1/239))
