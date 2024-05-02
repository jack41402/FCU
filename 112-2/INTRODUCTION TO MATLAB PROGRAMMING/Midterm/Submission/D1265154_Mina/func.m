function result = func()
    function result = rats(x)
        n = 0;
        term = 1;
        result = term;
         n = n + 1;
        x = n.*a^n./ n;
        n = 0:1:20;
           
            term = term * x / n;
            result = result + term;
       
    end
x = input('n=');
exp_result = rats(x,strlen);
fprintf('rats(%d) = %f\n', n, exp_result);

end
