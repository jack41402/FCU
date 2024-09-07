num_terms_a = 24000;
num_terms_b = 12000;
a = pi_a(num_terms_a);
fprintf('a = \n\t%.4f', a);
b = pi_b(num_terms_b);
fprintf('\nb = \n\t%.4f', b);
c = pi_c();
fprintf('\nc = \n\t%.4f', c);

function a = pi_a(num_terms)
    pi = 0;
    sign = 1;
    denominator = 1;
    
    for i = 1:num_terms
        pi = pi + sign * (1 / denominator);
        sign = sign * -1;
        denominator = denominator + 2;
    end
    
    a = pi * 4;
end

function b = pi_b(num_terms)
    pi = 0;
    denominator = 1;
    
    for i = 1:num_terms
        pi = pi + 1 / (denominator * (denominator + 2));
        denominator = denominator + 4;
    end
    
    b = pi * 8;
end

function arctan_x = compute_arctan(x)
    arctan_x = 0;
    sign = 1;
    numerator = x;
    denominator = 1;
    
    for n = 1:1000
        term = sign * (numerator / denominator);
        arctan_x = arctan_x + term;
        
        sign = -sign;
        numerator = numerator * x^2;
        denominator = denominator + 2;
    end
end

function c = pi_c()
    arctan_8 = compute_arctan(1/8);
    arctan_57 = compute_arctan(1/57);
    arctan_239 = compute_arctan(1/239);
    
    c = 6 * arctan_8 + 2 * arctan_57 + arctan_239;
    c = c * 4;
end