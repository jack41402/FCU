fh1 = @(x) 1+exp(-0.2.*x).*sin(x+2);

[x, y] = fminbnd(fh1, 0, 10);

fprintf("(x, y)=\n")

disp([x, y])

fplot(fh1, [0 10])

hold on;

fh2 = @(x) 1+exp(-0.2.*x).*sin(x+c);

c=2.5;

[x, y] = fminbnd(fh2, 0, 10);

fprintf("(x, y)=\n")

disp([x, y])

fplot(fh2, [0 10])
