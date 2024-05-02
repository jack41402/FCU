q1 = [10,8,12,6];
m1 = [6.*10^3,2.*10^3,4.*10^3,9.*10^3];
a1 = q1 .* m1;

sum_a1 = sum(a1);

q2 = [12,7,10,4];

a2 = q2 .* m1;

sum_a2 = sum(a2);


q3 = [13,6,13,11];

a3 = q3 .* m1;

sum_a3 = sum(a3);


q4 = [15,4,9,5];

a4 = q4 .* m1;

sum_a4 = sum(a4);

fprintf("Quarterly costs for materials: %d, %d, %d, %d\n",sum_a1 , sum_a2 ,sum_a3 ,sum_a4);

total_m = [sum_a1 , sum_a2 ,sum_a3 ,sum_a4];

labor = [2.*10^3,5.*10^3,3.*10^3,7.*10^3];
b1 = q1 .* labor;
sum_b1 = sum(b1);


b2 = q2 .* labor;
sum_b2 = sum(b2);


b3 = q3 .* labor;
sum_b3 = sum(b3);


b4 = q4 .* labor;
sum_b4 = sum(b4);

fprintf("Quarterly costs for labor: %d, %d, %d, %d\n",sum_b1 , sum_b2 ,sum_b3 ,sum_b4);
total_l = [sum_b1 , sum_b2 ,sum_b3 ,sum_b4];

trans = [1.*10^3,4.*10^3,2.*10^3,3.*10^3];

c1 = q1 .* trans;
sum_c1 = sum(c1);

c2 = q2 .* trans;
sum_c2 = sum(c2);

c3 = q3 .* trans;
sum_c3 = sum(c3);

c4 = q4 .* trans;
sum_c4 = sum(c4);

fprintf("Quarterly costs for transportation: %d, %d, %d, %d\n\n",sum_c1 , sum_c2 ,sum_c3 ,sum_c4);

total_t = [sum_c1 , sum_c2 ,sum_c3 ,sum_c4];

total_m1 = sum(total_m);

fprintf("Total costs for materials: %d\n",total_m1);

total_l1 = sum(total_l);

fprintf("Total costs for labor: %d\n",total_l1);
total_t1 = sum(total_t);

fprintf("Total costs for transportation: %d\n\n",total_t1);

a1 = sum_a1 + sum_b1 + sum_c1;
a2 = sum_a2 + sum_b2 + sum_c2;
a3 = sum_a3 + sum_b3 + sum_c3;
a4 = sum_a4 + sum_b4 + sum_c4;

fprintf("The total quarterly costs: %d %d %d %d",a1,a2,a3,a4);
