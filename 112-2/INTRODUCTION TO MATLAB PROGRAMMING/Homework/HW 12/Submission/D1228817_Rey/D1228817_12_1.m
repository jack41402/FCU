clear;

X=[2004 2005 2006 2007 2008 2009];
Y=[10 10.9 11.7 12.6 13.8 14.9].*10^6;

%p1=polyfit(X, Y, 1);
p2=polyfit(X, Y, 2);

plot(X, Y, 'o', X, polyval(p2, X), '-');

t=2009;
eval=polyval(p2, t);


while abs((eval-2*Y(1))/10^6)>10^-3
    t=t+0.001;
    eval=polyval(p2, t);
end

fprintf('t=\n   %.2f', t);

