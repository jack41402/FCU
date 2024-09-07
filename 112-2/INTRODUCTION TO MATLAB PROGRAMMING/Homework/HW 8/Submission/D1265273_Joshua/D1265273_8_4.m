y = @(n) (x^(2*n))/factorial(2*n);
n = 0;
x = 3;
b = y(n);
term = 1;
fprintf("%d    %3.4f\n", term, b); 
while abs(b-cos(x))>1e-4
    if rem(term,2) == 0
        n = n+1;
        term = term + 1;
        a = y(n);
        b = b+a;
    else
        n = n+1;
        term = term + 1;
        a = -1*y(n);
        b = b+a;
    end
    fprintf("%d   %3.4f\n", term, b);  
end
      