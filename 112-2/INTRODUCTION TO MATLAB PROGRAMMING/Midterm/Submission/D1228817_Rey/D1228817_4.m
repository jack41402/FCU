n=0:20;
a=2;

fprintf("n              x_n\n");

for i=1:21

    fprintf("%d%s", i-1, rats(func(a, n(i)), 30));
    fprintf("\n");

end