product = [1; 2; 3; 4];
Material = [6; 2; 4; 9];
Labor = [2; 5; 3; 7];
Transportation = [1; 4; 2; 3];
Quantity = [10 12 13 15; 8 7 6 4; 12 10 13 9; 6 4 11 5];
N = 1000;

firstMaterial = N * Material' * Quantity(:, 1);
secondMaterial = N * Material' * Quantity(:, 2);
thirdMaterial = N * Material' * Quantity(:, 3);
forthMaterial = N * Material' * Quantity(:, 4);

firstLabor = N * Labor' * Quantity(:, 1);
secondLabor = N * Labor' * Quantity(:, 2);
thirdLabor = N * Labor' * Quantity(:, 3);
forthLabor = N * Labor' * Quantity(:, 4);

firstTransportation = N * Transportation' * Quantity(:, 1);
secondTransportation = N * Transportation' * Quantity(:, 2);
thirdTransportation = N * Transportation' * Quantity(:, 3);
forthTransportation = N * Transportation' * Quantity(:, 4);

fprintf('Quarterly costs for materials: %d, %d, %d, %d\n', firstMaterial, secondMaterial, thirdMaterial, forthMaterial)
fprintf('Quarterly costs for labor: %d, %d, %d, %d\n', firstLabor, secondLabor, thirdLabor, forthLabor)
fprintf('Quarterly costs for transportation: %d, %d, %d, %d\n', firstTransportation, secondTransportation, thirdTransportation, forthTransportation)
fprintf('\n')

yearMaterial = firstMaterial + secondMaterial + thirdMaterial + forthMaterial;
yearLabor = firstLabor + secondLabor + thirdLabor + forthLabor;
yearTransportation = firstTransportation + secondTransportation + thirdTransportation + forthTransportation;

fprintf('Total costs for materials: %d\n', yearMaterial)
fprintf('Total costs for labor: %d\n', yearLabor)
fprintf('Total costs for transportation: %d\n', yearTransportation)
fprintf('\n')

firstTotal = firstMaterial + firstLabor + firstTransportation;
secondTotal = secondMaterial + secondLabor + secondTransportation;
thirdTotal = thirdMaterial + thirdLabor + thirdTransportation;
forthTotal = forthMaterial + forthLabor + forthTransportation;

fprintf('The total quarterly costs: %d,  %d,  %d,  %d\n', firstTotal, secondTotal, thirdTotal, forthTotal)