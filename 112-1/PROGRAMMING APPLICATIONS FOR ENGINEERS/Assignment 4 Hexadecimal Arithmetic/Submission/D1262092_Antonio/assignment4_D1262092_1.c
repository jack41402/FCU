#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(int count, char c) {
    for (int i = 0; i < count; i++) {
        printf("%c", c);
    }
}
void Adder(char*,char*,char*,unsigned long long,unsigned long long,unsigned long long);

int main() {
    char hex1[17] = {}, hex2[17] = {}, result[18] = {},sum[18] = {};
    int length, flag=0, i;
  	int len_hex1 = strlen(hex1), len_hex2 = strlen(hex2);

    while (1) {
        // Get input and verify
        scanf("%s %s", hex1, hex2);
        if (strcmp(hex1, "0") == 0 && strcmp(hex2, "0") == 0)
            break;
        // Get sum by Adder
      	unsigned long long decimal1=0, decimal2=0;
      	sscanf(hex1, "%llx", &decimal1);
      	sscanf(hex2, "%llx", &decimal2);
		unsigned long long dec_sum = decimal1 + decimal2;
        // Print the inputs and '+','-' and the sum
        Adder(hex1,hex2,result,decimal1,decimal2,dec_sum);
        printf("\n\n");
    }

    return 0;
}

void Adder(char *hex1,char *hex2,char *result,unsigned long long decimal1,unsigned long long decimal2,unsigned long long dec_sum){
  char num1[17] = {}, num2[17] = {}, sum[18] = {};
  int i, j, start;
  int len_hex1=strlen(hex1),len_hex2=strlen(hex2);
  int flag = 0;
  //Reverse string
  for(i=len_hex1-1, j=0; i>=0; i--){
    if(hex1[i]>='0' && hex1[i]<='9'){
      num1[j] = hex1[i] - '0';
    }
    else{
      num1[j] = hex1[i] - 'A' + 10;
    }
    j++;
  }	
  for(i=len_hex2-1, j=0; i>=0; i--){
    if(hex2[i]>='0' && hex2[i]<='9'){
      num2[j] = hex2[i] - '0';
    }
    else{
      num2[j] = hex2[i] - 'A' + 10;
    }
    j++;
  }
  //Add two numbers
  int carry = 0;
  for(i=0;i<17;i++){
    result[i]= (num1[i]+num2[i]+carry)%16;
    carry = (num1[i]+num2[i]+carry)/16;
  }
  //Get the result
  for(i=17;i>=0;i--){
    if(result[i]!=0){
        start=i;
        break;
      }
    flag++;
  }
    for(i=start,j=0;i>=0;i--,j++){
    sum[j]=result[i];
  }
  for(i=17-flag,j=0;i>=0;i--){
    if(result[i]>=0 && result[i]<=9){
      sum[j] = result[i] + 48;
    }
    else{
      sum[j] = result[i] + 65 - 10;
    }
    j++;
  }
  	printChar(18-flag - strlen(hex1)+2, ' ');
    printf("%s\n", hex1);
    printf("+");
    printChar(18-flag - strlen(hex2)+1, ' ');
    printf("%s\n", hex2);
	printChar(18-flag+2, '-');
	printf("\n");
    printChar(2,' ');
   	for(i = 0;i < 17-flag+1;i++){
    	printf("%c",sum[i]);
    }
    printf("\n%llu + %llu = %llu",decimal1,decimal2,dec_sum);
    if (18-flag>16) printf("    ****Overflow!!!");	
}
