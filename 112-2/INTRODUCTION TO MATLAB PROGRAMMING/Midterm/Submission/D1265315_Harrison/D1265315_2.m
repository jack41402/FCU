p = [6 2 1;2 5 4;4 3 2;9 7 3];
b = p'*1000;
q = [10 12 13 15;8 7 6 4;12 10 13 9;6 4 11 5];
a = b*q;
c = a(1,:);
d = a(2,:);
e = a(3,:);
fprintf("Quarterly costs for materials:")
disp(c)
fprintf("Quarterly costs for labor:")
disp(d)
fprintf("Quarterly costs for transportation:")
disp(e)
f = sum(c);
g = sum(d);
h = sum(e);
fprintf("Total costs for materials:")
disp(f)
fprintf("Total costs for labor:")
disp(g)
fprintf("Total costs for transportation:")
disp(h)
fprintf("The total quarterly costs:")
i = sum(a,1);
disp(i)