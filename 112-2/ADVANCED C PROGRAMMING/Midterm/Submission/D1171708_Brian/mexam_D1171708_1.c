#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Iterative function implementation of strncpy().
char *strncpy_ite(char *str1, const char *str2, size_t n) {
	// ***** Complete this function. 
	// DO NOT use any <string.h> functions in the the implementation of strncpy_ite().
	int i = 0;
	while(str2[i]!='\0' && i<n){
		str1[i] = str2[i];
		i++;
	} 
	str1[i] = '\0';
	return str1;
}

// DO NOT modify the main program. 
int main(void) {
	char str[100];
	printf("Tests of string copy with length n:\n\n");
	printf("The library version:\n");
	printf("  strncpy(str, \"abc\", 4) returns %s and str is %s. \n", strncpy(str, "abc", 4), str);
	printf("  strncpy(str, \"abcd\", 4) returns %s and str is %s. \n", strncpy(str, "abcd", 4), str);
	printf("  strncpy(str, \"abcde\", 4) returns %s and str is %s. \n", strncpy(str, "abcde", 4), str);
	printf("  --------------------------------------------------\n");
	printf("  strncpy_ite(str, \"abc\", 4) returns %s and str is %s. \n", strncpy_ite(str, "abc", 4), str);
	printf("  strncpy_ite(str, \"abcd\", 4) returns %s and str is %s. \n", strncpy_ite(str, "abcd", 4), str);
	printf("  strncpy_ite(str, \"abcde\", 4) returns %s and str is %s. \n", strncpy_ite(str, "abcde", 4), str);
	
	return 0;
}