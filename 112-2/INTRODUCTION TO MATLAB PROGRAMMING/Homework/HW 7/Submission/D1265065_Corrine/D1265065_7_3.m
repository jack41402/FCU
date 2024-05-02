
% Define the x value
x = 1;

% Initialize h
h = 1;

% Define the true derivative value
true_derivative = 3;

% Loop through successively smaller values of h
while h >= 1e-6  % You can adjust the stopping condition based on the desired precision
    % Compute the Newton quotient
    derivative_estimate = (newquot(x + h) - newquot(x)) / h;
    
    % Update h
    h = h / 10;
end

% Display the true derivative value 
disp('y =')
fprintf('     %.4f\n',true_derivative)