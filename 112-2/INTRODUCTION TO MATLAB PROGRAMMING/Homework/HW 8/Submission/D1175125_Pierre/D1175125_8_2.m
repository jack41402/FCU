A = 1000; 
r = 0.04; 
k = 10;   
V_limit = A * exp(r * k); 

n = 1; 
V = zeros(1, 20); 
i = 1;

for n = 1:2^20
    V(i) = A * (1 + r/n)^(n*k); 
    if abs(V_limit - V(i)) < 1e-4 
        break; 
    end
    i = i + 1;
end

fprintf('V = \n');
disp(V(i));
fprintf('exponential form = \n');
disp(V(i));