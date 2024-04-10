%part a
r=0.15;
L=50000;
N=20;
P=(r*L*(1+r/12)^(12*N))/12/((1+r/12)^(12*N)-1);
fprintf("%.2f\n",P)

%part b
N=20:1000;
P=(r.*L.*(1+r./12).^(12.*N))./12./((1+r./12).^(12.*N)-1);
plot(N,P);
disp("no")

%part c
r=0.15;
for i=1:20
    now = rate*50000*(1+rate/12)^(12*20)/(12*(1+rate/12)^(12*20)-1);
    if(i>1)
        disp(now-last)
    end
    rate = rate+0.01;
    last=now;
end

