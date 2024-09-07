x = [0 1 2 3 4 5];
y = [20 25 27 28 27 25];
n = 4;
p = polyfit(x, y, n);
y = polyval(p, 3.6)

ym=mean(y);
for k=1:4
           eval(['str=','coeff',int2str(k),';']);
           J(k)=sum((polyval(str,x)-y).^2);
           S(k)=sum((y-ym).^2);
           r2(k)=1-J(k)/S(k);
end
order=[ 1 2 3 4]';
disp([ order J' r2' ])
disp(S(1))
fprintf('SSE: %f\n', S(1));
fprintf('R-squared: %f\n', r2);
%(b)SSE Sum squared error performance function Foraperfectfit,
% J = 0 and r^2 =1.
% Therefore, the closer r^2 is to 1,
% thebetterthefitr2isatmost1.
% J may be greater than S, so r 2 may be negative.
% If this happens, it means that this is a very bad model.
% As a rule of thumb, a good fit should account for at
% least 99% of the variance in the data. 
% This value corresponds to r 2 >=0.99.
