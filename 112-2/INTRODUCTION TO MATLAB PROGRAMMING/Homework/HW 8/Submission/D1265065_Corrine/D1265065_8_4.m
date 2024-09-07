x = 3; % radians
tolerance = 1e-4; % desired tolerance for accuracy
cos_x_approx = compute_cos_approx(x, tolerance);

function cos_x_approx = compute_cos_approx(x, tolerance)
    cos_x_approx = 0;
    term = 1;
    n = 0;
    cosx = cos(x);
    while abs(cos_x_approx-cosx) >= tolerance
        term = (-1)^n * (x^(2*n)) / factorial(2*n);
        cos_x_approx = cos_x_approx + term;
        n = n + 1;
        fprintf('%d  %.4f\n',n,cos_x_approx)
    end
end