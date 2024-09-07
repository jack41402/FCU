function y =  final(x,y)
    p = @(x,y) sqrt(x.^2+y.^2);
    s = @(x,y) atan2(y./x,1);
    y = @(x,y) 2.*p.^2.*sin(s).*cos(s);
end

