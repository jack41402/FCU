ele = [200 500 700 1000 1500];
pay = 5 + (ele <= 500) .* (0.02 .* ele);
pay = pay + (ele > 500 & ele <= 1000) .* (10 + 0.05 .* (ele - 500));
pay = pay + (ele > 1000) .* (35 + 0.1 .* (ele - 1000));
disp([ele' pay']);
