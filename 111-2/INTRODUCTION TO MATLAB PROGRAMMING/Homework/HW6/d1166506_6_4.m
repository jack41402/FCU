income = [5000 10000 15000 22000 30000 38000 50000] ;
for i=income
    if (i<=10000) tax = 0.1*i ;
    elseif (i<=20000) tax = 1000 + 0.2*(i-10000) ;
    elseif (i<=40000) tax = 3000 + 0.3*(i-20000) ;
    else tax = 9000 + 0.5*(i-40000) ;
    end
    format compact;
    disp([i tax])
end