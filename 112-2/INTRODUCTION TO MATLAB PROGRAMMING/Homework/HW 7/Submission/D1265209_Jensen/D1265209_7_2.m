f = @(x) 1+exp(-0.2.*x).*sin(x+2);
    X=fminbnd(f,0,10)
    y=0:0.1:10;
    plot(y, 1+exp(-0.2.*y).*sin(y+2))
hold on;
f1 = @(x) 1+exp(-0.2.*x).*sin(x+c);
    c=2.5;
    X1=fminbnd(f1,0,10)
    y1=0:0.1:10;
    plot(y1, 1+exp(-0.2.*y1).*sin(y1+c))