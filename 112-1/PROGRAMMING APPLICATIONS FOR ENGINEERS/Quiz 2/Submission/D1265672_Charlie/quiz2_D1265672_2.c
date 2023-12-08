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
	
	int leng;

	// 1. Input a keyword and an English text;
	// fgets(keyword,41,stdin); test use
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
  	
  	// fgets(original_text,1001,stdin); test use
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	printf("**** The keyword is: %s\n", keyword);
	printf("\n>>>> The input original text:\n");
	printf("\n%s\n", original_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	j = 0;
	// 3. Remove white spaces and punctuation symbols;
	for(i=0; i<strlen(original_text);i++){
		if (original_text[i] != ' '){
			encoded_text[j] = original_text[i];
			j++;
		}
	}
	encoded_text[j] = '\0';
	for(i=0;i<strlen(encoded_text);i++)
		encoded_text[i]=toupper(encoded_text[i]);
	strcpy(decoded_text, encoded_text);
	
	// 4. Convert all lower case letters to upper case letters;
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	leng = strlen(keyword);
	j = 0;
	int ans;
	for(i=0;i<strlen(encoded_text);i++){
		if (j>=leng-1){
			j=0;
		}
		ans = encoded_text[i] - keyword[j];
		if (ans>=0){
			encoded_text[i] = ans + 'A';
		}
		else{
			encoded_text[i] = ans + 1 + 'Z';
		}
		j++;
	}
	
	printf(">>>> The encoded text:\n");
	printf("\n%s\n\n", encoded_text);
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	printf(">>>> The decoded text:\n");
	printf("\n%s\n\n", decoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
