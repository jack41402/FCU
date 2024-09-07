x = [0 1 2 3 4 5];
Y = [20 25 27 28 27 25];
ft = fittype('a*(x-b)^n','problem','n','options',fo);
[curve2,gof2] = fit(cdate,pop,ft,'problem',2)