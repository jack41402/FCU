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

	// 1. Input a keyword and an English text;
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
  
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	printf("The keywprd is: %s",keyword);
	printf("\n");
	printf(">>>>The original text is:\n\n");
	printf("%s",original_text);
	
	
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	
	j=0;
	for(i=0;i<strlen(original_text);i++){
		if(isalpha(original_text[i])){
			encoded_text[j]=((toupper(original_text[i]-'A')-(keyword[j%key_leng]-'A'))+26)%26+'A';
			j++;
		} 
	}
	encoded_text[j]='\0';
	printf(">>>>The encoded text : \n\n");
	printf("%s",encoded_text);
	
	// Output a separated line.
	printf("\n-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	
	// Output a separated line.
	
	for(i=0;i<strlen(encoded_text);i++){
		decoded_text[i]=(((encoded_text[i]-'A')+(keyword[j%key_leng]-'A')))%26+'A';
	}
	decoded_text[i]='\0';
	printf(">>>>The decoded text : \n\n");
	printf("%s",decoded_text);
	printf("\n-------------------------------------------------------------------------\n");
    
	return 0;
}
