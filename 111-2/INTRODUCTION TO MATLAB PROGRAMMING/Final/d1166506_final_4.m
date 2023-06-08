c = readcell("test_score1.xls") ;

midterm = [c{2:29 , 5}] ;
final = [c{2:29 , 6}] ;

midterm_avg = mean(midterm)
final_avg = mean(final)

% histogram(midterm)
h = histogram(midterm , 60:5:100) ;
