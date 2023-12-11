clear S
S(1) = struct("name" , "Ed Plum" , "score" , 83 , "grade" , "B+") ;
S(2) = struct("name" , "Toni Miller" , "score" , 91 , "grade" , "A-") ;
S(3) = struct("name" , "Jerry Garcia" , "score" , 70 , "grade" , "C") ;

% (1)
S(2).name

% (2)
fprintf("%12s %d %s\n" , S(1).name , S(1).score , S(1).grade) ;
fprintf("%12s %d %s\n" , S(2).name , S(2).score , S(2).grade) ;
fprintf("%12s %d %s\n" , S(3).name , S(3).score , S(3).grade) ;

% (3)
S(3).score = 50 ;

% (4)
S = rmfield(S , "grade") ;

% (5)
C = struct2cell(S)