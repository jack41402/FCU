f = @(x) 1 + exp(-0.2.*x)*sin(x+2) ;
[x , y] = fminbnd(f , 0 , 10);
disp([x y])
fplot(f , [0 10])