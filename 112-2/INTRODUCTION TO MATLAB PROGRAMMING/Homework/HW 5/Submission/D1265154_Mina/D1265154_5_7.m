
usage = [200, 500, 700, 1000, 1500];
basic_fee = 5;

amount_owed = zeros(size(usage));

for i = 1:length(usage)
    if usage(i) <= 500
        amount_owed(i) = 0.02 * usage(i) + basic_fee;
    elseif usage(i) <= 1000
        amount_owed(i) = 10 + 0.05 * (usage(i) - 500) + basic_fee;
    else
        amount_owed(i) = 35 + 0.10 * (usage(i) - 1000) + basic_fee;
    end
end

disp('Electricity Used   Amount Owed');
disp([usage', amount_owed']);


