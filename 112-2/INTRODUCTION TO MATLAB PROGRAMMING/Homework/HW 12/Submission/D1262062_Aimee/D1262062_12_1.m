Year = 2004:2009;
pop = [10, 10.9, 11.7, 12.6, 13.8, 14.9];
pop = pop * 1000000;

p = polyfit(Year, log(pop), 1);
a = exp(p(2));
b = p(1);

Year_fit = linspace(2004, 2009);
pop_fit = a * exp(b * Year_fit);

target_pop = 2 * pop(1);
t = log(target_pop/a) / b;
fprintf("t =\n\t\t%6.2f", t)

figure;
plot(Year, pop, 'o', 'MarkerSize', 8); 
hold on;
plot(Year_fit, pop_fit); 
hold off;
