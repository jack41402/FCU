A = cell(2, 2);
location1 = 'Walden Pond';
air_temp1 = [60, 72, 65];
date1 = 'June 13, 1997';
water_temp1 = [55, 57, 56; 54, 56, 55; 52, 55, 53];
A{1, 1} = location1;
A{1, 2} = date1;
A{2, 1} = air_temp1 ;
A{2, 2} = water_temp1;
cellplot(A);