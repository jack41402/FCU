Labor = [2;5;3;7];
Materials = [6;2;4;9];
trans = [1;4;2;3];
quar = [10 12 13 15;8 7 6 4;12 10 13 9;6 4 11 5];
ans1 = Materials.*quar;
ans2 = sum(ans1)*10^3;
fprintf('Quarterly coasts for materials: ');
disp(ans2);
ans3 =sum( Labor.*quar)*10^3;
fprintf('Quarterly costs for labor: ');
disp(ans3);
ans4 = sum(trans.*quar)*10^3;
fprintf('Quarterly costs for transportation: ');
disp(ans4);
ans5 = sum(ans2);
fprintf('Total costs for materials: %d',ans5);
ans6 = sum(ans3);
fprintf('\nTotal costs for Labor: %d',ans6);
ans7 = sum(ans4);
fprintf('\nTotal costs for Transportation: %d',ans7);



