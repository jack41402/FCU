units = [200,500,700,1000,1500];

fprintf('charge = \n')
for i=1:length(units)
    unit = units(i);
    if unit<=500
        total = 5 + (unit*0.02);
    elseif unit<=1000
        total = 5 + 10 + (unit - 500)*0.05;
    else
        total = 5 + 35 +(unit - 1000)*0.1;
    end


fprintf('     %d',total)

end











