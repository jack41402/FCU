x = 0:0.004:1;
B1 = (factorial(0)./(factorial(0-0).*factorial(0-0))).*1.*(x.^(0-0));
B2 = (factorial(1)./(factorial(1-0).*factorial(1-0))).*1.*(x.^(1-0)) + (factorial(1)./(factorial(1-1).*factorial(1-1))).*B1.*(x.^(1-1));
B3 = (factorial(2)./(factorial(2-0).*factorial(2-0))).*1.*(x.^(2-0)) + (factorial(2)./(factorial(2-1).*factorial(2-1))).*B1.*(x.^(2-1)) + (factorial(2)./(factorial(2-2).*factorial(2-2))).*B2.*(x.^(2-2));
B4 = (factorial(3)./(factorial(3-0).*factorial(3-0))).*1.*(x.^(3-0)) + (factorial(3)./(factorial(3-1).*factorial(3-1))).*B1.*(x.^(3-1)) + (factorial(3)./(factorial(3-2).*factorial(3-2))).*B2.*(x.^(3-2)) + (factorial(3)./(factorial(3-3).*factorial(3-3))).*B3.*(x.^(3-3));

figure;
hold on;
a = plot(B1);
b = plot(B2);
c = plot(B3);
d = plot(B4);
aa = a.LineStyle;
a.Linestyle = "-";
legend ('B1(x)','B2(x)','B3(x)','B4(x)');

