unit = [200 500 700 1000 1500];
for i=1:5
    if unit(i)<=500
        cost = 0.02;
charge(i) = cost*unit(i)+5;

    elseif unit(i)<=1000
        cost1 = 0.05;
        charge(i) = 10 + (unit(i)-500)*cost1+5;
        
    else
        cost2 = 0.1;
        charge(i) = 35+ (unit(i)-1000)*cost2+5;
    end
end

display(charge);