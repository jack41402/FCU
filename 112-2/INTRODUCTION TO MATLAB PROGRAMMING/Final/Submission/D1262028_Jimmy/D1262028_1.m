x = 0:0.004:1;
B0 = 1;


figure;
B1 = plot(x, B1, '-r', 'LineWidth', 1.5); 
hold on;
B2 = plot(x, B2, '-b', 'LineWidth', 1.5); 
hold on;
B3 = plot(x, B3, '-g', 'LineWidth', 1.5); 
hold on;
B4 = plot(x, B4, '-y', 'LineWidth', 1.5); 
legend('B1(x)', 'B2(x)', 'B3(x)', 'B4(x)'); 
hold off;

B1.LineStyle = "-";
B2.LineStyle = "--";
B3.LineStyle = ":";
B4.LineStyle = "-.";