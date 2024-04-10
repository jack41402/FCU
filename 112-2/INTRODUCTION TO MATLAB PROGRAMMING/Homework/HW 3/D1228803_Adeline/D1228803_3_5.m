P_function = @(L, r, N) (r * L * (1 + r / 12)^(12 * N)) / (12 * ((1 + r / 12)^(12 * N) - 1));

L = 50000; 
r = 0.15;  
N = 20;    
%N = 20:1000;

payment = P_function(L, r, N);
fprintf('%.4f\n', payment);

target_payment = 625;
found = false;
for N = 1:50
    P_N = P_function(L, r, N);
    if P_N < target_payment
        fprintf('yes\n');
        found = true;
        break;
    end
end
if ~found
    fprintf('no\n');
end

last = 0;
for r = 0.1:0.01:0.3
    newrate = r + 0.01;
    increasedRate = P_function(L, newrate, N);
    fprintf('L=%.2f, N=%d, newrate=%.2f%%, increasedRate=%.2f\n', L, N, newrate * 100, increasedRate);
    
    P = (r.*L.*(1+r./12).^(12.*N))./(12.*((1+r./12).^(12.*N)-1));
    now = P;
    diff = now - last;
    last = now;
end


