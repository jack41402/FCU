ans = 0;
n = 1;

while(1)
    t = n.^2;
    if(ans + t >1000)
        break
    else
      ans = ans + t;
      n = n+1;
    end
end
n = n-1
ans