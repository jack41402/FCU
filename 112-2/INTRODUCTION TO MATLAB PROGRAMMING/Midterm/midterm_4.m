format default

a = 2;

fprintf("\tn\t\tx_n\n");
for n=0:20
    fprintf("\t%d\t%-10s\n", n, rats(func(a, n), 20));
end