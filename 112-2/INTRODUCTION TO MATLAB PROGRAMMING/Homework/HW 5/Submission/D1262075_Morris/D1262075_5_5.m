total = [12000 15000 18000 24000 35000 50000 70000];
people = [3000 2500 1500 1000 400  100 25];
fprintf('a. %d',mean(total))
B = total < mean(total);
C = B .* people;
fprintf('\nb. %d',sum(C))
D = total > mean(total);
E = D.*people;
fprintf(' %d',sum(E))
F = total.*people;
G = sum(F);
H = sum(people);
I = G./H;
fprintf('\nc. %.2f',I)
