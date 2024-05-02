P_c = [6 2 1; 2 5 4; 4 3 2; 9 7 3];
P_v = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];

q_c_m = sum(P_c(:,[1]).*P_v).*10^3;
fprintf('Quarterly costs for materials: %d, %d, %d, %d\n', q_c_m)
q_c_l = sum(P_c(:,[2]).*P_v).*10^3;
fprintf('Quarterly costs for labor: %d, %d, %d, %d\n', q_c_l)
q_c_t = sum(P_c(:,[3]).*P_v).*10^3;

fprintf('Quarterly costs for transportation: %d, %d, %d, %d\n\n', q_c_t)
fprintf('Total costs for materials: %d\n', sum(q_c_m))
fprintf('Total costs for labor: %d\n', sum(q_c_l))
fprintf('Total costs for transportation: %d\n\n', sum(q_c_t))

fprintf('The Total quarterly costs: ')
for i=1:1:3;
    for j=1:1:4;
        q_cost(i,j) = sum(P_c(:, i).*P_v(:, j));
    end
end
for i=1:1:4
    fprintf("%d, ", sum(q_cost(:, i).*10^3))
end

