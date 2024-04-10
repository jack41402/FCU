L = 50000; 
r = 0.15;  
N = 20;   

%%a
P = r*L*((1+r/12)^(12*N)) / (12*(((1+r/12)^(12*N))-1));
fprintf('$%.2f\n', P);

%%b
N=20:1000;
P1 = (r.*L./12) ./ ((1 - (1 + r./12).^(-12.*N)));

plot(N,P1)

disp('No')

%%c
rate = 0.15;
for i=1:20
    now = rate*5000*((1+rate/12)^(12*20)) / (12*(((1+rate/12)^(12*20))-1));
    if(i>1)
        disp(now-last)
    end
    rate = rate + 0.01;
    last = now;
end