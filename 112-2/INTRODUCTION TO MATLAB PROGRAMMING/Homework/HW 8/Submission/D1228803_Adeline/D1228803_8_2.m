A = 1000;
r = 0.04;
k = 10;
n = 1;

V_values = [];
An_values = [];

for i = 1:10
    V = A * (1 + r/n)^(n*k);
    V_values = [V_values, V];
    
    An = A * exp(r * k);
    An_values = [An_values, An];
    
    n = n * 2;
end

fprintf('V =\n\t %.4e\n', V_values(end));
fprintf('exponential_form =\n\t %.4e\n', An_values(end));
