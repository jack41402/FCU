#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(void) {
	char keyword[41];
	int key_leng;
	char original_text[1001];
	char encoded_text[1001];
	char decoded_text[1001];
	int i, j;
	scanf("%s", &keyword);
	key_leng = strlen(keyword);
	do {
		original_text[0] = getchar();
	} while (!isalpha(original_text[0]));
	i = 1;
	do {
		original_text[i++] = getchar();
	} while (!feof(stdin));
	original_text[i] = '\0';
	printf("**** The keyword is: %s\n\n", keyword);
	printf(">>>> The input original text: \n\n%s\n", original_text);
	printf("-------------------------------------------------------------------------\n"); 
	j = 0;
	for(i = 0 ; i < strlen(original_text) ; i++){
		if(isalpha(original_text[i])){
			encoded_text[j] = ((toupper(original_text[i]) - 'A') + (26 - (keyword[j % key_leng] -'A'))) % 26 + 'A';
			j++;
		}else{
			encoded_text[j] = original_text[i];
		}
	}
	encoded_text[j] = '\0';
	printf(">>>> The encoded text: \n\n%s\n\n", encoded_text);
	printf("-------------------------------------------------------------------------\n");
	for(i = 0 ; i < strlen(encoded_text) ; i++){
		if(isalpha(encoded_text[i])){
			int temp = (encoded_text[i] - 'A') + (keyword[i % key_leng] - 'A');
			if(temp<0){
				temp += 26;
			}
			decoded_text[i] = (temp % 26) + 'A';
		}else{
			decoded_text[i] = encoded_text[i];
		}
	}
	decoded_text[i] = '\0';
	printf(">>>> The decoded text: \n\n%s\n\n", decoded_text);
	printf("-------------------------------------------------------------------------\n");
	return 0;
}
