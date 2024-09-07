total = 0;
terms_used = 0;
for i = 1:1000
    term = i^2;
    if total + term <= 1000
        total = total + term;
        terms_used = terms_used + 1;
    else
        break;
    end
end

fprintf('n = %d\n', terms_used);
fprintf('ans = %d\n', total);