income=[5000 10000 15000 22000 30000 38000 50000];
for ti=income
    if ti<10000
        tax=0.1*ti;
    elseif ti<20000
        tax=1000 + 0.2*(ti-10000);
    elseif ti<40000
        tax=3000 + 0.3*(ti-20000);
    else 
        tax=9000+ 0.5*(ti-40000);
    end;
    disp([ti tax])
end;