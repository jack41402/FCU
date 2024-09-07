clc;clear all
% Initialize variables
n = 1; % Term index
sum_terms = 0; % Sum of terms

% Iterate through terms until the sum exceeds 1000
while sum_terms + n^2 <= 1000
    sum_terms = sum_terms + n^2;
    n = n + 1;
end

% Display the number of terms used in the sum
disp(['n= ', num2str(n-1)]);
ans=sum_terms