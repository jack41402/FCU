#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char space(char *b, char *c)
{
	int i, j=0;
	for (i=0; i<strlen(b); i++)
	{
		if (b[i]!= ' ')
		{
			c[j]= b[i];
			j++;
		} 
		else
		{
			continue;
		}
	}
	return 0;
}

char upper(char *d)
{
	int i;
	for (i=0; i<strlen(d); i++)
	{
		if ('a'<=d[i] && d[i]<='z')
		{
			d[i]= d[i]-32;
		}
		else 
		{
			d[i]= d[i];
		}
	}
	return 0;
}

int main(void) {
	char keyword[41]; // The keyword.
	int key_leng; // The length of the keyword. 
	char original_text[1001]; // The original input text.
	char encoded_text[1001]; // Encoded text.
	char decoded_text[1001]; // Decoded text.
	int i, j; // Loop variable. 
	char original_text_2[1001];

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
	
	printf("The input original text:\n");
	printf("%s\n", original_text);
	

  
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	printf("The encoded text:\n");
	j=0;
	space(original_text, original_text_2);
	upper(original_text_2);
	//printf("%s\n", original_text_2);
	for (i=0; i<strlen(original_text_2); i++)
	{
		encoded_text[i]= ((original_text_2[i]-'A')+ (keyword[j% key_leng]-'A')+ 'A');
		j++;
	}
	printf("%s\n", encoded_text);
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	printf("The decoded text:\n");
	j=0;
	for (i=0; i<strlen(encoded_text); i++)
	{
		decoded_text[i]= (encoded_text[i]- 'A')+ (keyword[j% key_leng]- 'A')+ 'A';
		j++;
	}
	printf("%s\n", decoded_text);
	// 6. Decode the encoded text and output the decoded result.
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}
