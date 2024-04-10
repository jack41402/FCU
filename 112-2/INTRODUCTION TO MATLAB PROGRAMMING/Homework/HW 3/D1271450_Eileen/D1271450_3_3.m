% Define months
months = {'January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'};
number = {'1','2','3','4','5','6','7','8','9','10','11','12'};
% Initial deposit amount
deposit = 100000;

% Initialize interest rate
interest = 0;

% Initialize array to store increase for each month
increase = zeros(1, 12);

% Loop through each month
for i = 1:12
    % Determine interest rate based on current deposit amount
    if deposit <= 110000
        interest = 0.01;
    elseif deposit <= 125000
        interest = 0.015;
    else
        interest = 0.02;
    end
    
    % Calculate increase in deposit due to interest
    increase(i) = deposit * interest;
    
    % Update deposit with additional 1000 and interest
    deposit = deposit + 1000 + increase(i);
    
    % Print results for each month
    fprintf('%s\t%.2f\t%.2f\t%.2f\t\n', number{i}, interest, increase(i), deposit);
end