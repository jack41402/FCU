x=3;
i=1;
series=0;

while true

    if i==1

        a=1;

    else
        
        a=(-1)^(i-1)*x^(2*(i-1))/factorial(2*(i-1));

    end

    series=series+a;
    fprintf("%d     %.4f\n", i, series);

    if abs(series-cos(x))<=10^-4
        break;
    end


    i=i+1;

end
