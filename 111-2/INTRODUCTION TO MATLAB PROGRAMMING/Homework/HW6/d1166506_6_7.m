electricity = [200 500 700 1000 1500] ;
fee = 5*(electricity>=0) ;
fee = fee + (electricity<=500).*electricity*0.02 ;
fee = fee + (500<electricity & electricity<=1000).*(10 + (electricity-500)*0.05) ;
fee = fee + (1000<electricity).*(35 + (electricity-1000)*0.1) ;
disp([electricity' fee']) ;