units = [200, 500, 700, 1000, 1500];

for i = 1:5
    if units(i) <= 500
        disp(units(i)*0.02+5);
    elseif units(i) > 500 && units(i) <= 1000
        disp(0.05*(units(i)-500)+10+5);
    elseif units(i) > 1000
        disp(0.1*(units(i)-1000)+35+5);
    end
end