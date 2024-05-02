a=[1 0 2]
b=[0 2 2]
fprintf("A. ")
c = a~=b;
fprintf("%d", c)
fprintf("\nB. ")
c = a<b;
fprintf("%d", c)
fprintf("\nC. ")
c = a<b<a;
fprintf("%d", c)
fprintf("\nD. ")
c = a<b<b;
fprintf("%d", c)
fprintf("\nE. ")
c = a|(~a);
fprintf("%d", c)
fprintf("\nF. ")
c = b&(~b);
fprintf("%d", c)
fprintf("\nG. ")
c = a(~(~b));
fprintf("%d", c)
fprintf("\nH. ")
a = b == a;
fprintf("%d",a)