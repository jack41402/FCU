r = 1e7 ;
V = @(t) 1e9 + 1e8*(1-exp(-t/100)) - r*t ;
decrease = @(t) V(t)-1e9*0.5 ;
time = fzero(decrease , 0) ;
fprintf("%.0f days\n" , time) ;