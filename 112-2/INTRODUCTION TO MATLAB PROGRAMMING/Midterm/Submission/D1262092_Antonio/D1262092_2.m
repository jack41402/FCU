cost=[6 2 1;
      2 5 4;
      4 3 2;
      9 7 3];
Q_value=[10 12 13 15;
          8  7  6  4;
         12 10 13  9;
          6  4 11  5];
%(a)
Q_cost_M=sum(cost(:,1).*Q_value(:,1:4))*1000;
Q_cost_L=sum(cost(:,2).*Q_value(:,1:4))*1000;
Q_cost_T=sum(cost(:,3).*Q_value(:,1:4))*1000;
fprintf('Quaterly costs for materials: %d, %d, %d, %d\n',Q_cost_M);
fprintf('Quaterly costs for labor: %d, %d, %d, %d\n',Q_cost_L);
fprintf('Quaterly costs for transportation: %d, %d, %d, %d\n\n',Q_cost_T);
%(b)
Total_M=sum(Q_cost_M);
Total_L=sum(Q_cost_L);
Total_T=sum(Q_cost_T);
fprintf('Total costs for materials: %d\n',Total_M);
fprintf('Total costs for labor: %d\n',Total_L);
fprintf('Total costs for transportation: %d\n\n',Total_T);
%(c)
Total_Q=Q_cost_M+Q_cost_L+Q_cost_T;
fprintf('The total quaterly costs: %d, %d, %d, %d\n',Total_Q);

