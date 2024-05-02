for i = 0:1:20
    fprintf("%2d%8d\n",i,fib(i))
end
function y = fib(x)
if(x > 0)
    y = fib(x-1) + fib(x-2);
elseif(x == 0)
    y=1;
else 
    y = 0;
end
end
