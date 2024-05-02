x = 3
fprintf("The result of exponential function is %.6f", taylor(x))
function result = taylor(x)
    term = 1;
    result = term;
    n = 1;
    nume = x;
    deno = 1;
    i = 0;
    while abs(term) >= 1e-6
        deno = deno*n;
        term = nume/deno;
        result = result + term;
        n = n + 1;
        nume = nume*x;
    end
end

