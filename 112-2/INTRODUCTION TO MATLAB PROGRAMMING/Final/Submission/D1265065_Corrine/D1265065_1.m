B0 = @(x) 1;
B1 = @(x) 1;
B2 = @(x) 2*x+1;
B3 = @(x) 5*x+1;
B4 = @(x) 15*x+1;
x = 0:0.004:1;

y1 = B1(x);
y2 = B2(x);
y3 = B3(x);
y4 = B4(x);

figure;
hold on;
h1 = plot(x, y1, 'DisplayName', 'P1(x)');
h2 = plot(x, y2, 'DisplayName', 'P2(x)');
h3 = plot(x, y3, 'DisplayName', 'P3(x)');
h4 = plot(x, y4, 'DisplayName', 'P4(x)');
hold off;

legend ('B(1)','B(2)','B(3)','B(4)');
hLines = findobj(fig, 'Type', 'Line','Color','r');
set(h3, 'Color', 'r', 'LineWidth', 1.5, 'LineStyle', ':');
