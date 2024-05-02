usage = [200, 500, 700, 1000, 1500];
amount_owed = zeros(size(usage));
basic_fee = 5;


amount_owed(usage <= 500) = basic_fee + 0.02 * usage(usage <= 500);
over_500 = usage > 500 & usage <= 1000;
amount_owed(over_500) = basic_fee + 10 + 0.05 * (usage(over_500) - 500);
over_1000 = usage > 1000;
amount_owed(over_1000) = basic_fee + 35 + 0.10 * (usage(over_1000) - 1000);


for i = 1:length(usage)
    fprintf('%8d\t%8d\n', usage(i), amount_owed(i));
end
