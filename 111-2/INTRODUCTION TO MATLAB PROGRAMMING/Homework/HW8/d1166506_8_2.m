f = @(x) 1 + exp(-0.2.*x).*sin(x+2) ;

% (a) Find the minimum value for the function
[x , y] = fminbnd(f , 0 , 10) ;
fprintf("(x, y)=\n");
disp([x , y])

% (b) Use fplot to plot this function
fplot(f , [0 10])
hold on

% (c) c=2.5
c = 2.5 ;
f = @(x) 1 + exp(-0.2.*x).*sin(x+c) ;
[x , y] = fminbnd(f , 0 , 10) ;
fprintf("(x, y)=\n");
disp([x y])
fplot(f , [0 10])