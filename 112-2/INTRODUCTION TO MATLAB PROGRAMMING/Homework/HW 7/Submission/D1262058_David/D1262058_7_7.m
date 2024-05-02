fprintf("%5d%10d\n",0 ,1);
fprintf("%5d%10d\n",1 ,1);
fib(1, 1, 1);
function y =  fib(a, b, p)
    y = a + b;
    if(p < 20)
        p = p + 1;
        fprintf("%5d%10d\n",p ,y);
        fib(b, y, p);
    end
end
