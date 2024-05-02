function D1228803_7_3()
    function newton_quot = newquot(f)
        h_values = [1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6];
        x = 1;
        newton_quotient = zeros(size(h_values));
        for i = 1:length(h_values)
            h = h_values(i);
            newton_quotient(i) = (f(x + h) - f(x)) / h; % Calculate the Newton quotient
            fprintf('h = %.6f, Approximate derivative = %.6f\n', h, newton_quotient(i));
        end
        newton_quot = newton_quotient(end);
    end
end
