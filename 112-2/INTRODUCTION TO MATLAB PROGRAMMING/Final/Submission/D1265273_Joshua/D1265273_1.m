x = 0:0.004:1;
n = 0;
k = 0;
B1 = (factorial(n)/(factorial(n-k).*factorial(k))).*1.*x.^(n-k);
n =n+1;
B2 = B1 + (factorial(n)/(factorial(n-k).*factorial(k))).*B1.*x.^(n-k);
n = n+1;
B3 = B1 + B2 + (factorial(n)/(factorial(n-k).*factorial(k))).*B2.*x.^(n-k);
n = n+1;
B4 = B1 + B2 + B3 + B1 + B2 + B3 + (factorial(n)/(factorial(n-k).*factorial(k))).*B3.*x.^(n-k);
a = plot( B1)
hold on
b = plot (B2)
c = plot(B3)
d = plot(B4)
legend
hold off