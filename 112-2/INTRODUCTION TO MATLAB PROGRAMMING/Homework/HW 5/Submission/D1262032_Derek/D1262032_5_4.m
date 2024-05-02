units = [5000; 10000; 15000; 22000; 30000; 38000; 50000];
logical = [units<=10000, (units>10000)&(units<=20000), (units>20000)&(units<=40000), units>40000]
payable = [units*0.1, (units-10000)*0.2+1000, (units-20000)*0.3+3000, (units-40000)*0.5+9000]
result = logical.*payable
for i=1:7
    fprintf("%5d  ", units(i))
    for j=1:4
        if result(i,j)~=0 
            fprintf("%5d\n", result(i,j))
        end
    end
end
fprintf("\n")