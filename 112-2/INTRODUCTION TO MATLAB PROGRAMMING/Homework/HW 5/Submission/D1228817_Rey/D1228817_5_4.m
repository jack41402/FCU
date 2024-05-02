Money=[5000;10000;15000;22000;30000;38000;50000];
logical=[Money<=10000, (10000<Money)&(Money<=20000), (20000<Money)&(Money<=40000), Money>40000];


plan=[0.1*Money, 1000+0.2*(Money-10000), 3000+0.3*(Money-20000), 9000+0.5*(Money-40000)];


tax=plan.*logical;


for i=1:7
    fprintf("%5d    ",Money(i));
    for j=1:4
           if tax(i, j)~=0
               fprintf("%5d\n", tax(i, j));
           end
    end
end


