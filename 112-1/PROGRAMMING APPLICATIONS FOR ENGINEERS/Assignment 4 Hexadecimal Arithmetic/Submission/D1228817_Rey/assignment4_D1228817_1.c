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
	for(j=0; j<l-(1+i); j++){//Calculate how much the ith digit of the hexadecimal numeral would have to be multiplied by to add to the decimal numeral.
		a=a*16;
	}
	d+=a*(V[i]);//Add the calculated value times the ith digit of the hexadecimal numeral to the decimal numeral.
}

return d;//Function returns the value 'd'.
}

int main(){
	
char n1[17];//First hexadecimal numeral inputted by the user.
char n2[17];//Second hexadecimal numeral inputted by the user.
char sum[18];//The sum of 'n1' and 'n2' represented in hexadecimal.
int N1[17];//Every digit of 'n1' represented in decimal.
int N2[17];//Every digit of 'n2' represented in decimal.
int Sum[18];//Every digit of sum represented in decimal.
int l1, l2, ls;//Lengths of 'n1', 'n2' and 'sum'.
int max, min;//Biggest and smallest value between 'l1' and 'l2'.
int c;//The carry.
unsigned long long dn1, dn2, s;//'n1', 'n2' and 'sum' represented in decimal values.
int leading;//Variable used to calculate how many blanks should be put at the beginning of each line of output.

while (scanf("%s %s", n1, n2)==2) {//Allows the user to input 'n1' and 'n2' over and over again.
if (strcmp(n1, "0")==0 && strcmp(n2, "0")==0) break;//If 'n1' and 'n2' = 0, the program terminates.
//Initialize the values of variables.
s=0;
c=0;
dn1=0;
dn2=0;
l1=strlen(n1);
l2=strlen(n2);

//Between 'l1' and 'l2', decide which should be 'max' and 'min'.
if(l1>l2){
	max=l1;
	min=l2;
}
else{
	max=l2;
	min=l1;
}

Char_conversion(n1, N1, l1);//Convert every digit of 'n1' into a decimal value.
Char_conversion(n2, N2, l2);//Convert every digit of 'n2' into a decimal value.

//Adding up 'n1' and 'n2'.
for(i=0; i<max; i++){
	
	if(i<min){//Add up the i-th digit.
		Sum[max-(i+1)]=(N1[l1-(i+1)])+(N2[l2-(i+1)])+c;
	}
	else if(i<l1){//Add the i-th digit of 'N1' to 'Sum'.
		Sum[max-(i+1)]=(N1[l1-(i+1)])+c;
	}
	else if(i<l2){//Add the i-th digit of 'N2' to 'Sum'.
		Sum[max-(i+1)]=(N2[l2-(i+1)])+c;
	}
	
	c=Sum[max-(i+1)]/16;//The carry. 
	Sum[max-(i+1)]=Sum[max-(i+1)]%16;//The sum of the i-th digit.

}	

//Convert 'Sum' into hexadecimal.
for(i=0; i<max; i++){
	if(0<=Sum[i]&&Sum[i]<=9){
		sum[i]=Sum[i]+'0';
	}
	else{
		sum[i]=Sum[i]+'A'-10;
	}
}

if(c!=0){//If carry does not equal 0.
	for(i=0; i<max; i++){//Shift the digits one digit to the right.
		sum[max-i]= sum[max-(i+1)];
		Sum[max-i]= Sum[max-(i+1)];
	}
	sum[0]='1';//Set the first digit to 1.
	Sum[0]=1;
	ls=max+1;//Set length of 'sum' to 'max' +1.
}
else{
	ls=max;//Set length of 'sum' to 'max'.
}

if(c!=0) leading=ls+2;
else leading=max+2;

printf("\n");

dn1=Decimal(N1, l1);//Decimal representation of 'n1'.
dn2=Decimal(N2, l2);//Decimal representation of 'n2'.
s=Decimal(Sum, ls);//Decimal representation of 'sum'.

for(i=0; i<leading-l1; i++){
	printf(" ");//Print blanks before 'n1'.
}
for(i=0; i<l1; i++){
	printf("%c", n1[i]);//Print 'n1'.
}
printf("\n");
printf("+ ");
for(i=0; i<leading-(l2+2); i++){
	printf(" ");//Print blanks before 'n2'.
}
for(i=0; i<l2; i++){
	printf("%c", n2[i]);//Print 'n2'.
}
printf("\n");
for(i=0; i<leading; i++){
	printf("-");//Print the line between 'n2' and 'sum'.
}
printf("\n");
for(i=0; i<leading-ls; i++){
	printf(" ");//Print blanks before 'sum'.
}
for(i=0; i<ls; i++){
	printf("%c", sum[i]);//Print 'sum'.
}
printf("\n");
printf("%llu + %llu = %llu", dn1, dn2, s);//Print n1 + n2 = product in decimal.
if(ls>16)printf("   ****Overflow!!!\n\n");//Print overflow message.
else printf("\n\n");
	}
}
