y1 = @(x) 1+exp(-0.2.*x).*sin(x+2);
[x,y] = fminbnd(y1,0,10);
disp("(x,y)=")
disp([x,y])
fplot(y1,[0,10]);
hold on

c = 2.5;
y2 = @(x) 1+exp(-0.2.*x).*sin(x+c);
[x,y] = fminbnd(y2,0,10);
disp("(x,y)=")
disp([x,y])
fplot(y2,[0,10])
hold off