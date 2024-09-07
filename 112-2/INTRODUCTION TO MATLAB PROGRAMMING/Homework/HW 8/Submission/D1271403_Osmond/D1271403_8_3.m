n = 1;
c = zeros(1,1000);
while sum(c)+n.^2<=1000;
    c(n) = n.^2;
    n=n+1;
end
n=n-1
sum(c)