#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrin, *fptrout; 
	char *buffer;
	int capacity = 512;
	int inx = 0; 
	int i, j;
	char onechrtr[2];
	int chrtrcount[4] = {0};
	char* chrtr;
	int totalchrtr = 0;
	int length;
	char vowel[] = "AEIOU";
	int countvowel[5] = {0};
	int totalvowel = 0;
	
    // Dynamically allocate 512 characters as the initial memory space of buffer[]. 
	buffer = (char *) malloc(capacity *sizeof(char)); // Initial memory allocation for text buffer.
	 
	//Open "Gift_of_Magi.txt" then read the file

	fptrin = fopen("Gift_of_Magi.txt", "r");
	while(!feof(fptrin)){
		buffer[inx] = fgetc(fptrin);
		if (isalpha(buffer[inx])){
			buffer[inx] = toupper(buffer[inx]);
			inx++;
			if(inx == capacity){
				capacity += 512;
				buffer = (char* )realloc(buffer, capacity *sizeof(char));
			}
		}
	}
	buffer[inx] = '\0';
	printf("The input English characters: %d.\n", inx);
	printf("***********************************************************************\n");
	fclose(fptrin);
	
	//Open an output file "result.txt" and write the file
	fptrout = fopen("result.txt", "w");
	fwrite(buffer, 1, inx, fptrout);
	
	//Print the first 800 characters
	printf("\nThe first 800 characters are:\n");
	for (i=0; i<800; i++){
		if(i%80 == 0){
			printf("  ");
		}
		printf("%c", buffer[i]);
		if ((i+1)%80==0){
			printf("\n");
		}
	}
	printf("***********************************************************************\n\n");
	fclose(fptrout);
	
	//Count and report the number of contigious characters letters, 
	onechrtr[1] = '\0';
	totalchrtr = 0;
	chrtr = buffer;
	
	while(chrtr[0] != '\0'){
		onechrtr[0] = chrtr[0];
		length = strspn(chrtr, onechrtr);
		totalchrtr += length;
		chrtr = chrtr + length;
		if (length > 4) length = 4;
		chrtrcount[length-1]++;
	}
	
	// print contiguous letter count.
	printf(">>>> The number of contiguous letter(s) are:\n"); 
	printf("  One character: %u\n", chrtrcount[0]); 
	printf("  Two contiguous characters: %u\n", chrtrcount[1]); 
	printf("  Three contiguous characters: %u\n", chrtrcount[2]); 
	printf("  Four or more contiguous characters: %u\n", chrtrcount[3]); 
	printf("  **** Total characater counts: %u\n", totalchrtr); 
	printf("***********************************************************************\n\n");
  	
	// count the number of vowels,	
	for(i=0; i<inx; i++){
		if(buffer[i] == 'A'){
			countvowel[0]++;
			totalvowel++;
		}
		else if(buffer[i] == 'E'){
			countvowel[1]++;
			totalvowel++;
		}
		else if(buffer[i] == 'I'){
			countvowel[2]++;
			totalvowel++;
		}
		else if(buffer[i] == 'O'){
			countvowel[3]++;
			totalvowel++;
		}
		else if(buffer[i] == 'U'){
			countvowel[4]++;
			totalvowel++;
		}
	}
	printf(">>>> The number of occurences of vowels:\n");
	for (i=0; i<5; i++) 
		printf("  Vowel \'%c\': %u\n", vowel[i], countvowel[i]);
	printf("  **** Total vowel count: %u\n", totalvowel);
	printf("***********************************************************************\n\n");
	
	//Release memory.
	free(buffer);
}  

