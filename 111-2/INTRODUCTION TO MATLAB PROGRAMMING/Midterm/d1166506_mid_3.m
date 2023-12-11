A = 2000 ;
L = @(R) (A-0.5*pi*(R.^2))./(2.*R) ;
cost = @(R) 2*L(R)*40 + 2*R*40 + pi*R*50 ;
R = fminsearch(cost , 0) ;
fprintf("Radius: %f\n" , R) ;
fprintf("Length: %f\n" , L(R)) ;
fprintf("Cost: %f\n" , cost(R)) ;