#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int max(int m, int n){//return the bigger number
	if(m > n) return m;
	return n;
}

int main(){
	int i = 0;
	int al = 0;
	int bl = 0;
	int cl = 0;
	int maxl = 0; 
	char a[9] = {0};
	char b[9] = {0};
	char c[17] = {0};
	unsigned long m = 0;//32bits
	unsigned long n = 0;
	unsigned long long ans = 0;//64bits
	
	do{
		scanf("%s %s",&a, &b);
		
		m = strtoul(a, NULL, 16);// turn "a" to unsigned long from hexadecimal to decimal 
		n = strtoul(b, NULL, 16);
		ans = (unsigned long long)m * n;//because ans is unsigned long long
		if(m == 0 && n == 0) break;//stop the program if both are 0
		
		sprintf(c, "%llX", ans);//store ans in to c with format of hexadecimal 
		
		al = strlen(a);// to know how many digits each numbers have
		bl = strlen(b);
		cl = strlen(c);
		maxl = max(max(al, bl), cl); // determined which numbers have the most digits
		printf("  %*s\n", maxl, a); // make every numbers line up in the results
		printf("* %*s\n", maxl, b); 
		for(i = 0; i < 2 + maxl; i++) printf("-");
		printf("\n");
		printf("  %*s\n", maxl, c);
		
		printf("%lu * %lu = %llu\n\n", m, n, ans);
	
		
		
	}while(1);
}
