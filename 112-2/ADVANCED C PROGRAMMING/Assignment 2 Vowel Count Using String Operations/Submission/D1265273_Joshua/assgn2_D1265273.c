#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut; // Input and output file pointer.
	char *buffer; // Data buffer pointer.
	int capacity = 512;//make the initial capacity to 512 
	int inx = 0, j; // Index of the input text.
	int c_1=0, c_2=0, c_3=0, c_4=0;//declare variable for the count of one to four contiguous word
	
	buffer = (char *) malloc(capacity); // Initial memory allocation for text buffer.
	 
	fptrIn= fopen("Gift_of_Magi.txt", "r");// Open the input text file "Gift_of_Magi.txt"
	if (fptrIn==NULL)//if the file doesn't exist any thing, print the sentence "cannot open the file
	{
		printf("\ncannot open the file");
		exit(1);
	}
	int i=0, k;//define variable
	while(1)
	{
		if (i%512==0&&i!=0)
			{
				buffer= (char *)realloc(buffer, i+512);//plus 512 space of memory
			}
		inx= fgetc(fptrIn);//read the file with fgetc
		if (isalpha(inx))//read only alphabet
		{
			buffer[i]= toupper(inx);//l let every alphabet to uppercase
			i++;
		}
		if (feof(fptrIn))
			{
				break;//if fptrIn is read to the end, break
			}
	}
	fclose(fptrIn);//close fptrIn

	buffer[i+1]= '\0';//add '\0'to buffer
	printf(">>>> Total input English chatacters: %d\n", i);
	printf("***********************************************************************\n\n");
	printf(">>>> The first 800 characters are: ");
	
	fptrOut= fopen("result.txt", "w+");//open the file of result.txt that can write and read
	for (k=0; k<=i; k++)
	{
		fwrite(&buffer[k], sizeof(buffer[k]), 1, fptrOut);//write buffer into fptrOut
	}
	
	rewind(fptrOut);//let the pointer of fptrOut to the first
	for(k=0; k<800; k++)
	{
		if (k%80==0)//every line will contain only 80 words
		{
			printf("\n  ");
		}
		inx= fgetc(fptrOut);//read the fptrOut with fgetc 
		printf("%c", inx);//print out the first 800 words of fptrOut
	}
	fclose(fptrOut);//close fptrOut
	printf("\n\n***********************************************************************\n\n");
	printf(">>>> The number of contigous letter(s) are:\n");
	// Count the number of one character letter, two contiguous
	//         character letters, three contiguous character letters, and four or
	//         more contiguous character letters.
	for (k=0; k<i; k++)
	{
		if (buffer[k]!=buffer[k+1])//if the current letter isn't identical with the next one, it is only one character
		{
			c_1++;
		}
		else if (buffer[k]==buffer[k+1])//if the current letter is identical with the next one, check the third one
		{
			if (buffer[k+1]!=buffer[k+2])//if the second one isn't the same with the third one, it is the two contiguous word
			{
				c_2++;
				k=k+1;
			}
			else if (buffer[k+1]==buffer[k+2])//if the second one is identical with the third one, it is the three contiguous word
			{
				c_3++;
				k=k+2;
			}
			else //the rest situation is the four contiguous character letters or more contiguous character letters
			{
				c_4++;
				k=k+3;
			}
		}
		
	}
	//print the number of one character, two contiguous, three contiguous and four or more contiguous characters
	printf("  One character: %d\n", c_1);
	printf("  Two contiguous characters: %d\n", c_2);
	printf("  Three contiguous characters: %d\n", c_3);
	printf("  Four or more contiguous characters: %d\n", c_4);
	printf("  **** Total character counts: %d\n", c_1+c_2+c_3+c_4);
	printf("***********************************************************************\n\n");
	printf(">>>> The number of occurences of vowels:\n");
	int count_a=0, count_e=0, count_i=0, count_o=0, count_u=0;//define the variable
	for (k=0; k<i; k++)
	{
		if (buffer[k]=='A')//check the anount of A
		{
			count_a++;
		}
		else if (buffer[k]=='E')//check the amount of E
		{
			count_e++;
		}
		else if (buffer[k]=='I')//check the amount of I
		{
			count_i++;
		}
		else if (buffer[k]=='O')//check the amount of O
		{
			count_o++;
		}
		else if (buffer[k]=='U')//check the amount of U
		{
			count_u++;
		}
	}
	//print out the number of A, E, I, O, U 
	printf("  Vowel 'A': %d\n ", count_a);
	printf(" Vowel 'E': %d\n ", count_e);
	printf(" Vowel 'I': %d\n ", count_i);
	printf(" Vowel 'O': %d\n ", count_o);
	printf(" Vowel 'U': %d\n ", count_u);
	printf(" **** Total vowel count: %d\n", count_a+count_e+count_i+count_o+count_u);
	printf("***********************************************************************");
	// Release memory space 
  free(buffer);
  
	return 0;
}  

