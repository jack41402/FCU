#include<stdio.h>
#include<string.h>
//D1228817

int i, j;//Loop variables.

int Char_conversion(char *v, int *V, int l){//Convert every digit of the hexadecimal numeral into a decimal value.
	
for(i=0; i<l; i++){
	if('0'<=v[i]&&v[i]<='9'){//If the digit is between 0 and 9.
		V[i]=v[i]-'0';
	}
	else{//If the digit is between 'A' and 'F'.
		V[i]=v[i]-'A'+10;
	}
}

}

unsigned long long Decimal(int*V, int l){//Convert the hexadecimal numeral into a decimal numeral.
	unsigned long long d=0;
	unsigned long long a;
	for(i=0; i<l; i++){//Here, 'i' controls which digit of the hexadecimal numeral is being added to the decimal numeral.
	a=1;
	for(j=0; j<l-(i+1); j++){//Calculate how much the ith digit of the hexadecimal numeral would have to be multiplied by to add to the decimal numeral.
		a=a*16;
	}
	d+=a*(V[i]);//Add the calculated value times the ith digit of the hexadecimal numeral to the decimal numeral.
}

return d;//Function returns the value 'd'.
}

int main(){
	
char n1[17];//First hexadecimal numeral inputted by the user.
char n2[17];//Second hexadecimal numeral inputted by the user.
char product[18];//The product of 'n1' and 'n2' represented in hexadecimal.
int N1[17];//Every digit of 'n1' represented in decimal.	
int N2[17];//Every digit of 'n2' represented in decimal.	
int Product[18];//Every digit of product represented in decimal.	
int l1, l2, lp;//Lengths of 'n1', 'n2' and 'product'.
int c;//The carry.
unsigned long long dn1, dn2, p;//'n1', 'n2' and 'product' represented in decimal values.
int leading;//Variable used to calculate how many blanks should be put at the beginning of each line of output.	

while (scanf("%s %s", n1, n2)==2) {//Allows the user to input 'n1' and 'n2' over and over again.
if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break;//If 'n1' and 'n2' = 0, the program terminates.
//Initialize the values of variables.
c=0;
dn1=0;
dn2=0;
p=0;
l1=strlen(n1);
l2=strlen(n2);

for(i=0; i<18; i++){
	Product[i]=0;
}

Char_conversion(n1, N1, l1);//Convert every digit of 'n1' into a decimal value.
Char_conversion(n2, N2, l2);//Convert every digit of 'n2' into a decimal value.

//Multiply 'N2' by 'N1', and store the calculated decimal value in the correct digit of 'Product'.
for(i=0; i<l1; i++){
	
	for(j=0; j<l2; j++){
			Product[l1+l2-(j+i+2)]+=(N1[l1-(i+1)])*(N2[l2-(j+1)]);//Storing the calculated value in 'Product'.
		}
}	

//Calculate the correct decimal value for each digit of the hexadecimal representation of the product.
for(i=0; i<l1+l2-1; i++){
	
	Product[l1+l2-(i+2)] = Product[l1+l2-(i+2)]+c;//Add the carry to each digit of 'Product'.
	c=Product[l1+l2-(i+2)]/16;//Devide the digit of 'Product' by 16 to get the carry.
	Product[l1+l2-(i+2)]=Product[l1+l2-(i+2)]%16;//Use the '%' operator to get the correct decimal value for the digit.
}	

if(c!=0){//If the carry is not 0.
	for(i=0; i<l1+l2; i++){//Shift each digit of 'Product' one digit to the right.
		Product[l1+l2-i]=Product[l1+l2-(i+1)];	
	}
	Product[0]= c;//Set the first digit of 'Product' to the value of the carry.
	lp=l1+l2;//Set length of 'Product' to 'l1' + 'l2'.
}
else{
	lp=l1+l2-1;//Set length of 'Product' to 'l1' + 'l2' - 1.
}

//Convert 'Product' into hexadecimal.
for(i=0; i<lp; i++){
	if(0<=Product[i]&&Product[i]<=9){
		product[i]=Product[i]+'0';
	}
	else{
		product[i]=Product[i]+'A'-10;
	}
}

leading=lp+2;
dn1=Decimal(N1, l1);//Decimal representation of 'n1'.
dn2=Decimal(N2, l2);//Decimal representation of 'n2'.
p=Decimal(Product, lp);//Decimal representation of 'product'.

for(i=0; i<leading-l1; i++){
	printf(" ");//Print blanks before 'n1'.
}
for(i=0; i<l1; i++){
	printf("%c", n1[i]);//Print 'n1'.
}
printf("\n");
printf("* ");
for(i=0; i<leading-(l2+2); i++){
	printf(" ");//Print blanks before 'n2'.
}
for(i=0; i<l2; i++){
	printf("%c", n2[i]);//Print 'n2'.
}
printf("\n");
for(i=0; i<leading; i++){
	printf("-");//Print the line between 'n2' and 'product'.
}
printf("\n");
for(i=0; i<leading-lp; i++){
	printf(" ");//Print blanks before 'product'.
}
for(i=0; i<lp; i++){
	printf("%c", product[i]);//Print 'product'.
}
printf("\n");
printf("%llu * %llu = %llu\n\n", dn1, dn2, p);//Print n1 * n2 = product in decimal.


}

}
