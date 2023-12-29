#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int max(int m, int n){ // return the bigger integer
	if(m > n) return m;
	return n;
}

int main(){
	int i = 0;
	int over = 0;
	int al = 0;
	int bl = 0;
	int cl = 0;
	int maxl = 0; 
	char a[17] = {0};
	char b[17] = {0};
	char c[18] = {0};//extra place for the result that is overflow
	unsigned long long m = 0;// because assingment requrire strings with 64 bits, so it need to be unsigned long long
	unsigned long long n = 0;
	unsigned long long ans = 0;
	
	do{
		scanf("%s %s",&a, &b);
		
		m = strtoull(a, NULL, 16);//make "a" turn from string to unsigned long long from hexadecimal to decimal
		n = strtoull(b, NULL, 16);
		ans = m + n;
		if(m == 0 && n == 0) break;// stop the program if both are 0
		int over = UINT64_MAX - m < n;// to determined is the ans overflow
		
		if (over) sprintf(c, "1%llX",ans);// turn the ans to hexadecimal and store into c, if ans is overflow add a extra 1 in the front
		else sprintf(c, "%llX", ans);
		
		al = strlen(a); //to know how many digits each numbers have
		bl = strlen(b);
		cl = strlen(c);
		maxl = max(max(al, bl), cl); // determined which numbers have the most digits
		printf("  %*s\n", maxl, a); // make every numbers line up in the results
		printf("+ %*s\n", maxl, b);
		for(i = 0; i < 2 + maxl; i++) printf("-");
		printf("\n");
		printf("  %*s\n", maxl, c);
		
		if (over) printf("%llu + %llu = %llu    ****Overflow!!!\n\n", m, n, ans);// printed overflow when the result is overflow
		else printf("%llu + %llu = %llu\n\n", m, n, ans);
	
		
		
	}while(1);
}
