accounts = [200 500 700 1000 1500]; 
amounts = (0.02*accounts).*(accounts<=500);
amounts = amounts +(10+0.05*(accounts-500)).*(accounts>500 & accounts<=1000);
amounts = amounts + (35+0.1*(accounts-1000)).*(accounts>1000);
amounts = amounts + 5;
disp([accounts' amounts'])
