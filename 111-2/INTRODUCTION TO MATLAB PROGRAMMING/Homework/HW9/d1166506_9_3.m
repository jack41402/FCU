ans = 0 ;
n = 1 ;
while true
    ans = ans + n^2 ;
    if ans>1000
       break
    end
    n = n + 1 ;
end
n = n - 1
ans = ans - (n+1)^2