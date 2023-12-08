#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	char keyword[41]; // The keyword.
	int key_leng, numorg, numkey; // The length of the keyword. 
	char original_text[1001] = {};
	char newtext[1001]= {};  // The original input text.
	char encoded_text[1001] = {}; // Encoded text.
	char decoded_text[1001] = {}; // Decoded text.
	int i, j, oldl = 0, newl = 0; // Loop variable. 

	// 1. Input a keyword and an English text;
	scanf("%s", &keyword); // Input the keyword;
	key_leng = strlen(keyword); // Length of the keyword. 

	do {
		original_text[oldl] = getchar();
		oldl++; // Input a character from the console.
	} while (!feof(stdin)); // Stop until the end of file.
	original_text[oldl] = '\0'; // Insert end-of-string.

  
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	printf("****The keyword is: %s \n", keyword);
	printf(">>>>The input original text:\n%s", original_text );
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	for(i=0; i<oldl; i++){
		if(isalpha(original_text[i])){
			newtext[newl] = toupper(original_text[i]);
//			printf("%c\n", newtext[newl]);
			newl++;
		}
	}
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	int n1, mns, key;
	char mnsvalue[1001],keyvalue[10001];
	for(i=0; i<newl; i++){
		n1 = newtext[i] - 'A';
		key = keyword[i%key_leng] - 'A';
		mns = n1 - key;
		mnsvalue[i] = mns;
		keyvalue[i] = key;
		if (mns >= 0){
			encoded_text[i] = 'A' + mns;	
		}
		else{
			encoded_text[i] = 'Z' + mns + 1;
		}
	}

	printf(">>>>The encoded text is:\n%s\n", encoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	for(i=0; i<newl; i++){
		if(mnsvalue[i] >= 0){
			decoded_text[i] = encoded_text[i] + keyvalue[i];
		}
		else{
			decoded_text[i] = encoded_text[i] - 'Z' + 1 + keyvalue[i] + 'A';
		}
	}
	printf(">>>>The decoded text is:\n%s\n", decoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
