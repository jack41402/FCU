function y = func(n);
a = 2;
y =  n.*a.^n./factorial(n+1);
t = rats(y,30)
end