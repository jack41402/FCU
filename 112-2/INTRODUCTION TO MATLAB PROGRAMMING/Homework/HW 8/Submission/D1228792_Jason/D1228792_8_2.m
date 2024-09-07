clear all;
A = 1000;
r = 0.04;
k = 10;
n = 1;
epsilon = 10 .^ -4;
preV = -20;
V = 0;
while(abs(preV - V) >=  epsilon)
    preV = V;
    V = A .* (1 + r ./ n) .^ (n .* k);
    n = n .* 2;
end
V
exponential_form = V