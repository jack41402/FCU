function d = newquot(f, r)
    h = 1e-3;
    d = zeros(size(r));
    for i=1:length(r)
        x=r(i);
        d(i)=(f(x+h)-f(x))/h;
    end
end