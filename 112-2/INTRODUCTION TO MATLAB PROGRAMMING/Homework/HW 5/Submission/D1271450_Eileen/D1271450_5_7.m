units = [200, 500, 700, 1000, 1500];

% Preallocate arrays to store results
amount_owed = zeros(size(units));

% Calculate amount owed based on units
for i = 1:numel(units)
    if units(i) < 500
        amount_owed(i) = 0.02 * units(i) + 5;
    elseif units(i) < 1000
        amount_owed(i) = 15 + 0.05 * (units(i) - 500);
    else
        amount_owed(i) = 40 + 0.1 * (units(i) - 1000);
    end
end

% Display results in two columns
disp('Electricity Used (Units)   Amount Owed');
disp([units' amount_owed']);
