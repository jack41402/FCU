t = [0 0.5 1 1.5 2 2.5 3 3.5 4];
volt = [100 62 38 21 13 7 4 2 3];
y = polyfit(t, volt, 8);
plot(t, volt, 'o', t, polyval(y,t))

n=8