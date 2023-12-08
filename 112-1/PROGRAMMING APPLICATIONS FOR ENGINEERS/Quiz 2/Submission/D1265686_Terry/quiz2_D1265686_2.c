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
	
	printf("The keyword is: %s\n",keyword);
	printf("The input original text:\n\n");
	printf("%s",original_text);
	
	
	
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	
	// 3. Remove white spaces and punctuation symbols;
	char keyword2[41];
	j=0;
	for(i=0;i<key_leng;++i)
	{
		if(keyword[i]!=' ' && !ispunct(keyword[i]))
		{
			keyword2[j++]=keyword[i];
		}
	}
	keyword2[j]='\0';
	
	// 4. Convert all lower case letters to upper case letters;
	char keyword3[41];
	for(i=0;i<strlen(keyword2);++i)
	{
		keyword3[i]=toupper(keyword2[i]);
	}
	keyword3[i]='\0';
	
	
	char original_text2[41];
	int k=0;
	for(i=0;i<strlen(original_text);++i)
	{
		if(original_text[i]!=' ' && !ispunct(original_text2[i]))
		{
			original_text2[k++]=original_text[i];
		}
	}
	original_text2[k]='\0';
	
	char original_text3[41];
	for(i=0;i<strlen(original_text2);++i)
	{
		original_text3[i]=toupper(keyword3[i]);
	}
	original_text3[i]='\0';
	
	
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	
	for(i=0;i<strlen(original_text3);++i)
	{
		encoded_text[i]=(original_text3[i] + 26 - keyword3[i])%26;
	}
	encoded_text[i]='\0';
	printf("The encodeed text:\n\n");
	printf("%s",encoded_text);
	
	
	
	
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
