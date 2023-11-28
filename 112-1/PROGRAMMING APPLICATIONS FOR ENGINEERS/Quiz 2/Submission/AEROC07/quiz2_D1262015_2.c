#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	char keyword[41]; // The keyword.
	int key_leng; // The length of the keyword. 
	char original_text[1001]; // The original input text.
	char encoded_text[1001]; // Encoded text.
	char decoded_text[1001]; // Decoded text.
	int i, j; // Loop variable. 

	scanf("%s", &keyword); // Input the keyword;
	key_leng = strlen(keyword); // Length of the keyword. 
	do {
		original_text[0] = getchar(); // Input a character from the console.
	} while (!isalpha(original_text[0])); // Continue until reaching the first letter.
  
	i = 1; // Inintial loop varible i to 1.
	do {
		original_text[i++] = getchar(); // Input a character from the console.
	} while (!feof(stdin)); // Stop until the end of file.
	original_text[i] = '\0'; // Insert end-of-string.
	
	printf("**** The keyword is: %s\n\n ",keyword );
	printf(">>>> The input origional text:\n\n%s\n\n",original_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	j=0;
    for (i=0;i<strlen(original_text); i++);
    
     if (isalpha(original_text[i])) {
     	encoded_text[j] = (keyword[j % key_leng] - 'A' + toupper(original_text[i]) - 'A') % 26 + 'A';
	 	j++;
	 }
     
    	
	

	encoded_text[j]='\0';
	printf(">>>> The encoded text:\n\n%s\n\n",encoded_text);
	
	printf("-------------------------------------------------------------------------\n");
	
	for(i=0; i<strlen(encoded_text); i++);
	decoded_text[i] = (encoded_text[i] - 'A' - (keyword[i%key_leng] -'A') + 26) % 26 + 'A' ;
	encoded_text[i] = '\0';
	// 6. Decode the encoded text and output the decoded result.
	printf(">>>> The decoded text:\n\n%s\n\n", decoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
