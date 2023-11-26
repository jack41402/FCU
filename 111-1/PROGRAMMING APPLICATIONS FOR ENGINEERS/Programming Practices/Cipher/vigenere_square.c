/*
  A more complicated cipher technique is polyalphabetic substitution cipher.
  It is more difficult to break a polyalphabetic substitution cipher. A Vigenere square
  with a keyword is used to encode a text of English letters. The first row of a Vigenere
  square is 26 English letters in the alphabetical order, then each of the next row 
  is one-letter rotation to the left of the original row. 
  Assume the maximum characters in the input length is 10,000.
  
  Write a C program to perform the following steps:
    1. Input a keyword and an English text;
    2. Remove white spaces and punctuation symbols;
    3. Convert all lower case letters to upper case letters;
    4. Encode the text using the Vigenère square and
    5. Output the original text and the encoded text;
    6. Decode the encoded text and output the decoding result.
  Assume the maximum characters in the input length is 10,000. You may use MDOS pipeline
  command to input (<) and output (>) the orginal text and the encoded text.

  Use MDOS pipeline commands to input (<) and output (>) the orginal text and the encoded text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
  char keyword[41]; // The keyword.
  int key_leng; // The length of the keyword. 
  char original_text[10001]; // The original input text.
  char encoded_text[10001]; // Encoded text.
  char decoded_text[10001]; // Decoded text.
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

  printf("**** The keyword is: %s\n\n", keyword); // Ouput the keyword.
  printf(">>>> The input original text:\n\n%s\n\n", original_text); // Output the original text.
  // Output a separated line.
  printf("-------------------------------------------------------------------------\n"); 
  
  j = 0; // Initail the index of the encoded text to 0.
  for (i=0; i<strlen(original_text); i++) // Scan the entire original text.
    // Convert English to upper case and encode a character.
    // keyword[j % key_leng]-'A': Index of the code book in Vigenere square.
    // toupper(original_text[i])-'A': Alphabetical oredering of the input character.
	// Add these two together because the code book start from letter keyword[j % key_leng].
	// Modulo 26 because when it reaches 'Z', the letter cyclically starts over from 'A'.
    if (isalpha(original_text[i])) {
	  encoded_text[j] = (keyword[j % key_leng] - 'A' + toupper(original_text[i]) - 'A') % 26 + 'A';
	  j++;
	}
  encoded_text[j] = '\0'; // Insert end-of-string.

  printf(">>>> The encoded text:\n\n%s\n\n", encoded_text); // Output the encoded text.
  // Output a separated line.
  printf("-------------------------------------------------------------------------\n");
  
  for (i=0; i<strlen(encoded_text); i++) // Scan the entire encoded text.
    // Decode a character.
    // This is the inverse function of the encoding formula.
    // 26 is added for the leters after 'Z' in the selected code book.
    decoded_text[i] = (encoded_text[i] - 'A' - (keyword[i % key_leng] - 'A') + 26 ) % 26 + 'A' ; 
  encoded_text[i] = '\0'; // Insert end-of-string.

  printf(">>>> The decoded text:\n\n%s\n\n", decoded_text); // Output the encoded text.
  // Output a separated line.
  printf("-------------------------------------------------------------------------\n");
    
  return 0;
}
