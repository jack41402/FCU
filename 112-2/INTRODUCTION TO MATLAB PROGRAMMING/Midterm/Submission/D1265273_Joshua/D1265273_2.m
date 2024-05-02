a = [6 2 1;2 5 4;4 3 2;9 7 3];
b =[10 12 13 15;8 7 6 4;12 10 13 9;6 4 11 5];
fprintf('Quarataerly cost for materials:%d, %d, %d, %d\n', sum(a(:,1).*b(:,1).*10^3), sum(a(:,1).*b(:,2).*10^3), sum(a(:,1).*b(:,3).*10^3), sum(a(:,1).*b(:,4).*10^3))
fprintf('Quarataerly cost for labor:%d, %d, %d, %d\n', sum(a(:,2).*b(:,1).*10^3), sum(a(:,2).*b(:,2).*10^3), sum(a(:,2).*b(:,3).*10^3), sum(a(:,2).*b(:,4).*10^3))
fprintf('Quarataerly cost for transportation:%d, %d, %d, %d\n\n', sum(a(:,3).*b(:,1).*10^3), sum(a(:,3).*b(:,2).*10^3), sum(a(:,3).*b(:,3).*10^3), sum(a(:,3).*b(:,4).*10^3))
fprintf('Total cost for materials: %d\n', sum(a(:,1).*b(:,1).*10^3)+ sum(a(:,1).*b(:,2).*10^3)+ sum(a(:,1).*b(:,3).*10^3)+ sum(a(:,1).*b(:,4).*10^3))
fprintf('Total cost for labor: %d\n',  sum(a(:,2).*b(:,1).*10^3)+ sum(a(:,2).*b(:,2).*10^3)+ sum(a(:,2).*b(:,3).*10^3)+ sum(a(:,2).*b(:,4).*10^3))
fprintf('Toal cost for transportation: %d\n\n', sum(a(:,3).*b(:,1).*10^3)+ sum(a(:,3).*b(:,2).*10^3)+ sum(a(:,3).*b(:,3).*10^3)+ sum(a(:,3).*b(:,4).*10^3))
fprintf('Total quarterly cost: %d %d %d %d', sum(a(:,1).*b(:,1).*10^3)+sum(a(:,2).*b(:,1).*10^3)+sum(a(:,3).*b(:,1).*10^3), sum(a(:,1).*b(:,2).*10^3)+sum(a(:,2).*b(:,2).*10^3)+sum(a(:,3).*b(:,2).*10^3), sum(a(:,1).*b(:,3).*10^3)+sum(a(:,2).*b(:,3).*10^3)+sum(a(:,3).*b(:,3).*10^3), sum(a(:,1).*b(:,4).*10^3)+sum(a(:,2).*b(:,4).*10^3)+sum(a(:,3).*b(:,4).*10^3))