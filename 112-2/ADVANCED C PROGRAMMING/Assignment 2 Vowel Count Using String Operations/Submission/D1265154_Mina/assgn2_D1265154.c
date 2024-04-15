#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(void) {
	char *buffer;//data buffer pointer.
	FILE *fptrIn, *fptrOut; //input and output file pointer
	int inx=0;//index of the input text
	int capacity=512;
	char *ptr;//character pointers for scanning characters
	char vowels[]="AEIOU";//vowels
	char one_char[2];//to construct one-character string
	unsigned int i;//loop variable
	unsigned int length; //length of letter sequence
	unsigned int total_count;//total count of characcters
	unsigned int word_count[7]={0, 0, 0, 0, 0, 0, 0};//number of words with length 1 to 6 and over 6 
	unsigned int vowel_count[5]={0, 0, 0, 0, 0};//number of vowels 'A' 'E' 'I' 'O' and 'U'
	unsigned int char_count[4]={0, 0, 0, 0};//number 1, 2, 3, and over 3 contiguous characters
	buffer=(char *)malloc(capacity);//allocate memory for text buffer with initial capacity
	fptrIn=fopen("Gift_of_Magi.txt","r");// Open input text file "Gift_of_Magi.txt" in read mode
	while(!feof(fptrIn)){
    buffer[inx]=fgetc(fptrIn);//read character from file and store it in buffer at index inx
    if(isalpha(buffer[inx])) {
		buffer[inx]=toupper(buffer[inx]);//convert the character to uppercase
        inx++;//increment the index for buffer
	if (inx==capacity){//check if buffer is full and needs resizing
            capacity += 512;//increase capacity by 512 bytes
            buffer = (char *)realloc(buffer, capacity); //reallocate memory for buffer with increased capacity
        }
    	}
	}  
	buffer[inx]='\0';//null-terminate the buffer to mark the end of the string
	printf(">>>> Total input English characters: %d.\n",inx);
	printf("");//print an empty string
	fclose(fptrIn);//close the input file
	printf("***********************************************************************\n\n");
	fptrOut = fopen("result.txt", "w");//open output file
	fwrite(buffer, 1, inx, fptrOut);//write data from the data buffer to the output file
	fclose(fptrOut);//close the output file
	printf(">>>> The first 800 characters are:\n ");//print the first 500 characters
	for (i=0;i<800; i++) {//800 characters in a line
		if ((i+1)%80==0)  printf("%c\n  ", buffer[i]);//if it is not a full line, print the character only
		else printf("%c", buffer[i]);//if it is a full line, print the character and a new line
	}
	printf("\n");
	printf("***********************************************************************\n\n");
	ptr=buffer;//start from the beginning of the text.
	one_char[1]='\0';//since the string is of length 1, insert end-of-string in the second array element.
	total_count=0;//reset total character count to 0.
	while(ptr[0]!='\0'){ //continue, When there are more letters.
		one_char[0]=ptr[0];//insert the letter.
		length=strspn(ptr,one_char);//find the length of the contiguous letter.
		total_count+=length;//sum up the total character count.
		ptr=ptr+length; //move to the address of the next distinguished letter.
		length= length<4?length:4;//if the length is over four, set it to 4.
		++char_count[length-1];//increment the contiguous letter count
	}
	printf(">>>> The number of contiguous letter(s) are:\n");//print contiguous letter count
	printf("  One character: %u\n", char_count[0]);//one-letter count
	printf("  Two contiguous characters: %u\n", char_count[1]);//two-letter count
	printf("  Three contiguous characters: %u\n", char_count[2]);//three-letter count
	printf("  Four or more contiguous characters: %u\n", char_count[3]);//four-letter or more count
	printf("  **** Total characater counts: %u\n", total_count);//total letter count
	printf("***********************************************************************\n\n");
 	ptr=(char *)strpbrk(buffer, vowels);//find the first vowel
	total_count=0;//reset total vowel count to 0
	while(ptr!=NULL) {//continue, when there are more vowels
		switch (*ptr) {//check the case of the vowel
			case'A':{++vowel_count[0]; break;}//vowel A, increment its count
			case'E':{++vowel_count[1]; break;}//vowel E, increment its count
			case'I':{++vowel_count[2]; break;}//vowel I, increment its count
			case'O':{++vowel_count[3]; break;}//vowel O, increment its count
			case'U':{++vowel_count[4]; break;}//vowel U, increment its count
		}
		ptr=(char *)strpbrk(ptr+1, vowels);//find the next vowel
		total_count++;//increment total vowel count.
	}
	printf(">>>> The number of occurences of vowels:\n");//report vowel counts
	for (i=0;i<5;i++)//print vowel count
		printf("  Vowel \'%c\': %u\n", vowels[i], vowel_count[i]);
	printf("  **** Total vowel count: %u\n", total_count);
	printf("***********************************************************************\n\n");
	free(buffer);//free the dynamically allocated memory for the buffer
	return 0;
}  
