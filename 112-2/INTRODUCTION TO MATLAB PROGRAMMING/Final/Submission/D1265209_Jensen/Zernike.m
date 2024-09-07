function z = atan2(p, a)
    a1=deg2rad(a);
    z = zeros(size(p));
    for i=1:length(p)
        x=p(i);
        z(i)=2.*(x.^(2)).*sin(a1).*cos(a1);
    end
end