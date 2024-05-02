%5.7
electricity_used = [200, 500, 700, 1000, 1500];

cost = zeros(size(electricity_used));

basic_service_fee = 5;

for i = 1:length(electricity_used)
    if electricity_used(i) <= 500
        cost(i) = 0.02 * electricity_used(i);
    elseif electricity_used(i) <= 1000
        cost(i) = 10 + 0.05 * (electricity_used(i) - 500);
    else
        cost(i) = 35 + 0.10 * (electricity_used(i) - 1000);
    end
    cost(i) = cost(i) + basic_service_fee;
end

for i = 1:length(electricity_used)
    fprintf('%d\t\t%d\n', electricity_used(i), cost(i));
end