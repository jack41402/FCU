x = 3
n = 1;
sum = 1;
while (exponential(x, n)>=1e-6)
    sum = sum + exponential(x, n);
    n = n + 1;
end
fprintf("The result of exponential funxtion is %.4f", sum);

function y = exponential(x, n)
a = 1;
cur = n;
for i = 1:n
    a = a .* cur;
    cur = cur - 1;
end
y = x .^n ./ a;
end



