deposit=100000;
interest=[0.01 0.015 0.02];
increase=0;
for i=1:12
    if (deposit<=110000)
        increase=deposit*interest(1);
        deposit=deposit*(1+interest(1))+1000;
        month=i;
        
        fprintf("%d,%1.2f,%1.2f,%1.2f\n",month ,interest(1) ,increase ,deposit)
    elseif((110000<deposit)&&(deposit<=125000))
        increase=deposit*interest(2);
        deposit=deposit*(1+interest(2))+1000;
        month=i;
        
        fprintf("%d,%1.3f,%1.2f,%1.2f\n",month ,interest(2) ,increase ,deposit)
    else 
        increase=deposit*interest(3);
        deposit=deposit*(1+interest(3))+1000;
        month=i;
        fprintf("%d,%1.2f,%1.2f,%1.2f\n",month ,interest(3) ,increase ,deposit)
    end
end

