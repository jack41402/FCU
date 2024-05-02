a = [200 500 700 1000 1500];
fprintf('charge: \n')

for i=1:5
    if a(i)<500;
       charge(i) =  a(i)*0.02+5;
    elseif 500<=a(i) & a(i)<=1000
       charge(i) =  10+(a(i)-500)*0.05+5;
    else 
       charge(i) =  35+0.1*(a(i)-1000)+5;
    end
end

disp(charge)

