#include <stdio.h>
#include <string.h>
void hex_multiplication(char *n1, char *n2, char *sum, int *dict);
void printChar(int n, char c);
int main(void){
	int dict[130];
	int i,j,I;
	int lsum;
	char n1[20],n2[20],realn1[20],realn2[20];
	unsigned long long N1=0,N2=0,k,N;
	for (i=0 ; i<10 ; ++i) dict['0'+i] = i ; //0~9
	for(i=0;i<6;i++) dict['A'+i]= 10 + i ; //A~F
	while(scanf("%s %s",&n1,&n2)==2 && (strcmp(n1,"0")!=0 || strcmp(n2,"0")!=0)){ //verify if n1 & n2==0
		char sum[20];
		N1=0; //initialize the data
		N2=0; //initialize the data
		k=0; //initialize the data
		lsum=20; //initialize the data
		for(i=0;i<20;i++) realn1[i] = '0'; //initialize the data
		for(i=0;i<20;i++) realn2[i] = '0'; //initialize the data
		for(i=0;i<20;i++) sum[i] = '0'; //initialize the data
		for(i=strlen(n1)-1;i>=0;i--){
			N=dict[n1[i]];
			for(j=1;j<=k;j++) N=N*16;
			N1+=N;
			k++;
		} //change character to number
		k=0; //return k to 0
		for(i=strlen(n2)-1;i>=0;i--){
			N=dict[n2[i]];
			for(j=1;j<=k;j++) N=N*16;
			N2+=N;
			k++;
		} //change character to number
		for(i=0;i<strlen(n1);i++) realn1[i]=n1[strlen(n1)-1-i];
		int flag=0;
		for(i=0;i<20;i++){
			if(realn1[i]=='\0') flag=1;
			if (flag) realn1[i]='0';
		}
		for(i=0;i<strlen(n2);i++) realn2[i]=n2[strlen(n2)-1-i];
		flag=0;
		for(i=0;i<20;i++){
			if(realn2[i]=='\0') flag=1;
			if (flag) realn2[i]='0';
		} //add 0 to the null character
		hex_multiplication(realn1, realn2, sum, dict); // do the multiplication
		for(i=19;i>=0;i--){
			if(sum[i]=='0') lsum--;
			else break;
		} //calculate the digits of sum
		if(strlen(n2)==1&&n2[0]=='0'){
			lsum=strlen(n1);
		}
		if (strlen(n1)==1&&n1[0]=='0'){
			lsum =strlen(n2);
		}
		printChar(2+lsum-strlen(n1),' '); //print the space before n1
		for(i=0;i<strlen(n1);i++) printf("%c",n1[i]);
		printf("\n*");
		printChar(2+lsum-strlen(n2)-1,' '); //print the space before n2
		for(i=0;i<strlen(n2);i++) printf("%c",n2[i]);
		printf("\n");
		printChar(2+lsum,'-');
		printf("\n  ");
		if(strlen(n1)==1&&n1[0]=='0'||strlen(n2)==1&&n2[0]=='0') {
			printChar(lsum-1,' ');
			printf("0");
		}
		else for(i=19-(20-lsum);i>=0;i--) printf("%c",sum[i]);
		printf("\n%llu * %llu = %llu",N1,N2,N1*N2);
		printf("\n\n");
	}
	return 0;
}
void printChar(int n, char c) {
 int i; // Loop vairable.
 for (i=0; i<n; i++) printf("%c", c); // Each iteration print one character c.
}
void hex_multiplication(char *realn1, char *realn2,char *sum,int *dict){
	char num[16]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int carry=0,i,j,k;
	int SUM=0; //initialize the data
	char sep_sum[20][40]; //for the sum of each layer
	for(i=0;i<20;i++) for(j=0;j<40;j++) sep_sum[i][j]='0'; //initialize the data
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			sep_sum[i][j]=num[(dict[realn1[j]] * dict[realn2[i]] + carry)%16];
			carry=(dict[realn1[j]] * dict[realn2[i]] + carry)/16;
		}
	} //use n2 to multiple n1
	for(i=0;i<20;i++){
		for(j=19;j>=0;j--) sep_sum[i][j]=sep_sum[i][j-i];
		for(k=0;k<i;k++) sep_sum[i][j]='0';
	} //place each layer at the corresponding number of digits 
	carry=0; //initialize carry
	for(j=0;j<20;j++){
		for(i=0;i<20;i++){
			if(i==19) SUM+=carry;
			SUM=SUM+dict[sep_sum[i][j]];
		}// add up the sum of each straight roll
		sum[j]=num[SUM%16];// turn number to character
		carry=SUM/16;
		SUM=0; //return to 0 for next sum
	}
}
