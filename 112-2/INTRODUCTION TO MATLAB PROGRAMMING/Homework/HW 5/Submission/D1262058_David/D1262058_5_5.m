offer= [12000 15000 18000 24000 35000 50000 70000];
level= [3000 2500 1500 1000 400 100 25];
a = mean(offer, "all")

above = level(find(offer>averageoffer));
b1 = sum(above)
below = level(find(offer<averageoffer));
b2 = sum(below)

money = offer.*level;
total = sum(money);
people = sum(level);
c = total/people