units = [200, 500, 700, 1000, 1500];

for i = 1:length(units)
    unit = units(i);
    if unit <= 500
        cost = 5 + (0.02 * unit);
    elseif unit <= 1000
        cost = 5 + 10 + 0.05 * (unit - 500);
    else
        cost = 5 + 35 + 0.1 * (unit - 1000);
    end

    fprintf('%d ', cost)
end


