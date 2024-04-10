N = 20;
L = 50000;
r = 0.15;
P = (r * L * (1 + r / 12)^(12 * N)) / (12 * ((1 + r / 12)^(12 * N) - 1));
fprintf('Monthly payment: %.2f\n', P);

N = 20 : 1 : 1000;
P = (r * L * (1 + r / 12) .^ (12 * N)) ./ (12 * ((1 + r / 12) .^ (12 * N) - 1));
plot(N, P);
xlabel('Number of months');
ylabel('Monthly payment');

disp('no');

N = 20;
L = 50000;
r = 0.15;
p = (r * L * (1 + r / 12)^(12 * N)) / (12 * ((1 + r / 12)^(12 * N) - 1));

r = 0.16;
q = (r * L * (1 + r / 12)^(12 * N)) / (12 * ((1 + r / 12)^(12 * N) - 1));
diff = q - P;

lp = 0;
for i = 1:10
    P = (r * L * (1 + r / 12)^(12 * N)) / (12 * ((1 + r / 12)^(12 * N) - 1));
    if (i > 1)
        a = P - lp;
        fprintf('Difference in monthly payment: %.2f\n', a);
    end
    lp = P;
    r = r + 0.01;
end
