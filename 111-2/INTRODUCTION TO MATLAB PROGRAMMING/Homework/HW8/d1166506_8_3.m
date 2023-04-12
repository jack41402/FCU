h = 1 ;
x = 1 ;
while (h>1e-6)
    y = newquot(x , h) ;
    h = h * 0.1 ;
end
disp(y)