clearvars;
times = 0:6; 
temperatures = [300 150 75 35 12 5 2];
polyfit(times, temperatures, 5);
plot(times, temperatures, 'o', times, temperatures);