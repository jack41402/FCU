n = 0;
x = 0;
while(x < 1000)
    x = x + n .^ 2;
    if(x > 1000)
        x = x - n .^ 2;
        n = n - 1;
        break;
    end
    n = n + 1;
end
fprintf("n = \n    %d\n",n)
fprintf("ans = \n   %d\n",x)