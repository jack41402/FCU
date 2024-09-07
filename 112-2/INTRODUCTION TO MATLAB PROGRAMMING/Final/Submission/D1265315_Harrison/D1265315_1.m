x = 0:0.004:1;

B0 = ones(size(x));
B1 = x;
B2 = x.^2 + x;
B3 = x.^3 + 3*x.^2 + x;
B4 = x.^4 + 6*x.^3 + 7*x.^2 + x;

figure;
hold on;
plot(x, B1, '-', 'DisplayName', 'B1(x)');
plot(x, B2, '--', 'DisplayName', 'B2(x)'); 
plot(x, B3, ':',  'DisplayName', 'B3(x)');
plot(x, B4, '-.', 'DisplayName', 'B4(x)');
legend('show');
hold off;
