#include <stdio.h>
#include <string.h> 
#include <ctype.h> 
int main(){
	int base; 
	char s[65];
	unsigned long long n; 
	unsigned long long power; 
	int i;
	while(1){
		printf("Enter a numeral (a string of digits and English letters): ");
		scanf("%s", s); 
		base = 0;
		for(i = 0 ; i < strlen(s) ; i++){
			if(isdigit(s[i]) && (s[i] - '0') >= base)
				base = s[i] - '0' + 1;
			else if(isupper(s[i]) && (s[i] - 'A' + 10) >= base)
				base = s[i] - 'A' + 10 + 1;
			else if(islower(s[i]) && (s[i] - 'a' + 36) >= base)
				base = s[i] - 'a' + 10 + 26 + 1;
			else if(!isalnum(s[i])){
				printf("The input string is an invalid numeral.\n\n");
				base = 0;
				break;
			}
		}
		if(base > 1){
			n = 0;
			power = 1;
			for(i = strlen(s) - 1 ; i >= 0 ; i--){
				if(isdigit(s[i]))
					n += (s[i] -'0') * power;
				else if (isupper(s[i]))
					n += (s[i] - 'A' + 10) * power;
				else
					n += (s[i] - 'a' + 36) * power;
				power *= base;
			}
		printf("Base: %d, Deciaml value: %llu\n", base, n);
		printf("Binary numeral: ");
		int j;
		for(j = 63 ; j >= 0 ; j--){
			printf("%llu", (n >> j) & 1);
			if(j % 8 == 0){
				printf(" ");
			}
		}
		printf("\n");
		printf("Hexadecimal numeral: ");
		for(j = 15 ; j >= 0 ; j--){
			printf("%llX", (n >> (j * 4)) & 0xF);
			if(j % 4 == 0){
				printf(" ");
			}
		}
		printf("\n\n");
		}else if(base == 1){
			break;
		}
	}
	return 0;
}
