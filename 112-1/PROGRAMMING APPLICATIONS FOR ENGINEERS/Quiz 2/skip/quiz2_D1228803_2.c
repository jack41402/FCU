#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Remove white spaces and punctuation symbols;
char* f(char*p)
{
	int i, j;
	char original_text[1001];
	unsigned int len = strlen(p);
	
	for(i = 0; i < len; ++i)
	{
		for(j = 0; j < len; ++j)
		{
			if((!isalpha(original_text[0])))
			{
				len = len - 1;
				i -= 1;
			}
		}
	}
	return p;
}

//Convert all lower case letters to upper case letters
char* g(char* p)
{
	int i;
	unsigned int len = strlen(p);
	char original_text[1001];
	
	for(i = 0; i < len; ++i)
	{
		if(char* p(islower)
		{
			original_text = toupper(original_text);
		}
	}
	return p;
}


//Encode the text using the right-shift Vigenere square and output the encoded text;
char* h(char* p)
{
	char v[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
	
	int i;
	unsigned int len = strlen(p);
	
	for(i = 0; i < len; ++i)
	{
		if(i = )
		{
			
		}
	}
	return p;
}

//Decode the encoded text and output the decoded result.
void()
{
	char v[26] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
	
}

char* k(char* c, char* v)
{
	
	int i, j;
	do()
	while()
	return c;
}

int main(void) 
{
	char keyword[41]; // The keyword.
	int key_leng; // The length of the keyword. 
	char original_text[1001]; // The original input text.
	char encoded_text[1001]; // Encoded text.
	char decoded_text[1001]; // Decoded text.
	int i, j; // Loop variable. 

	// 1. Input a keyword and an English text;
	scanf("%s", &keyword); // Input the keyword;
	key_leng = strlen(keyword); // Length of the keyword. 
	
	/*
	do 
	{
		original_text[0] = getchar(); // Input a character from the console.
	} 
	while (!isalpha(original_text[0])); // Continue until reaching the first letter.
  
	i = 1; // Inintial loop varible i to 1.
	
	*/
	
	/*
	do 
	{
		original_text[i++] = getchar(); // Input a character from the console.
	} 
	while (!feof(stdin)); // Stop until the end of file.
	original_text[i] = '\0'; // Insert end-of-string.
  	*/
  	
  	f(string);
	g(string);
	h(string);
	
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	printf("**** The keyword is: ", original_text[1001]);
	printf(">>>> The input original text:");
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	printf(">>>> The encoded text:", encoded_text[1001]);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	// 6. Decode the encoded text and output the decoded result.
	printf(">>>> The decoded text:", decoded_text[1001]);
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
    
	return 0;
}


