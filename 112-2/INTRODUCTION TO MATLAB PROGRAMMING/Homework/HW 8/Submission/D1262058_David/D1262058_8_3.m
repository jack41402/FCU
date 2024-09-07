ans = 0;
n = 1;

while(1)
    term = n.^2;
    if(ans + term >1000)
        break
    else
      ans = ans + term;
      n = n+1;
    end
end
n = n-1
ans