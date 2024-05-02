unit = [200 500 700 1000 1500];
fprintf("charge =\n   ");
for i=1:5
    if (unit(i) <= 500)
        charge = 5 + unit(i) / 100 * 2;
        fprintf("%d  ", charge);
    elseif (500 < unit(i) && unit(i) <= 1000)
        charge = 15 + (unit(i) - 500) / 100 * 5;
        fprintf("%d  ", charge);
    elseif (1000 < unit(i))
        charge = 40 + (unit(i) - 1000) / 100 * 10;
        fprintf("%d  ", charge);
    end
end
