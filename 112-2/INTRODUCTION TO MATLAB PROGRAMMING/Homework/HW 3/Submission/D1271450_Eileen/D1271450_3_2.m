units = [200, 500, 700, 1000, 1500];
fee=5;
fprintf('charge=\n     ')
for i=1:length(units)
    unit =units(i);
    if unit <= 500
        total_charge=fee+(0.02*unit);
    
    elseif unit > 1000
    total_charge=fee+35+(unit-1000)*0.1;

    else
    total_charge=fee+10+(unit-500)*0.05;

    end
fprintf('%d    ',total_charge)
end