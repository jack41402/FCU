x= 0:0.004:1; 
n_max = 4;
B = cell(1, n_max + 1);
B{1} = ones(size(x)); 
for n = 1:n_max
    B_n = zeros(size(x));
    for k = 0:n-1
        B_n = B_n + nchoosek(n-1, k) * B{k+1} .* x.^(n-k);
    end
    B{n+1} = B_n;
end

for n = 2:n_max+1
    B{n} = B{n} + 1;
end

figure;
a = plot(x, B{1}, 'DisplayName', 'B1(x)');
hold on;
b = plot(x, B{2}, 'DisplayName', 'B2(x)');
c = plot(x, B{3}, 'DisplayName', 'B3(x)');
d = plot(x, B{4}, 'DisplayName', 'B4(x)');
hold off;
a.Color = 'red';
a.LineStyle = ':';
a.LineWidth = 1;
b.Color = 'black';
b.LineStyle = '-';
b.LineWidth = 2;
c.Color = 'green';
c.LineStyle = ':';
c.LineWidth = 3;
d.Color = 'cyan';
d.LineStyle = '-';
d.LineWidth = 4;
yticks(0:5:15);
ylim([0, 16]);
xlim([0, 1]);
legend show;

