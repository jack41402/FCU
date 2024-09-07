x_initial = input('Initial guess: ');
newton_method(x_initial, 0);


function newton_method(x, steps)
    f = @(x) x.^3 + x-3;
    df = @(x) 3*x.^2 + 1;

    % Define the required relative error
    re = 1e-8;

    % Check if maximum iterations reached
    if steps >= 20
        disp('Zero NOT found');
        return;
    end

    % Calculate new x value
    x_new = x - f(x)/df(x);

    % Display the current x value and f(x) value
    disp([x_new, f(x_new)]);

    % Check if the relative error is less than or equal to the required relative error
    if abs((x_new - x) / x_new) <= re
        disp('Zero found at');
        disp(x_new);
    else
        % Recursively call newton_method with updated values
        newton_method(x_new, steps + 1);
    end
end
