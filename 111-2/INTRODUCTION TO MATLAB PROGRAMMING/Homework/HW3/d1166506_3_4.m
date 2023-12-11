% initialize the variables
deposit = 100000 ;

% main program
for i=1:12
    if (deposit<=110000)
        interest = 0.01 ;
    elseif (deposit<=125000)
        interest = 0.015 ;
    else
        interest = 0.02 ;
    end
    fprintf("%d %.3f %.2f " , i , interest , deposit*interest) ;
    deposit = deposit * (1 + interest) + 1000 ;
    fprintf("%.2f\n" , deposit) ;
end