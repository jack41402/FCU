x = 0:0.004:1;
oldans(1) = 1;
ans = 0;
for n = 0 : 3
    for k = 0 : n
        coef = factorial(n)/(factorial(n-k) * factorial(k));
        term = coef.* oldans(k+1).* x.^(n-k);
        ans = ans + term;
    end
    plot(x,ans)
    hold on
    oldans(n+2) = ans;
end
hold off
