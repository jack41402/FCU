unit = [6 2 1; 2 5 4; 4 3 2; 9 7 3];
unit = unit.*(10^3);
quarterly = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
q_materials = quarterly.*unit(:,1);
q_labors = quarterly.*unit(:,2);
q_trans = quarterly.*unit(:,3);
S1 = sum(q_materials);
S2 = sum(q_labors);
S3 = sum(q_trans);
fprintf('Quarterly costs for materials: ')
for n = 1:3
    fprintf('%d, ', S1(n))
end
fprintf('%d\n', S1(4))
fprintf('Quarterly costs for labor: ')
for n = 1:3
    fprintf('%d, ', S2(n))
end
fprintf('%d\n', S2(4))
fprintf('Quarterly costs for transportation: ')
for n = 1:3
    fprintf('%d, ', S3(n))
end
fprintf('%d\n', S3(4))
S4 = sum(S1);
S5 = sum(S2);
S6 = sum(S3);
fprintf('Total costs for materials: %d\n', S4)
fprintf('Total costs for labor: %d\n', S5)
fprintf('Total costs for transportation: %d\n', S6)
S7 = zeros(1, 4);
S7(1) = S1(1) + S2(1) + S3(1);
S7(2) = S1(2) + S2(2) + S3(2);
S7(3) = S1(3) + S2(3) + S3(3);
S7(4) = S1(4) + S2(4) + S3(4);
fprintf('The total quartely costs: ')
for n = 1:3
    fprintf('%d, ', S7(n))
end
fprintf('%d\n', S7(4))


