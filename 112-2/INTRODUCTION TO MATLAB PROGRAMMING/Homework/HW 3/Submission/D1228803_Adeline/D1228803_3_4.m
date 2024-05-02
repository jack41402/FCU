P = @(t) 197273000 / (1 + exp(-0.03134 * (t - 1913.25)));
years = 1790:10:2000;
for i = 1:length(years)
    P_graph(i) = P(years(i));
end
fprintf('%s %s\n', 'Year', 'Population');
for i = 1:length(years)
    fprintf('%d %.2f\n', years(i), P_graph(i));
end

figure;
plot(years, P_graph);

grid on;
