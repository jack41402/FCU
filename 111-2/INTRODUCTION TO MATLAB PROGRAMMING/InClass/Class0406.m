value = 1 ;
x = 3 ;
re = 1e-6 ;
step = 1 ;
myerr = 1 ;
while (myerr>re)
    value_old = value ;
    value = value + (x.^step)./(fact(step)) ;
    disp([step value]) ;
    step = step + 1 ;
    myerr = value - value_old ;
end
disp([x value])