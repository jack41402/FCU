x = 3;
n = 1;
a = 1;
fprintf("%d   %.4f\n",n,a);
while(abs(cos(3) - a) >= 0.0001)
    a = a + ((-1) .^ n) .* x .^ (2 .* n) ./ factorial(2 .* n);
    n = n + 1;
    fprintf("%d   %.4f\n",n,a);
end