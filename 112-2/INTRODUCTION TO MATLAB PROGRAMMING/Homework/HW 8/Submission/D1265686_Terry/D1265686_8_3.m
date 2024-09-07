n = 1;
a = zeros(1,1000);

while sum(a) + n^2 <= 1000
    a(n) = n^2;
    n = n + 1;
end

n = n - 1

ans = sum(a)
