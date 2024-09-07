
function r = a(x, y)

    t = atan2(y, x);
    
    f = sqrt(x.^2 + y.^2);

    r = 2 .* (f.^2) .* sin(t) .* cos(t);
end
