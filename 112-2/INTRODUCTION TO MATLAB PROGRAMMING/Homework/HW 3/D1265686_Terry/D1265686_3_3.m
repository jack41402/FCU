deposite=100000;

for i=1:12
    if deposite<=110000
        i_rate=0.01;

    elseif deposite<=125000
        i_rate=0.015;
        
    else 
        i_rate=0.02;
        
    end
    interest=(i_rate)*(deposite);
        deposite=deposite+interest+1000;
        fprintf("%d %.2f %.2f %.2f\n", i, i_rate, interest, deposite);
end