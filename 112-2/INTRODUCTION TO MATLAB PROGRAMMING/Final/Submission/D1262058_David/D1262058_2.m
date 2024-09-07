time  = [0,1,2,3,4,5];
temp = [20, 25, 27, 28, 27, 25];
p = polyfit(time,temp,4);
y = polyval(p, 3.6)
fittype()
fprintf("SSE: \n");
fprintf("R-squred: \n");


