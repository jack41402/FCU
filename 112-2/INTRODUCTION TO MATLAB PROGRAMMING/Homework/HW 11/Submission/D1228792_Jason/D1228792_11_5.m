clear score;
score = table2struct(readtable('test_score1.xls'));
a = mean(cat(1,score.x____));
b = mean(cat(1,score.x_____1));
c = mean(cat(1,score.x_____2));
score(29) = struct('x__','29','x___1','Average score','x___2','-','x____',a,'x_____1',b,'x_____2',c,'x_____3','','x_____4','','x_____5','');
writetable(struct2table(score),'test_score1NEW.xls')
