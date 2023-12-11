% (a)
y1 = @(x , n) ((-1).^(n)).*(x.^(2.*n+1))./(2.*n+1) ;
ans = 0 ;
for i=0:1000000
    ans = ans + y1(1 , i) ;
end
disp(ans*4)

% (b)
y2 = @(n) 1./((4.*n-3).*(4.*n-1)) ;
ans = 0 ;
for i=1:100000
    ans = ans + y2(i) ;
end
disp(ans*8)

% (c)
temp1 = 0 ;
temp2 = 0 ;
temp3 = 0 ;
for i=0:100
    temp1 = temp1 + y1(1/8 , i) ;
    temp2 = temp2 + y1(1/57 , i) ;
    temp3 = temp3 + y1(1/239 , i) ;
end
ans = 6*temp1 + 2*temp2 + temp3 ;
disp(ans * 4)

% (d)
n = 0:100000 ;
ans = sum(4.*y1(1 , n))

n = 1:10000 ;
ans = sum(8*y2(n))