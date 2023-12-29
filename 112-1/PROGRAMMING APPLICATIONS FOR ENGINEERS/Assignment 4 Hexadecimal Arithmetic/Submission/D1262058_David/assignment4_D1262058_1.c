#include <string.h>
#include <stdio.h>
unsigned long long hextodecimal (char hex[],int hexlength){
	int i;
	unsigned long long decimal=0;
	for(i=0;i<hexlength;i++){
		if (hex[i]-'0'<10) hex[i]=hex[i]-'0';	
		else hex[i]=hex[i]-'A'+10;
		decimal=(decimal<<4)+hex[i];
	}
	return decimal;
}
void hexdigitoutput (char hex[],char newhex[],int hexlength){
	int i;
	for(i=0;i<hexlength;i++){
		if(hex[i]<10) newhex[i]=hex[i]+'0';
		else newhex[i]=hex[i]-10+'A';
	}
}
int hexadder(char n1[], char n2[], char sumf[], int lmin, int lmax, int counta, int countb){
	int i,newlmax;
	int carry=0;
	for(i=0;i<lmax;i++){
		if (i<lmin)	sumf[(lmax-1-i)]=n1[(counta-1-i)]+n2[(countb-1-i)]+carry;//adding i-th bit for both n1,n2	
		else if(i<counta) sumf[(lmax-1-i)]=n1[(counta-1-i)]+carry;//when n1 has more digits
		else if(i<countb) sumf[(lmax-1-i)]=n2[(countb-1-i)]+carry;//when n2 has more digits
		carry= sumf[(lmax-1-i)]/16;
		sumf[lmax-(i+1)] = sumf[lmax-(i+1)] % 16;		
	}
	if (carry==1){//if the final carry is 1
		for(i=lmax;i>0;i--) sumf[i]=sumf[i-1];//right shift every digit 
		sumf[0]=1;//the msb is 0
		newlmax=lmax+1;//sum length +1
	}
	else newlmax=lmax;	
	return newlmax;
}
int main(void){
	int i,counta, countb, lmax, lmin, newlmax; 
	unsigned long long decimal1, decimal2, decimalsum, hexsum;
	char n1[17], n2[17], sum[18];
	char newn1[17],newn2[17],newsum[18];
	while(1){
		if (scanf("%s %s",n1,n2)!=2) break;//make sure there are two inputs
		if (strcmp(n1,"0")==0 && strcmp(n2,"0")==0) break;//if the inputs are both 0 then break
		for(i=0;i<17;i++) newn1[i]=0;//initialize the arrays
		for(i=0;i<17;i++) newn2[i]=0;
		for(i=0;i<18;i++) newsum[i]=0;
		counta=strlen(n1);
		countb=strlen(n2);
		if (counta>=countb){//find the largest input count
			lmax=counta;
			lmin=countb;
		} 
		else {
			lmax=countb;
			lmin=counta;
		}
		decimal1=hextodecimal(n1,counta);//convert the inout into decimal form
		decimal2=hextodecimal(n2,countb);
		decimalsum=decimal1+decimal2;
		newlmax=hexadder(n1, n2, sum, lmin, lmax, counta, countb);//add n1, n2
		hexdigitoutput (n1,newn1,counta);//convert n1,n2 back to hex form
		hexdigitoutput (n2,newn2,countb);
		hexdigitoutput (sum,newsum,newlmax);
		for(i=0;i<(newlmax-counta+2);i++) printf(" ");//printf out the operation in hex form
		printf("%s\n",newn1);
		printf("+");
		for(i=0;i<(newlmax-countb+1);i++) printf(" ");
		printf("%s\n",newn2);
		for(i=0;i<(newlmax+2);i++) printf("-");
		printf("\n");
		printf("  %s\n",newsum);
		printf("%llu + %llu = %llu",decimal1, decimal2, decimalsum);//print out the operation in decimal form
		if (strlen(newsum)>16) printf("  ****overflow!!");//checking overflow
		printf("\n\n");
//		hexsum=hextodecimal(newsum,newlmax);
//		if (decimalsum!=hexsum) printf("     wrong");
	}
}




