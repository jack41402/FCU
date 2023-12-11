% Define the function of payment
N = @(r , L , P) (log(P/(P-r*L/12)))/(12*log(1+r/12)) ;
P = @(r, L, N) (r*L*(1+r/12)^(12*N))/(12*((1+r/12)^(12*N)-1)) ;

% Find the years take to pay off the loan
fprintf("a.%.1f\n" , N(0.15 , 50000 , 800)) ;

% Find the smallest monthly payment 
fprintf("b.") ;
i = 0 ;
p = 1e8 ;
while (p>(0.15*50000)/12)
    i = i + 1 ;
    p = P(0.15 , 50000 , i) ;
end
fprintf("less than %d\n" , p) ;