#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive function implementation of strncmp().
int strncmp_rec(const char *str1, const char *str2, size_t n) {
	// ***** Complete this function. 
	 int result=0;
	if(str1[n]!='\0'&&str2[n]!='\0'){
		
			if(str1[n]==str2[n]) return 0;
			
			else if(str1[n]>str2[n]) return 1;
			else if(str1[n]<str2[n]) return -1;
			if(!result&&str1[n]!='\0') return 1;
			else if(!result&&str2[n]!='\0') return -1;
			
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
	printf("  strncmp_rec(\"abc\", \"xYZ\", 4) returns %d\n\n", strncmp_rec("abc", "xYZ", 4));
	
	return 0;
}