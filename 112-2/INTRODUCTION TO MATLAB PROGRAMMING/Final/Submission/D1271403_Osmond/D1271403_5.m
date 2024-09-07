clear;
T=readcell('test_score1.xls');
T=cell2struct(T);

scores=[T.x____; T.x_____1; T.x_____2];
T(29).x__='29';
T(29).x___1='Average score';
T(29).x____=mean(scores(1, :));
T(29).x_____1=mean(scores(2, :));
T(29).x_____2=mean(scores(3, :));
T(29).x____=std(scores(1, :));
T(29).x_____1=std(scores(2, :));
T(29).x_____2=std(scores(3, :));
T=struct2table(T);
writetable(T, 'Excel_test_score1.xls');
histogram(x,)