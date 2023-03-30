A = [1:3 ; 4:6 ; 7:9] ;

% Interchange 2nd and 3rd column
A(:,[2 3]) = A(:,[3 2])

% Add 4th column of 0s
four = zeros(3 , 1) ;
A(:,4) = four

% Insert 2nd row of 1s
temp = ones(1 , size(A , 2)) ;
A = [A(1,:) ; temp ; A(2:end,:)]

% Remove 2nd column
A(:,2) = []