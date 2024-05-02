units=[200; 500; 700; 1000; 1500];
logical=[units<=500, (500<units)&(units<=1000), units>1000];
plan=[0.02*units+5, 15+0.05*(units-500), 40+0.1*(units-1000)];

cost=plan.*logical;

for i=1:5
    fprintf("%5d    ",units(i));
    for j=1:3
           if cost(i, j)~=0
               fprintf("%5d\n", cost(i, j));
           end
    end
end