X=0:1:5;
Y=[20,25,27,28,27,25];
a = polyfit(X,Y,4);
y = polyval(a,3.6)
fittype