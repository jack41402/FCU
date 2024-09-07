a = zeros(1,30);
i = (2:2:100);
n = 2;
a(1) = 1;

while abs(sum(a)-cos(3))>10^-4
    a(n) = (-1).^(n-1).*(3.^i(n-1)) ./ factorial(i(n-1));
    n=n+1;
end

for j = 1:n-1
    fprintf("%d  %.4f\n",j,sum(a(1:j)));
end
