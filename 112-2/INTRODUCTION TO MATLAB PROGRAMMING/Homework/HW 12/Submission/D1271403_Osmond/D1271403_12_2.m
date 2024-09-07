t = [0 1 2 3 4 5 6];
temp = [300 150 75 35 12 5 2];
y = polyfit(t, temp, 5);
plot(t, temp, 'o', t, polyval(y,t), '-')

n = 5