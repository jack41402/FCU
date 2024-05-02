fprintf('n               x_n\n')
for i = 0:1:20
    a = 2;
    n = i;
    x_n = (n.*a.^n)./factorial(n+1);
    fprintf('%2d', n)
    R = rats(x_n, 30);
    fprintf(R);
    fprintf('\n');
end