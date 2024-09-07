sum = 0;
term = 0;
while sum<=1000
    term = term +1;
    sum = sum + term^2;
    if((sum + (term+1)^2)>1000)
        break
    end
end
n = term
ans = sum