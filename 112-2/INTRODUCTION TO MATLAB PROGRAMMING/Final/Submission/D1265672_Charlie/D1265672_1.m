x = 0:0.004:1;  
B(1,:) = 1; 

for n = 2:5
    for k = 0:n
        B(n,:) = B(n,:) + nchoosek(n, k) .* B(k,:) .* (x.^(n-k));
    end
end
figure; 
hold on;
plot(x, B(2,:), 'Color', 'b', 'LineWidth', 2, 'LineStyle','-');
plot(x, B(3,:), 'Color', 'r', 'LineWidth', 2, 'LineStyle','--');
plot(x, B(4,:), 'Color', 'g', 'LineWidth', 2, 'LineStyle',':');
plot(x, B(5,:), 'Color', 'y', 'LineWidth', 2, 'LineStyle','-.');
legend('B1(x)', 'B2(x)', 'B3(x)', 'B4(x)');
hold off;