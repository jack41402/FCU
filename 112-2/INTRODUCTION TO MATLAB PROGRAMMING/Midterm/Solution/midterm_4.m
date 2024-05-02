format default

a = 2;

fprintf("\tn\t\t\t\t  x_n\n");
for n=0:20
    fprintf("\t%d\t%-10s\n", n, rats(func(a, n), 30));
end