#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
char *buffer;
buffer= (char*) malloc(sizeof(char)*512);

FILE *F_in, *F_out;
F_in=fopen("Gift_of_Magi.txt", "r");

int index=0;//Index of the elements inside buffer
int i;//Loop variable
int count;//Variable used for counting
int contiguous[4]={0, 0, 0, 0};//Array used for counting number of contiguous words
int vowel_count[5]={0, 0, 0, 0, 0};//Array used for calculating number of vowels
char temp;//Variable used for temporarily storing a character
char vowels[5]={'A', 'E', 'I', 'O', 'U'};
char* ptr;//Pointer used with strpbrk to calculate number of vowels 

while(!feof(F_in)){//Loop ends when end of file is reached
	temp=fgetc(F_in);
	if(isalpha(temp)){//Check if the character being read is an English letter
		if(index>511){
			buffer= (char*) realloc(buffer, sizeof(char)*(512+index-511));//Allocates additional space for buffer
		}
		buffer[index]=toupper(temp);//Turn the letters into uppercase
		index++;//Increment the index
	}
}
buffer[index]='\0';//Add end of string at the end of buffer
fclose(F_in);

printf("Total input English characters: %d.\n", index);
printf("*********************************************************************");
printf("\n\n>>>> The first 800 characters are: \n");

F_out=fopen("result.txt", "w");//Create a file called "result.txt"

fwrite(buffer, 1, index, F_out);//Copy the contents of buffer to result.txt

fclose(F_out);

for(i=0; i<800; i++){
	if(i%80==0){
		printf("\n%c", buffer[i]);
	}
	else printf("%c", buffer[i]);
}
printf("\n\n*********************************************************************\n\n");

index=0;
while(buffer[index]!='\0'){//Loop ends when the end of buffer is reached
	temp=buffer[index];
	count=0;
	while(temp==buffer[index]){//Checks for contiguous character letters
		count+=1;
		index++;
	}
	
	switch (count){//Adds up the number of the different cases of contiguous character letters
		case 1:
			contiguous[0]++;
			break;
		case 2:
			contiguous[1]++;
			break;
		case 3:
			contiguous[2]++;
			break;
		default:
			contiguous[3]++;
	}
}

printf("The number of contiguous letter(s) are:\n");
printf("  One character: %d\n", contiguous[0]);
printf("  Two contiguous characters: %d\n", contiguous[1]);
printf("  Three contiguous characters: %d\n", contiguous[2]);
printf("  Four or more contiguous characters: %d\n", contiguous[3]);
printf("  **** Total character counts: %d", index);

ptr=buffer-1;
while(1){
	ptr=strpbrk(ptr+1, vowels);//Checks for vowels in buffer and return their position
	if(ptr==NULL) break;//Loop breaks when the end of buffer is reached
	else{
		switch(*ptr){//Adds up the number of each of the vowels
			case 'A':
				vowel_count[0]++;
				break;
			case 'E':
				vowel_count[1]++;
				break;
			case 'I':
				vowel_count[2]++;
				break;
			case 'O':
				vowel_count[3]++;
				break;
			case 'U':
				vowel_count[4]++;
		}
	}
}

printf("\n*********************************************************************\n\n");
printf(">>>> The number of occurences of vowels:\n");
printf("  Vowel \'A\' : %d\n", vowel_count[0]);
printf("  Vowel \'E\' : %d\n", vowel_count[1]);
printf("  Vowel \'I\' : %d\n", vowel_count[2]);
printf("  Vowel \'O\' : %d\n", vowel_count[3]);
printf("  Vowel \'U\' : %d\n", vowel_count[4]);
count=0;
for(i=0; i<5; i++) count+=vowel_count[i];//Calcualte the total number of vowel
printf("  **** Total vowel count: %d", count);
printf("\n*********************************************************************");

free(buffer);
return 0;
}
