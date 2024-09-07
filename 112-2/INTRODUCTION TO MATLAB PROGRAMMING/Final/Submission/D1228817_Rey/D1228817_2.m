clear;

X=[0 1 2 3 4 5];
Y=[20 25 27 28 27 25];

fits=fit(X', Y', 'poly4');

y=mean(Y);

SSE=sum((Y-y).^2)
RS=sum((feval(fits, X)'-Y).^2)
y=feval(fits, 3.6)

fprintf("SSE: %.6f", SSE);
fprintf("R-squared: %.4f", RS);

%For R-squared:
%We can use the R-squared value to compare how well the curve fits two or more
%functions describing the same data.
%The function that yields the smallest R-squared value has the best fit to the data.

