for i = 0:20
    fprintf('%2d   %5d\n', i, f(i));
end
function result = f(n)
    if n == 0 || n == 1
        result = 1;
    else
        result = f(n-1) + f(n-2);
    end
end 
