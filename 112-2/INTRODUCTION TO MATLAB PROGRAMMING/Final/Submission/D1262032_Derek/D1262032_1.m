x=0:0.004:1;
B=cell(1, 5);
B{1}=ones(size(x));
bi=@(n, k) factorial(n)./(factorial(k).*factorial(n - k));
for n=1:4
    B{n+1}=zeros(size(x));
    for k=0:n-1
        B{n+1}=B{n+1}+bi(n-1, k).*B{k+1}.*x.^(n-k-1);
    end
end
figure;
hold on;
h1=plot(x, B{2}, 'r-');
h2=plot(x, B{3}, 'g--');
h3=plot(x, B{4}, 'm:');
h4=plot(x, B{5}, 'b-.');
legend('B1(x)', 'B2(x)', 'B3(x)', 'B4(x)');
h3.Color='magenta';
h3.LineWidth=2;
h3.LineStyle=':';
hold off;

