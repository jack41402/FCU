clear bridge;
bridge(1)=struct('Location', "Smith St.", 'Max_load', 80,'Year_build', 1928, 'Due_for_maintenance', 2011);
bridge(2)=struct('Location', "Hope Ave.", 'Max_load', 90,'Year_build', 1950, 'Due_for_maintenance', 2013);
bridge(3)=struct('Location', "Clark St.", 'Max_load', 85,'Year_build', 1933, 'Due_for_maintenance', 2012);
bridge(4)=struct('Location', "North Rd.", 'Max_load', 100,'Year_build', 1960, 'Due_for_maintenance', 2012);

bridge(3).Due_for_maintenance= 2018;

bridge(5).Location="Shore Rd.";
bridge(5).Max_load=85;
bridge(5).Year_build=1997;
bridge(5).Due_for_maintenance=2014;