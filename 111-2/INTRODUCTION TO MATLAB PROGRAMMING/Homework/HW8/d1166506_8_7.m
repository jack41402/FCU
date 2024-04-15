for i=0:20
    fprintf("%3d %7d\n", i, fibonacci(i));
    %disp([i fibonacci(i)])
end

function y = fibonacci(x)
    if (x==0) y = 1 ;
    elseif (x==1) y = 1 ;
    else
        y = fibonacci(x-1) + fibonacci(x-2) ;
    end
end