x = 3
s = 0; 
n = 0;
while abs(x^n/myfactorial(n)) >= 1e-6
    s = s + x^n/myfactorial(n); % compute the series
    n = n + 1; % increment n
end
fprintf('The result of exponential function is %6f\n', s);
function a = myfactorial(b)
a = 1 ; 
for i = 1:b
    a = a*i ; 
end
end

