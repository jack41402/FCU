x = input('x = ');
n = 30; 
i = 0;
f = 1;
while i <= n
    last_term = (x.^i) / factorial(i);
    if (x.^i) / factorial(i)<0.000001
        break
    elseif i == n && last_term > 0.000001
        break
    end
    f = f + last_term;
    i = i + 1;
end
y = f - 1;
fprintf('The result of exponential function is %.6f\n', y);