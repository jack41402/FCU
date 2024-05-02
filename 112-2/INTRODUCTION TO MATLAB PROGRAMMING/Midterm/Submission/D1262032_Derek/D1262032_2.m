unit=[6 2 1; 2 5 4; 4 3 2; 9 7 3];
volume=[10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
fprintf("Quarterly costs for materials:")
for i=1:3
    for j=1:4
        quarterly_cost(i, j)=sum(unit(:, i).*volume(:, j).*1000);
        if(j~=4)
        fprintf(" %d,", quarterly_cost(i, j))
        else
        fprintf(" %d", quarterly_cost(i, j))
        end
    end
    if(i==1)
        fprintf("\nQuarterly costs for labor:")
    end
    if(i==2)
        fprintf("\nQuarterly costs for transportation:")
    end
end
fprintf("\n\n")
fprintf("\nTotal costs for materials: %d", sum(quarterly_cost(1, :)))
fprintf("\nTotal costs for labor: %d", sum(quarterly_cost(2, :)))
fprintf("\nTotal costs for transportation: %d\n\n", sum(quarterly_cost(3, :)))
fprintf("\nThe total quarterly costs: %d, %d, %d, %d\n", sum(quarterly_cost(:, 1)), sum(quarterly_cost(:, 2)), sum(quarterly_cost(:, 3)), sum(quarterly_cost(:, 4)))


