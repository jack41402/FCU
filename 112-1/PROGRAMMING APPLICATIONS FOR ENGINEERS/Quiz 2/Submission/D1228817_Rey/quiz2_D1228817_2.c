#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int i, j; // Loop variable.

char* f(char* original_text){
	int l=strlen(original_text);
	for(i=0; i<l; i++){
		if(!isalpha(original_text[i])){
			for(j=i; j<l; j++){
				original_text[j]=original_text[j+1];
			}
			l-=1;
			i-=1;
		}
	}
}

char* g(char* original_text){
	int l=strlen(original_text);
	for(i=0; i<l; i++){
		if(original_text[i]>='a'&&original_text[i]<='z') original_text[i]=original_text[i]-'a'+'A';
	}
}

char* codebook_generate(char* original_text, char* key, int j, char*code_book){
	int lo=strlen(original_text);
	int lk=strlen(key);
	char k=key[j];
	
	for(i=0; i<26; i++){
		if(i<k-'A') code_book[i]='Z'-(k-'A')+i+1; 
		else code_book[i]='A'+i-(k-'A');
	}
	code_book[26]='\0';
}

char* decode(char* decoded_text){
	
}
int main(void) {
	char keyword[41]; // The keyword.
	int key_leng; // The length of the keyword. 
	char original_text[1001]; // The original input text.
	char encoded_text[1001]; // Encoded text.
	char decoded_text[1001]; // Decoded text.
	char key[1001];
	char code_book[26];
	 

	// 1. Input a keyword and an English text;
	printf("**** The keyword is: ");
	scanf("%s", &keyword);// Input the keyword;
	gets(original_text); 
	key_leng = strlen(keyword); // Length of the keyword. 
/*	do {
		original_text[0] = getchar(); // Input a character from the console.
	} while (!isalpha(original_text[0])); // Continue until reaching the first letter.
  
	i = 1; // Inintial loop varible i to 1.
	do {
		original_text[i++] = getchar(); // Input a character from the console.
	} while (!feof(stdin)); // Stop until the end of file.
	original_text[i] = '\0'; // Insert end-of-string.*/
	printf("\n>>>> The input original text: \n");
	gets(original_text);
	f(original_text);
	g(original_text);
	int l=strlen(original_text);
	//printf("%s", original_text);
	printf("\n");
	
	for(i=0; i<l; i++){
		key[i]=keyword[i%key_leng];
	}
	
	for(j=0; j<l; j++){
		codebook_generate(original_text, key, j, code_book);
		
	
		
		encoded_text[j]=code_book[original_text[j]-'A'];
			//printf("%s\n", code_book);
	}
	encoded_text[l]='\0';
	
	for(j=0; j<l; j++){
		codebook_generate(original_text, key, j, code_book);
		
			i=-1;
		
		do{
			i+=1;
		}while(encoded_text[j]!=code_book[i]);
		
		decoded_text[j]='A'+i;
		
	}

	decoded_text[l]='\0';
  
	// ***** Complete the rest of the program.
	// 2. Output the keyword the original text;
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n"); 
	
	printf(">>>>The encoded text: \n\n%s\n\n", encoded_text);
	
	// 3. Remove white spaces and punctuation symbols;
	// 4. Convert all lower case letters to upper case letters;
	// 5. Encode the text using the right-shift Vigenre square and output the encoded text.
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	
	
	printf(">>>>The decoded text: \n\n%s\n\n", decoded_text);
	
	// 6. Decode the encoded text and output the decoded result.
	
	// Output a separated line.
	printf("-------------------------------------------------------------------------\n");
	

    
	return 0;
}
