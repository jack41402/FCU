% (1)
score = table2struct(readtable("test_score1.xls" , 'VariableNamingRule', 'preserve')) ;

% (2)
score(29) = struct("x__" , "29" , "x___1" , "Average score" , "x___2" , "" , ...
                   "x____" , mean([score.x____]) , "x_____1" , mean([score.x_____1]) , ...
                   "x_____2" , mean([score.x_____2]) , "x_____3" , [] , ...
                   "x_____4" , [] , "x_____5" , []) ;

% (3)
writetable(struct2table(score) , "answer.xlsx")