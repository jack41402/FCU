#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function implementation of strncmp().
int strncmp_rec(const char *str1, const char *str2, size_t n) {
	// ***** Complete this function. 
	// DO NOT use any <string.h> functions in the the implementation of strncmp_rec().
	int s1 = strlen(str1);
	int s2 = strlen(str2);
	int a,i;
	char sum1 = "0", sum2 = "0";
	
	for(i=1; i<n; i++){
		if(str1[i] != "\"")
			sum1 = sum1 + str1[i];
		else
			break;
	}
	for(i=1; i<n; i++){
		if(str2[i] != "\"")
			sum2 = sum2 + str2[i];
		else
			break;
	}
	
	if(sum1 == sum2)
		a=0;
	else if(sum1 < sum2)
		a=-1;
	else if(sum1 > sum2)
		a=1;
		
	return a;	
}

// DO NOT modify the main program. 
int main(void) {
	printf("Tests of string comparison with length n:\n\n");
	printf("The library version:\n");
	printf("  strncmp(\"abc\", \"abc\", 4) returns %d\n", strncmp("abc", "abc", 4));
	printf("  strncmp(\"abcde\", \"abc\", 4) returns %d\n", strncmp("abcde", "abc", 4));
	printf("  strncmp(\"abcde\", \"abc\", 3) returns %d\n", strncmp("abcde", "abc", 3));
	printf("  strncmp(\"abc\", \"abcde\", 4) returns %d\n", strncmp("abc", "abcde", 4));
	printf("  strncmp(\"abc\", \"abcde\", 3) returns %d\n", strncmp("abc", "abcde", 3));
	printf("  strncmp(\"xyz\", \"XYZ\", 4) returns %d\n", strncmp("xyz", "XYZ", 4));
	printf("  strncmp(\"abc\", \"XYZ\", 4) returns %d\n", strncmp("abc", "XYZ", 4));
	printf("  strncmp(\"abc\", \"xYZ\", 4) returns %d\n", strncmp("abc", "xYZ", 4));
	printf("  --------------------------------------------------\n");

	printf("The recursive version:\n");
	printf("  strncmp_rec(\"abc\", \"abc\", 4) returns %d\n", strncmp_rec("abc", "abc", 4));
	printf("  strncmp_rec(\"abcde\", \"abc\", 4) returns %d\n", strncmp_rec("abcde", "abc", 4));
	printf("  strncmp_rec(\"abcde\", \"abc\", 3) returns %d\n", strncmp_rec("abcde", "abc", 3));
	printf("  strncmp_rec(\"abc\", \"abcde\", 4) returns %d\n", strncmp_rec("abc", "abcde", 4));
	printf("  strncmp_rec(\"abc\", \"abcde\", 3) returns %d\n", strncmp_rec("abc", "abcde", 3));
	printf("  strncmp_rec(\"xyz\", \"XYZ\", 4) returns %d\n", strncmp_rec("xyz", "XYZ", 4));
	printf("  strncmp_rec(\"abc\", \"XYZ\", 4) returns %d\n", strncmp_rec("abc", "XYZ", 4));
	printf("  strncmp_rec(\"abc\", \"xYZ\", 4) returns %d\n\n", strncmp_rec("abc", "xYZ", 4));
	
	return 0;
}
