function main()
    A = 1000;
    r = 0.04;
    k = 10;
    epsilon = 1e-4;
    n = 1;
    V_previous = calculate_V(A, r, k, n);
    while true
        n = n * 2;
        V = calculate_V(A, r, k, n);
        if abs(V - V_previous) < epsilon
            break;
        end
        V_previous = V;
    end

    fprintf('V = %.4e\n', V);
    fprintf('exponential_form = %.4e\n', V);
end
function V = calculate_V(A, r, k, n)
    V = A * (1 + r/n)^(n * k);
end
