A = 1000; 
r = 0.04;  
k = 10;    

V_cont = A * exp(r * k);

n = 1;

while true
    V = A * (1 + r / n)^(n * k);

    if abs(V_cont - V) < 1e-4
        break;
    end
    n = n * 2;
end
fprintf('V = \n %.4e\n', V);
fprintf('exponential_form = \n %.4e\n', V_cont);