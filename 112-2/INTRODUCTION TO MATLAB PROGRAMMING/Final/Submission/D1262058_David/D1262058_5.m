format bank
C = readcell("test_score1.xls");
total_mid = 0;
total_fianl = 0;
for i = 2:29
    total_mid = total_mid + C{i, 5};
    total_fianl = total_fianl + C{i, 6}
end 
fprintf("Mean of mid-term scores: %.2f\n",total_mid/28);
fprintf("Standard deviation of mid-term scores: \n");
fprintf("Mean of final scores: %.2f\n", total_fianl/28);
fprintf("Standard deviation of final scores: \n");