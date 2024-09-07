clear;
Test=readtable("test_score1.xls");
Test=table2struct(Test);

Test(29).x__='29';
Test(29).x___1="Average score";

a=[Test(1:28).x____];
b=[Test(1:28).x_____1];
c=[Test(1:28).x_____2];

Test(29).x____=mean(a);
Test(29).x_____1=mean(b);
Test(29).x_____2=mean(c);

out=struct2table(Test);
writetable(out, "Excel_test_score1_HW.xls");
