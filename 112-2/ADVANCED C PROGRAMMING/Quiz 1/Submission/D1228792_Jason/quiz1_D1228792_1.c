#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function implementation of strncmp().
int strncmp_rec(const char *str1, const char *str2, size_t n) {
	// ***** Complete this function. 
	// DO NOT use any <string.h> functions in the the implementation of strncmp_rec().
	int j;
	int i=0;
	while(str1[0]!=NULL&&str2[0]!=NULL&&i<n){
		if(str1[0]==str2[0]){
			str1++;
			str2++;
			i++;
			strncmp_rec(str1,str2,1);
		}
		else break;
	}
	printf("%d",i);
	if(i+1==n){
		return 0;	
	}
	if(i<n);
	if(str1[0]>str2[0]){
		return 1;
	}
	else if(str1[0]<str2[0]){
		return -1;
	}
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
	printf("  strncmp_rec(\"abc\", \"xYZ\", 4) returns %d\n\n", strncmp_rec("abc", "xYZ", -1));
	
	return 0;
}
