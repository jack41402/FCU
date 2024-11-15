#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	// The first code book. 
	//                     A    B    C    D    E    F    G    H    I    J    K    L    M    
	char code_book[26] = {'N', 'E', 'I', 'Q', 'O', 'Y', 'A', 'R', 'D', 'C', 'S', 'H', 'X',  
	//                     N    O    P    Q    R    S    T    U    V    W    X    Y    Z   
  	                      'Z', 'B', 'P', 'J', 'T', 'K', 'U', 'F', 'L', 'V', 'G', 'W', 'M'};
	char decode_book[26]; // Decode book, generated by the program.
	char keyword[41]; // The keyword.
	int selected_book;
	int key_leng; // The length of the keyword. 
	char original_text[101]; // The original input text.
	char encoded_text[101]; // Encoded text.
	char decoded_text[101]; // Decoded text.
	int i, j; // Loop variable. 
	
	printf("Enter a keyword: "); // Input the keyword;
	scanf("%s", &keyword);
	getchar();
	printf("\n");
	key_leng = strlen(keyword); // Length of the keyword. 
  
	printf("Enter a line of English text: "); // Input the testing text.
	i = 0; // Inintial loop varible i to 0.
	do {
		original_text[i++] = getchar(); // Input a character from the console.
	} while (original_text[i-1] != '\n'); // Stop until the newline.
	original_text[i-1] = '\0'; // Insert end-of-string.

	printf("\n**** The keyword is: %s\n", keyword); // Ouput the keyword.
	printf(">>>> The original text: %s\n\n", original_text); // Output the original text.
  
	// Create the decode book.
	for (i=0; i<26; i++) decode_book[code_book[i]-'A'] = i + 'A'; 
  
	// Print the code book.
	printf(">>>> The first code book:\n    ");
	for (i=0; i<26; i++) printf("%c ", 'A'+i);
	printf("\n    ");
	for (i=0; i<26; i++) printf("%c ", code_book[i]);
	printf("\n\n");
  
	// Print the code book.
	printf(">>>> The first decode book:\n    ");
	for (i=0; i<26; i++) printf("%c ", 'A'+i);
	printf("\n    ");
	for (i=0; i<26; i++) printf("%c ", decode_book[i]);
	printf("\n\n");
  
	j = 0; // Initial the index of the encoded text to 0.
	for (i=0; i<strlen(original_text); i++) // Scan the entire original text.
		// Convert English to upper case and encode a character.
		// decode_book[keyword[j % key_leng] - 'A'] - 'A': Index of the selected code book.
		// toupper(original_text[i])-'A': Alphabetical oredering of the input character.
		// Add these two together because the selected book is the 1st code book with a shift of 
		// the selected code book index.
		// Modulo 26 because it is the length of the code book.
		if (isalpha(original_text[i])) {
			selected_book = decode_book[keyword[j % key_leng] - 'A'] - 'A'; // Index of the selected book.
			encoded_text[j] = code_book[(toupper(original_text[i]) - 'A' + selected_book) % 26];
			j++;
		}
	encoded_text[j] = '\0'; // Insert end-of-string.

	printf(">>>> The encoded text: %s\n\n", encoded_text); // Output the encoded text.
  
	for (i=0; i<strlen(encoded_text); i++) { // Scan the entire encoded text.
		// Decode a character.
		// This is the inverse function of the encoding formula, but uses the origianl keyword 
		// to search for the selected book.
		selected_book = decode_book[keyword[i % key_leng] - 'A'] - 'A';
		decoded_text[i] = (decode_book[encoded_text[i] - 'A'] -'A' - selected_book + 26) % 26 + 'A';
	}
	decoded_text[i] = '\0'; // Insert end-of-string.

	printf(">>>> The decoded text: %s\n\n", decoded_text); // Output the decoded text.

	return 0;
}
