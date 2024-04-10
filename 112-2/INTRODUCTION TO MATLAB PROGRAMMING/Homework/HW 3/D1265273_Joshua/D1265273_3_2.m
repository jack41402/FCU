a=[200 500 700 1000 1500];
fprintf('charge: \n')



for i=1:5
    prompt= "enter the used charge:";
    if a(i)<=500
        charge(i)= (2.*a(i))./100 + 5
    elseif 500<a(i) && a(i)<=1000
            charge(i)= ((a(i) - 500).*5)./100 + 10 + 5
    else 
            charge(i)=   ((a(i) - 1000).*10)./100 + 35 + 5
    end
end


