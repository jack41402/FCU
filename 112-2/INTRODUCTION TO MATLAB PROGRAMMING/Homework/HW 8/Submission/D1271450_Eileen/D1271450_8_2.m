A = 1000; 
r = 0.04;
k = 10;
V = zeros(1, 20); 
n_values = zeros(1, 20); 
for i = 1:20
    n = 2^(i-1); 
    V(i) = A * (1 + r/n)^(n*k);
    n_values(i) = n;
end
A_exp_rk = A * exp(r*k);
epsilon = 1e-4;
index = find(abs(A_exp_rk - V) < epsilon, 1);
disp([sprintf('%.4e', A_exp_rk)]);
disp('exponential_form =');
disp(sprintf('%.4e', A_exp_rk));

