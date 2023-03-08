price = [300 550 400 250 500] ;
quantity = [5 4 6 ; 3 2 4 ; 6 5 3 ; 3 5 4 ; 2 4 3] ;
cost = price' .* quantity ;
fprintf ("spent =\n")
disp(cost)

month_total = sum(cost , 1) ;
fprintf ("may =\n")
disp(month_total(1 , 1))
fprintf ("june =\n")
disp(month_total(1 , 2))
fprintf ("july =\n")
disp(month_total(1 , 3))

material_total = sum(cost , 2) ;
fprintf ("one =\n")
disp(material_total(1 , 1))
fprintf ("two =\n")
disp(material_total(2 , 1))
fprintf ("three =\n")
disp(material_total(3 , 1))
fprintf ("four =\n")
disp(material_total(4 , 1))
fprintf ("five =\n")
disp(material_total(5 , 1))

fprintf ("total =\n")
disp(sum(cost , 'all'))