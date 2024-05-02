consumptions = [200, 500, 700, 1000, 1500];
total_charges = zeros(1, length(consumptions));

for i = 1:length(consumptions)
    consumption = consumptions(i);
    basic_fee = 5;
    total_cost = basic_fee;
    
    if consumption <= 500
        total_cost = total_cost + consumption * 0.02;
    elseif consumption <= 1000
        total_cost = total_cost + (500 * 0.02) + ((consumption - 500) * 0.05);
    else
        total_cost = total_cost + (500 * 0.02) + (500 * 0.05) + ((consumption - 1000) * 0.1);
    end
    
    total_charges(i) = total_cost;
end

charge = total_charges

