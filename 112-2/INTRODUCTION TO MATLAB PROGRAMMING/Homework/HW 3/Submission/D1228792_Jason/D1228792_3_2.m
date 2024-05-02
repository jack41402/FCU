a = [200 500 700 1000 1500];
for i=1:5
    if(a(i)<=500)
        price(i) = 5 + 2.*(a(i)/100);
    elseif(a(i)<=1000 & a(i)>500)
        price(i) = 15 + ((a(i)-500)/100).*5;
    else
        price(i) = 40 + ((a(i)-1000)/100).*10;
    end
end
fprintf("charge = \n");
disp(price);

