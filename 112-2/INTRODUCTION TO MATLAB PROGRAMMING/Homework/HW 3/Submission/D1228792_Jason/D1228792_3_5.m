N = 20;
L = 50000;
r = 0.15;
P = (r.*L.*(1+r./12).^(12.*N))./(12.*((1+r./12).^(12.*N)-1));
fprintf("%.4f\n",P)
N = 20 : 1 : 1000;
P = (r.*L.*(1+r./12).^(12.*N))./(12.*((1+r./12).^(12.*N)-1));
plot(N,P)
disp("no");
a=0;
N = 20;
L = 50000;
r = 0.15;
for i = 1:16
    P = (r.*L.*(1+r./12).^(12.*N))./(12.*((1+r./12).^(12.*N)-1));
    if(i>1)
        a=P-lp;
        fprintf("%.4f\n",a);
    end
    lp = P;
    r = r + 0.01;
end

