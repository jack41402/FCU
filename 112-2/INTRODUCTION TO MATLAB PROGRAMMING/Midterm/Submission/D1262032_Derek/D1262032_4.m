format rational
fprintf("n          x_n\n")
xn(:, 1)=0:20;
for n=0:20
    a=2;
    xn(n+1, 2)=func(a, n);
    %fprintf("%d          %f\n", n, rats(func(a, n), 10))
    %rats(func(a, n))
end
c=rats(xn, 100)
for n=0:20
fprintf("%d          \n", n, c(1, 2))
end
fprintf("\n")