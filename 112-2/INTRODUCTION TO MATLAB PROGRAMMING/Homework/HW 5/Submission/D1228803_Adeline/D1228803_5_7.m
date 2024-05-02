electricity = [200, 500, 700, 1000, 1500];
cost = zeros(size(electricity));
for i = 1:length(electricity)
    if electricity(i) <= 500
        cost(i) = electricity(i) * 0.02 + 5;
    elseif electricity(i) <= 1000
        cost(i) = (electricity(i) - 500) * 0.05 + 10 + 5; 
    else
        cost(i) = (electricity(i) - 1000) * 0.1 + 35 + 5; 
    end
end

disp([electricity' cost']);