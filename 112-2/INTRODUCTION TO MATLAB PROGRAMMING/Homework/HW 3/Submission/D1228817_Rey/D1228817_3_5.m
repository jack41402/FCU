N=20;
r=0.15;
L=50000;

P=@(N, r, L) (r*L*((1+r/12)^(12*N)))/(12*((1+r/12)^(12*N)-1));

fprintf("%.4f\n", P(N, r, L));

n=20:1000;
p=(r.*L.*((1+r./12).^(12.*n)))./(12.*((1+r./12).^(12.*n)-1));
plot(n, p);

for i=1:15
    last= P(N, r, L);
    r=r+0.01;
    now=P(N, r, L);
    fprintf("%.4f\n", now-last);

end
