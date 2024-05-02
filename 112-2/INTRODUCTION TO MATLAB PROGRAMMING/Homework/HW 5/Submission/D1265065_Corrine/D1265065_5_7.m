units = [200 500 700 1000 1500];
cost(units <= 500) = units(units <= 500)*0.02+5;
cost(units > 500 & units <= 1000) = (units(units > 500 & units <= 1000)-500)*0.05+10+5;
cost(units > 1000) = (units(units > 1000)-1000)*0.1+35+5;
answer = [units;cost]'