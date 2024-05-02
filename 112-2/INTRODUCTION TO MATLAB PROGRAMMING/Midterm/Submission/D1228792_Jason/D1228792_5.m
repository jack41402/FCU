for L = 25 : 0.0001 : 30
    for R = 20 : 0.0001 : 25
        A = L .* 2 .* R + (pi .* R.^2) ./2;
        if(abs(A - 2000)<=0.01)
            cost = (2.*L + 2.*R) .* 40 + (pi .* R) .* 50;
        end
    end
end
fprintf("R_min = \n   %.4f\n",R)
fprintf("L_min = \n   %.4f\n",L)
fprintf("min_cost = \n\t   %.2f\n",min(cost))

