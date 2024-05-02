for i=0:1:20
    fprintf("%2d %7d\n", i, f(i))
end

function y = f(x)

if(x==1 || x==0)
y = 1;

else 
    y =f(x-2)+f(x-1);
end
end
