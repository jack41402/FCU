% Define the function of payment
P = @(r, L, N) (r*L*(1+r/12)^(12*N))/(12*((1+r/12)^(12*N)-1)) ;

% Find the payment when N=20 and L=50000
fprintf("a.%.2f\n" , P(0.15 , 50000 , 20)) ;

% Find if any amount of payment less than 625
fprintf("b.") ;
find = false ;
for i=0:20
    if (P(0.15 , 50000 , i)<625)
        find = true ;
    end
end
if (find)
    fprintf("Yes\n") ;
else
    fprintf("No\n") ;
end

% Check if the monthly payment rose 37 or not
format("default") ;
fprintf("c.") ;
fprintf("%.2f\n" , P(0.16 , 50000 , 20)-P(0.15 , 50000 , 20)) ;