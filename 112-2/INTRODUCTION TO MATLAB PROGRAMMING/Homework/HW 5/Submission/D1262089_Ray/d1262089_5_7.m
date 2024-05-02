% Amounts of electricity used by each resident (units)
electricity_used = [200, 500, 700, 1000, 1500];

% Constants for electricity cost calculation
unit_cost_500 = 0.02;  % Cost per unit for 500 units or less
unit_cost_1000 = 0.05; % Cost per unit for more than 500 but not more than 1000 units
unit_cost_1000_plus = 0.1; % Cost per unit for more than 1000 units
basic_service_fee = 5; % Basic service fee

% Initialize array to store amounts owed by each resident
amount_owed = zeros(size(electricity_used));

% Calculate amount owed for each resident
for i = 1:numel(electricity_used)
    % Check the amount of electricity used by the resident
    if electricity_used(i) <= 500
        amount_owed(i) = electricity_used(i) * unit_cost_500;
    elseif electricity_used(i) <= 1000
        amount_owed(i) = 10 + (electricity_used(i) - 500) * unit_cost_1000;
    else
        amount_owed(i) = 35 + (electricity_used(i) - 1000) * unit_cost_1000_plus;
    end
    
    % Add the basic service fee
    amount_owed(i) = amount_owed(i) + basic_service_fee;
end

% Display the results
disp([electricity_used' amount_owed']);
