x = input('') ;
y = input('') ;
[x , y] = swop(x , y) ;
disp([x y])

function [x , y] = swop(x , y)
    temp = x ;
    x = y ;
    y = temp ;
end