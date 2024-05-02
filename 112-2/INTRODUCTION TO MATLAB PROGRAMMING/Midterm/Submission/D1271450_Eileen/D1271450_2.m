materials = [6000 2000 4000 9000];
labor =[2000 5000 3000 7000];
transportation=[1000 4000 2000 3000];
s1=[10 8 12 6];
s2=[12 7 10 4];
s3=[13 6 13 11];
s4=[15 4 9 5];
first_materials = materials.*s1;
second_materials = materials.*s2;
third_materials = materials.*s3;
fourth_materials = materials.*s4;
Am=sum(first_materials);
Bm=sum(second_materials);
Cm=sum(third_materials);
Dm=sum(fourth_materials);
fprintf("Quarterly costs for materials: %d, %d, %d, %d\n",Am,Bm,Cm,Dm);
first_labor = labor.*s1;
second_labor = labor.*s2;
third_labor = labor.*s3;
fourth_labor = labor.*s4;
Al=sum(first_labor);
Bl=sum(second_labor);
Cl=sum(third_labor);
Dl=sum(fourth_labor);
fprintf("Quarterly costs for labor:%d, %d, %d, %d\n",Al,Bl,Cl,Dl);
first_transportation = transportation.*s1;
second_transportation = transportation.*s2;
third_transportation = transportation.*s3;
fourth_transportation = transportation.*s4;
At=sum(first_transportation);
Bt=sum(second_transportation);
Ct=sum(third_transportation);
Dt=sum(fourth_transportation);
fprintf("Quarterly costs for transportation: %d, %d, %d, %d\n\n",At,Bt,Ct,Dt);
A = first_materials + second_materials + third_materials+ fourth_materials;
total_sum = sum(A);
fprintf("Total costs for materials: %d\n",total_sum);
B = first_labor + second_labor + third_labor + fourth_labor;
total_sum = sum(B);
fprintf("Total costs for labor: %d\n",total_sum);
C = first_transportation + second_transportation + third_transportation + fourth_transportation;
total_sum = sum(C);
fprintf("Total costs for transportation: %d\n\n",total_sum);
A = first_materials + first_labor + first_transportation;
total_sumA = sum(A);
B =  second_materials + second_labor + second_transportation;
total_sumB = sum(B);
C = third_materials + third_labor + third_transportation ;
total_sumC = sum(C);
D =  fourth_materials + fourth_labor + fourth_transportation;
total_sumD = sum(D);
fprintf("The total quarterly costs: %d, %d, %d, %d",total_sumA,total_sumB,total_sumC,total_sumD);








