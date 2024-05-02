unit = [200 500 700 1000 1500];
charge = [];
for i = 1:5
    if unit(i) <= 500
       charge(i) = 0.02 * unit(i);
    elseif unit(i) > 500 & unit(i) <= 1000
       charge(i) = 0.05 * (unit(i)-500) + 10;
    elseif unit(i) > 1000
       charge(i) = 0.1 * (unit(i)-1000) + 35;
    end
    charge(i) = charge(i) + 5;
end
charge = charge