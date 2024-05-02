clear all
clc
product_cost=[1 6 2 1;
              2 2 5 4 ;
              3 4 3 2;
              4 9 7 3]
producton_volume=[1 10 12 13 15;
                  2  8  7  6  4;
                  3 12 10 13  9;
                  4  6  4 11  5;]

%(a)
for i=1:4
summaterial(i)=sum(product_cost(:,2).*producton_volume(:,i+1))*1000;
sumlabor(i)=sum(product_cost(:,3).*producton_volume(:,i+1))*1000;
sumtransport(i)=sum(product_cost(:,4).*producton_volume(:,i+1))*1000;
end
fprintf("Quartely costs for materials:%d,%d,%d,%d\n",summaterial(1),summaterial(2),summaterial(3),summaterial(4))
fprintf("Quartely costs for labor:%d,%d,%d,%d\n",sumlabor(1),sumlabor(2),sumlabor(3),sumlabor(4))
fprintf("Quartely costs for transportation:%d,%d,%d,%d\n\n",sumtransport(1),sumtransport(2),sumtransport(3),sumtransport(4))

%(b)
fprintf("Total costs for materials:%d\n",sum(summaterial))
fprintf("Total costs for labor:%d\n",sum(sumlabor))
fprintf("Total costs for transportation:%d\n\n",sum(sumtransport))
%(c)
for i=1:4
total(i)=summaterial(i)+sumlabor(i)+sumtransport(i);
end
fprintf("Total quarterly costs :%d,%d,%d,%d\n",total(1),total(2),total(3),total(4))

