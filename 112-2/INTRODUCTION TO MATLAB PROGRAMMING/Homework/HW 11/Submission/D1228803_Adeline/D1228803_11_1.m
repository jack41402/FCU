location = 'Walden Pond';
date = 'June 13, 1997';
air_temp = [60 72 65];
water_temp = [55 57 56; 54 56 55; 52 55 53];

A = {location, date; air_temp, water_temp};
cellplot(A);
disp(A);