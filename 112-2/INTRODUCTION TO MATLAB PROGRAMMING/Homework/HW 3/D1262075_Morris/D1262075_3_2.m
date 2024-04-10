unit=[200 500 700 1000 1500];

for i=1:5
    if unit(i)<500
        charge(i)=unit(i)*0.02+5;
    elseif 500<=unit(i) && unit(i)<=1000
        charge(i)=10+(unit(i)-500)*0.05+5;
    else
        charge(i)=35+0.1*(unit(i)-1000)+5;
    end
end
disp(charge)