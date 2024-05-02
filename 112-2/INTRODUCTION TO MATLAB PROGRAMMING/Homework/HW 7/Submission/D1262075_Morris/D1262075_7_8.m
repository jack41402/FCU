p2_rec = p(2,3);
fprintf('P(2, 3) is %f\n', p2_rec);

function ans = p(x, y)
    if x ==0
        ans = 1;
    elseif x == 1
        ans = y;
    else
        ans = ((2*x-1)*y*p(x-1,y)-(x-1)*p(x-2,y))/x;
    end
end