% (a)
y = @(x) 10*exp(-2*x) ;
fplot(y , [0 2])

% (b)
figure
y = @(x) 20*x.^2-200*x+3 ;
x = 0:0.01:0.2 ;
plot(x , y(x))
[t , index] = min(abs(y(x))) ;
fprintf("f(x)=0 is approximated at x=%f\n" , x(index))

%(c)
fzero(y , 0)
fzero(y , 100)