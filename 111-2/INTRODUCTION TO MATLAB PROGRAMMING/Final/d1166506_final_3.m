% (a)
bridge(1) = struct("Location" , "Smith St." , "Max_load" , 80 , ...
                   "Year_built" , 1928 , "Due_for_maintenance" , 2011) ;
bridge(2) = struct("Location" , "Hope Ave." , "Max_load" , 90 , ...
                   "Year_built" , 1950 , "Due_for_maintenance" , 2013) ;
bridge(3) = struct("Location" , "Clark St." , "Max_load" , 85 , ...
                   "Year_built" , 1933 , "Due_for_maintenance" , 2012) ;
bridge(4) = struct("Location" , "North Rd." , "Max_load" , 100 , ...
                   "Year_built" , 1960 , "Due_for_maintenance" , 2012) ;

% (b)
bridge(3).Due_for_maintenance = 2018 ;

% (c)
c = [bridge(:).Due_for_maintenance]

% (d)
[x , index] = sort(c , "ascend") ;
[bridge(index).Location]