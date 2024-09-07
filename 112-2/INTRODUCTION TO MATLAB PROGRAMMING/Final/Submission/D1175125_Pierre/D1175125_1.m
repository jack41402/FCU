x_vals = 0:0.004:1; 

n_max = 4;

B = cell(1, n_max + 1);

B{1} = zeros(size(x_vals));

for n = 1:n_max
    B_n = ones(size(x_vals));
    for k = 0:n-1
        B_n = B_n + nchoosek(n-1, k) * B{k+1} .* x_vals.^(n-k);
    end
    B{n+1} = B_n;
end

for n = 2:n_max+1
    B{n} = B{n} + 1;
end

figure;
hold on;
colors = ['b', 'r', 'g', 'm'];
line_types = {'-', '--', ':', '-.'};

for n = 1:n_max
    plot(x_vals, B{n+1}, 'Color', colors(n), 'LineStyle', line_types{n}, 'DisplayName', sprintf('B%d(x)', n));
end

set(findobj('DisplayName', 'B3(x)'), 'Color', 'k', 'LineWidth', 2, 'LineStyle', '--');

legend;
xlabel('x');
ylabel('B_n(x)');
yticks(0:5:15);
ylim([0, 16]);
xlim([0, 1]); 
hold off;
