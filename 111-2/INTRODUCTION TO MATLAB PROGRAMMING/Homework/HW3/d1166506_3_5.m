% Define the function of population
P = @(x) 197273000./(1+exp(-0.03134*(x-1913.25)));

% Find the steady state
x = 1900 ;
now = -2 ;
while true
    next = P(x) ;
    if (abs(next-now)<1)
        break ;
    end
    now = next ;
    x = x + 1 ;
end
fprintf("%d\n" , x) ;

% Plot the graph
x = 1790:10:2000 ;
y = P(x) ;
plot(x , y) ;
title("Population") ;