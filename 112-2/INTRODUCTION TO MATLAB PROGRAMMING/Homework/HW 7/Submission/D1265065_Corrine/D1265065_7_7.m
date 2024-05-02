for i = 0:20
    fprintf('%3d %7d\n', i, f(i));
end
function fibonacci = f(n)
    if (n == 0 || n == 1)
        fibonacci = 1;
    else
        fibonacci = f(n-1) + f(n-2);
    end
end
