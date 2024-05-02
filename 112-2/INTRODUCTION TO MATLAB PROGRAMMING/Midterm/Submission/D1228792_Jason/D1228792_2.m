cost = [6 2 1 ; 2 5 4 ; 4 3 2 ; 9 7 3];
vol = [10 12 13 15 ; 8 7 6 4 ; 12 10 13 9 ; 6 4 11 5];
qm = sum(cost(:,1) .* vol(:,:)) .* 1000;
ql = sum(cost(:,2) .* vol(:,:)) .* 1000;
qt = sum(cost(:,3) .* vol(:,:)) .* 1000;
fprintf("Quarterly costs for materials: %d, %d, %d, %d\n",qm)
fprintf("Quarterly costs for labor: %d, %d, %d, %d\n",ql)
fprintf("Quarterly costs for transportation: %d, %d, %d, %d\n\n",qt)
fprintf("Total costs for materials: %d\n",sum(qm))
fprintf("Total costs for labor: %d\n",sum(ql))
fprintf("Total costs for transportation: %d\n\n",sum(qt))
fprintf("The total quarterly costs: %d, %d, %d, %d\n",qm + ql + qt)
