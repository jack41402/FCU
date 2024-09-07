a= @(x) x^2;
n = 1;
term = 0;
b = 0;
while b<1000
    c = a(n);
    b = b + c;
    n = n+1;
    term = term+1;
end
if b>1000
    n = term -1
    ans = b -term^2
end