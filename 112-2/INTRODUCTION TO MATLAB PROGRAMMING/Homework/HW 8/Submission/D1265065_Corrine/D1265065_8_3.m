compute_largest_sum();
function sum_terms = compute_largest_sum()
    sum_terms = 0;
    num_terms = 0;
    
    while sum_terms + (num_terms + 1)^2 <= 1000
        num_terms = num_terms + 1;
        sum_terms = sum_terms + num_terms^2;
    end
    n = num_terms
    ans = sum_terms
end

