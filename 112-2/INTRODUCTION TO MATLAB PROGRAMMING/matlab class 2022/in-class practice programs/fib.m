function y = fib(n)
fib(1)=1;
for i=2:n
    if (i<3)
        fib(i)=1+fib(i-1);
    else
    fib(i)=fib(i-2)+fib(i-1);
    end
    disp(fib(i));
end

