function y = fact(n)
% FACT Recursive definition of n!
if n > 1
    y = n * fact(n-1);
else
    y = 1;
end;