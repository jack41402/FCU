electricity = [200 500 700 1000 1500];
cost = zeros(size(electricity));
cost(electricity <= 500) = electricity(electricity <= 500)*0.02 + 5;
cost(electricity > 500 & electricity <= 1000) = (electricity(electricity > 500 & electricity <= 1000)-500)*0.05 + 15;
cost(electricity > 1000) = (electricity(electricity > 1000)-1000)*0.1 + 40;
total = [electricity; cost]'

