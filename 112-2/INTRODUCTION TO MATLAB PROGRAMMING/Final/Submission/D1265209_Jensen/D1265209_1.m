x=0:0.004:1;
n=0:3
B1 = @(x) sum(factorial(n)./factorial(n-k).*factorial(k)).*;


figure; 
figure1 = plot(x, B1, 'DisplayName', 'B1(x)');
hold on;
figure2 = plot(x, B2, 'DisplayName', 'B2(x)');
hold on;
figure3 = plot(x, B3, 'DisplayName', 'B3(x)');
hold on;
figure4 = plot(x, B4, 'DisplayName', 'B4(x)');
hold off;
legend show
figure1.Color = 'Black'
figure1.LineStyle = '-'
figure2.Color = 'Blue'
figure2.LineStyle = '-.'
figure3.Color = 'Red'
figure3.LineWidth = 10
figure3.LineStyle = '.'
figure4.LineStyle = '--.'
xlabel('x');
ylabel('y');
handle = gcf
