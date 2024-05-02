units = [200 500 700 1000 1500];
less_than_500 = units<=500;
between_500and1000 = (units>500 & units<=1000);
more_than_1000 = units>1000;
cost_less_than_500 = less_than_500.*units*0.02+5;
cost_between_500and1000 = (between_500and1000.*units-500)*0.05+15;
cost_more_than_1000 = (more_than_1000.*units-1000)*0.1+40;
cost=[];
cost(1,2) = cost_less_than_500(1,1);
cost(2,2) = cost_less_than_500(1,2);
cost(3,2) = cost_between_500and1000(1,3);
cost(4,2) = cost_between_500and1000(1,4);
cost(5,2) = cost_more_than_1000(1,5);
cost(:, 1)= units(1, :);
disp(cost)
fprintf("\n")
