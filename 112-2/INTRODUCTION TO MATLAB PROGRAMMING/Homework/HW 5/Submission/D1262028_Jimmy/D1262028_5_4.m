capital=[5000;10000;15000;22000;30000;38000;50000];
condition=[capital<=10000, (10000<capital)&(capital<=20000), (20000<capital)&(capital<=40000), capital>40000];

payment=[0.1*capital, 1000+0.2*(capital-10000), 3000+0.3*(capital-20000), 9000+0.5*(capital-40000)];

tax=payment.*condition;

for idx=1:7
    fprintf("%5d    ",capital(idx));
    for j=1:4
        if tax(idx, j)~=0
            fprintf("%5d\n", tax(idx, j));
        end
    end
end


