a = 2;
fprintf("n                    x_n\n")
for n = 0 : 1 : 20
    if(n >= 10)
        fprintf("%d%s\n",n,rats(func(a,n),40))
    else
        fprintf("%d %s\n",n,rats(func(a,n),40))
    end
    func(a,n);
end