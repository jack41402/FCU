%ok

sum = 0;
term = 0;
n = 1;

while sum <= 1000
    term = term + 1;
    sum = sum + n^2; 
    n = n + 1;
end

sum = sum - (n - 1)^2;
term = term - 1;

disp(['n = ', num2str(term)]);
disp(['ans = ', num2str(sum)]);
