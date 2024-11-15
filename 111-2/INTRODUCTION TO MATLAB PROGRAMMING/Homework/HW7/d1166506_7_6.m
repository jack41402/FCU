materials = [7000 3000 9000 2000 6000] ;
labor = [3000 1000 4000 5000 2000] ;
transportation = [2000 3000 5000 4000 1000] ;
season = [16 14 10 12 ; 12 15 11 13 ; 8 9 7 11 ; 14 13 15 17 ; 13 16 12 18] ;

%  (a) the cost of materials, labor, and transportation for each season.
for i=1:4
    fprintf("Season %d:\n" , i) ;
    fprintf("\tmaterials: %d\n" , sum(materials.*season(:,i)')) ;
    fprintf("\tlabor: %d\n" , sum(labor.*season(:,i)')) ;
    fprintf("\ttransportation: %d\n\n" , sum(transportation.*season(:,i)')) ;
end

%  (b) the total cost of materials, labor, and transportation for each year.
fprintf("Year:\n") ;
fprintf("\tmaterials: %d\n" , sum(sum(materials.*season'))) ;
fprintf("\tlabor: %d\n" , sum(sum(labor.*season'))) ;
fprintf("\ttransportation: %d\n\n" , sum(sum(transportation.*season'))) ;

%  (c) total costs of each season.
total = (materials + labor + transportation).*season' ;
for i=1:4
    fprintf("Total of season %d: %d\n" , i , sum(total(i,:))) ;
end