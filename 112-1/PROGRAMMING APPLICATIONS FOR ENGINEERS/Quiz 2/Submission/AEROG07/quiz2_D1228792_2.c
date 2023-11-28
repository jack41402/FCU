#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	char keyword[41]; // The keyword.
	int key_leng; // The length of the keyword. 
	char original_text[1001]; // The original input text.
	char big[1001];
	char encoded_text[1001]; // Encoded text.
	char decoded_text[1001]; // Decoded text.
	char book[26][26];
	int i, j; // Loop variable. 
	int k;
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			if((j-i)<0) k=26+j-i;
			else k=j-i;
			book[i][j]='A'+k%26;
		}
	}
//	for(i=0;i<26;i++){
//		for(j=0;j<26;j++){
//			printf("%c",book[i][j]);
//		}
//		printf("\n");
//	}
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
	printf("**** The keyword is: %s\n\n",keyword);
	printf(">>>> The input original text:\n\n%s\n",original_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	k=0;
	for(i=0;i<strlen(original_text);i++){
		if(isalpha(original_text[i])){
			if(islower(original_text[i])) big[k]=original_text[i]-'a'+'A';
			else big[k]=original_text[i];
			k++;
		}
	}
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
//	for(i=0;i<strlen(big);i++){
//		encoded_text[i]=book[keyword[i%strlen(keyword)]-'A'][big[i]-'A'];
//	}
//	encoded_text[strlen(big)]='\0';
	int m=0;
	for(i=0;i<strlen(big);i++){
		if((big[i]-(keyword[i%strlen(keyword)]-'A'))<'A'||(big[i]-(keyword[i%strlen(keyword)]-'A'))>'Z') m=26+(big[i]-(keyword[i%strlen(keyword)]-'A'));
		else m=big[i]-(keyword[i%strlen(keyword)]-'A');
		encoded_text[i]=m;
	}
	encoded_text[strlen(big)]='\0';
	printf(">>>>The encoded text:\n\n");
	printf("%s\n\n",encoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	m=0;
	for(i=0;i<strlen(encoded_text);i++){
		if((encoded_text[i]+(keyword[i%strlen(keyword)]-'A'))<'A'||(encoded_text[i]+(keyword[i%strlen(keyword)]-'A'))>'Z') m=(encoded_text[i]+(keyword[i%strlen(keyword)]-'A'))-26;
		else m=encoded_text[i]+(keyword[i%strlen(keyword)]-'A');
		encoded_text[i]=m;
	}
	printf(">>>>The dncoded text:\n\n");
	printf("%s\n\n",encoded_text);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
