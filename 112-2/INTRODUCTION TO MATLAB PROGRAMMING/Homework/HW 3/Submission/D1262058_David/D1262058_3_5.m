p = (0.15*50000*(1+0.15/12)^(12*20))/(12*((1+0.15/12)^(12*20)-1));
fprintf("%.2f\n", p);

n = 20:1:1000;
p = (0.15.*50000.*(1+0.15/12).^(12.*n))./(12.*((1+0.15/12).^(12.*n)-1));
plot(n,p)
disp("no");

r = 0.15;
last = 1;
for i = 1:16
    p = (r.*50000.*(1+r./12).^(12.*20))./(12.*((1+r./12).^(12.*20)-1));
    if (i>1)
    diff = p - last
    end
    r = r + 0.01;
    last = p;
end


