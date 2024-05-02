y = @(x)x^3 + x - 3;
dy = @(x)3*x^2 + 1;
steps = 0;
x = input( 'Initial guess: ');
re = 1e-8;
myrel = 1;
for i = 1 : 1 : 20;
    xold = x;
    x = x - y(x)/dy(x);
    steps = steps + 1;
    fprintf("\t%.4f  %8.4f\n",x,y(x))
    myrel = abs((x-xold)/x);
    if(myrel <=re)
        disp( 'Zero found at' )
        disp(x)
        break;
    elseif(i == 20)
        disp( 'Zero NOT found')
    end
end
