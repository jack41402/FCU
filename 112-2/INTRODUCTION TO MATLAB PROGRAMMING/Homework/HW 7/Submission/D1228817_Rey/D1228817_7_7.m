
for i=0:20
    fprintf("%2d%10d\n", i, fib(i));
end


function y=fib(x)

    if x==0
        y=1;

    else if x==1
        y=1;

    else 
        y=fib(x-2)+fib(x-1);

    end
    end

end




