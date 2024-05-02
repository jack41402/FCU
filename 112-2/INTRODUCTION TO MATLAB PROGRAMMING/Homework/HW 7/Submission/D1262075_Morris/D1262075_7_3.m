
for i = 0:1:6
    h = 10^(-i);
    x = 1;
    der =newquotD1262075(x,h);
end
fprintf('y = %.4f',der);