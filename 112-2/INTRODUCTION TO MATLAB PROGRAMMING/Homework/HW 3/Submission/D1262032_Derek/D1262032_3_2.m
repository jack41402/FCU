units = [200 500 700 1000 1500];
cost=[];
fprintf("charge=\n\n     ")
for i = 1:5
    if units(i)<=500
        cost(i) = units(i).*0.02+5;
    elseif units(i)<=1000
        cost(i) = (units(i)-500).*0.05+10+5;
    else 
        cost(i) = (units(i)-1000).*0.1+35+5;
    end
    fprintf("%d  ", cost(i))
end
fprintf("\n")
