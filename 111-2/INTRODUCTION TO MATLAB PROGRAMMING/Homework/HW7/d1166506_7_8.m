t = 1:0.00001:3 ;
A = -800 + 320.*t ;
B = 410 - 160.*t ;
D = sqrt((A.*A)+(B.*B)) ;

[minD , minIdx] = min(D) ;
format short
minTime = t(minIdx)

% Plot the distance D as a function of time
plot(t, D) ;
xlabel('Time') ;
ylabel('Distance') ;
xlim([1 minTime])