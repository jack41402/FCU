x = 0:0.004:1;
k=0:1:3;
z=1;
B1(x)= @(x)factorial(1)./factorial(1-k)./factorial(k).*x.^(1-k).*(B1(x));
plot(x,B1(x))
B2(x)= @(x)factorial(2)./factorial(2-k)./factorial(k).*x.^(2-k).*(B2(x));
plot(x,B2(x))
B3(x)= @(x)factorial(3)./factorial(3-k)./factorial(k).*x.^(3-k).*(B3(x));
plot(x,B3(x))
B4(x)= @(x)factorial(4)./factorial(4-k)./factorial(k).*x.^(4-k).*(B4(x));
a = plot(x,B1(x));
b = plot(x,B2(x));
c = plot(x,B3(x));
d = plot(x,B4(x));
a.Linestyle = "--";
a.color = "m";
a.LineWidth = "2";
b.Linestyle = "- ";
b.color = "r";
b.LineWidth = "2";
c.Linestyle = ".";
c.color = "p";
c.LineWidth = "4";
d.Linestyle = "-.";
d.color = "g";
d.LineWidth = "2";
legand("B1(x)", "B2(x)", "B3(x)", "B4(x)")