function D1271450_7_7()
function fibonacci = f(n)
    if n <= 0
        fibonacci = 1;
    elseif n == 1
        fibonacci = 1;
    else
        fibonacci = f(n-1) + f(n-2);
    end
end

for n = 0:20
    fprintf('%d = %d\n', n, f(n));
end
end







