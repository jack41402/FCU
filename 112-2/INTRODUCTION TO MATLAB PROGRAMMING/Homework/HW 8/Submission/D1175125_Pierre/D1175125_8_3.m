n = 1;
sum = 0;
while sum + n^2 <= 1000
    sum = sum + n^2;
    n = n+1;
end
fprintf('n = \n');
disp(n-1);
fprintf('ans = \n');
disp(sum);