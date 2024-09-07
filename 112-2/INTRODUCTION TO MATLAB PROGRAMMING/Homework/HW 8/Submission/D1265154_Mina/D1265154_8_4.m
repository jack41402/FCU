x = 3; 
desired_accuracy = 1e-4; 
cos_approx = 0;

for n = 0:6 
    term = (-1)^n * (x^(2*n)) / factorial(2*n);
    cos_approx = cos_approx + term;
    fprintf('%d    %0.4f\n', n+1, cos_approx); 
    if abs(cos_approx - cos(x)) < desired_accuracy
        break;
    end
end


