x=0:0.004:1;



plot(x, b(1, x), 'b-.');
hold on;
plot(x, b(2, x), 'r--');
hold on;
B3=plot(x, b(3, x), 'g-');
hold on;
plot(x, b(4, x), 'c:');

legend('B1(X)', 'B2(X)', 'B3(X)', 'B4(X)');

B3.Color='M';
B3.LineWidth=3;
B3.LineStyle='--';


function y=b(n, x)
y=0;
if n==0
    y=1;
else
    y=y+factorial(n)/factorial(n-1).*B(n-1, x).*x.^(n-1);

end
    
end