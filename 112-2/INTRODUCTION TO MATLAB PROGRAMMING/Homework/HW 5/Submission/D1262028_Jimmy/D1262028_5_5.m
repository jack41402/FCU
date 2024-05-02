earning=[12000, 15000, 18000, 24000, 35000, 50000, 70000];
number=[3000, 2500, 1500, 1000, 400, 100, 25];
total=earning.*number;
average_salary=mean(earning)
earning=earning';
number=number';
logical=[earning<average_salary, earning>average_salary];
x=number.*logical;
summ=sum(x)%right is below, left is above


average_earning=sum(total)/sum(sum(number));

fprintf("%f", average_earning)

