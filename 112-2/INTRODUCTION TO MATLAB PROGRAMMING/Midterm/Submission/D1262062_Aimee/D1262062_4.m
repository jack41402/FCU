a = 2;
for n = 0:20
    x_n = func(a, n);
    fprintf('%d %d\n', n, rats(x/n))
end
