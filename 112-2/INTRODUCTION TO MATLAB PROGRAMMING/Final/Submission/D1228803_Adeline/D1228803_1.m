%D1228803_1

k = 0;

%ncr = factorial(n)/(factorial(n - k) * factorial(k));

tic
n = k:3;
%x = 0:0.004:1;


B = sum(B * ncr) * x;
toc

ncr = factorial(n)/(factorial(n - k) * factorial(k));
plot(x, B);
legend('B1(x)', 'B2(x)', 'B3(x)', 'B4(x)');
figure;
