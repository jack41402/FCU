inc = [12000 15000 18000 24000 35000 50000 70000];
level = [3000 2500 1500 1000 400 100 25];
fprintf("\n(a): %d\n\n",mean(inc));
above = (inc > 32000) .* level;
below = (inc < 32000) .* level;
fprintf("(b): %d above, %d below\n\n",sum(above),sum(below));
total = inc .* level;
average = sum(total) ./ sum(level);
fprintf("(c): %.2f\n\n",average);
