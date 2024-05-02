function D1228803_5()
    function [R, L, min_cost, A] = calculateValues()
        global V_func; 

        A = (2 * R * L) + ((1/2) * R * pi);
        R = fminbnd(A, 0, 2000);

        %V_func = @(R) ((1/2) * pi * sqrt(R)); 
        %V_func = 10;
      
        %L = @(R) (2000 - ((1/2) * pi * sqrt(R)) / 2 * R);
        %R = fminbnd(L, 0, 10);
        %L = L(R);
        
        min_cost = ((1/2) * pi * sqrt(R) * 40)  + (2 * R * 50 * L * 50);

    end

    [R, L, min_cost, A] = calculateValues();
   
    disp(['R_min = ', sprintf('%.4f', R)]);
    disp(['L_min = ', sprintf('%.4f', L)]);
    disp(['min_cost = ', sprintf('%.2f', min_cost)]);
end
