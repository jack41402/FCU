unit = [200 500 700 1000 1500];
charge = [];
for i = 1:5
    if unit(i) <= 500
        charge(i) = unit(i) * 0.02;
    elseif unit(i) > 500 & unit(i) <= 1000
        charge(i) = 10 + (unit(i)-500) * 0.05;
    elseif unit(i) > 1000
        charge(i) = 35 + (unit(i)-1000) * 0.1;
    end
    charge(i) = charge(i) + 5;
end
charge = charge
