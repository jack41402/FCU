x = 3; 

cos_approximate = 1;
acuracy = 1e-4;

fprintf('%d\t%.4f\n', 1, cos_approximate);

sign = -1; 
for n = 1:6 
    term = (x^(2 * (n))) * ((-1)^(n)) / factorial(2 * (n)); 
    cos_approximate = cos_approximate + term;
    fprintf('%d\t%.4f\n', n+1, cos_approximate); 
end
