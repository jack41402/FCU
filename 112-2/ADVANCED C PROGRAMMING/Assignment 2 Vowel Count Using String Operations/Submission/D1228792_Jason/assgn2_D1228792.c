#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut; // Input and output file pointer.
	char *buffer; // Data buffer pointer.
	int capacity = 512;
	int count1=0,count2=0,count3=0,count4=0;
	int inx = 0; // Index of the input text.
    //Dynamically allocate 512 characters as the initial memory space of buffer[]. 
	buffer = (char *) malloc(capacity); // Initial memory allocation for text buffer.
	//    1) If the input character is an English letter, convert it to uppercase letter 
	//       and store in buffer[], starting from index 0. When the memory space of buffer[] 
	//       becomes full, extend the size of buffer 512 bytes more.
	//    2) If the input character is not an English letter, ignore it.
	int i=0,k;
	fptrIn =fopen("Gift_of_Magi.txt","r");
	do{
		if(i%512==0&&i!=0) buffer = (char *) realloc(buffer, i+512);
		inx =fgetc(fptrIn);
		if(inx>='a'&&inx<='z'){
			buffer[i]=inx-'a'+'A';
			i++;
		}
		else if(inx>='A'&&inx<='Z'){
			buffer[i]=inx;
			i++;
		}
		if(feof(fptrIn)) break;
	}while(1);
	fclose(fptrIn);
	// Insert end-of-string ¡®\0¡¯ following the last input character. 
	//         Print the number of input English letters, i.e., the length of string.
	buffer[i]='\0';
	printf(">>>> Total input English characters: %d.\n",i);
	printf("***********************************************************************\n\n");
	printf(">>>> The first 800 characters are:");
	// Open an output text file "result.txt" and write the file using fwrite(). 
	fptrOut =fopen("result.txt","w+");
	fwrite(buffer,1,i,fptrOut);
	//Print the first 800 characters of the modified text on the monitor,
	//80 characters in a line.
	rewind(fptrOut);
	for(k=0;k<800;k++){
		if(k%80==0){
			printf("\n  ");
		}
		inx =fgetc(fptrOut);
		printf("%c",inx);
	}
	fclose(fptrOut);
	//Count and report the number of one character letter, two contiguous
	//character letters, three contiguous character letters, and four or
	//more contiguous character letters.
	int y=0;
	for(k=0;k<i;k++){
		if(buffer[k]==buffer[k+1]){
			if(buffer[k+1]==buffer[k+2]){
				if(buffer[k+2]==buffer[k+3]){
					count4++;
					k+=3;
					do{
						if(buffer[k+3+y]==buffer[k+3+y+1]) k++;
						y++;
					}while(buffer[k+3+y]!=buffer[k+3+y+1]);
				}
				else{
					count3++;
					k+=2;
				}
			}
			else{
				count2++;
				k+=1;
			}
		}
		else{
			count1++;
		}
	}
	printf("\n\n***********************************************************************\n\n");
	printf(">>>> The number of contigious letter(s) are:\n");
	printf("  One character: %d\n",count1);
	printf("  Two contigious characters: %d\n",count2);
	printf("  Three contigious characters: %d\n",count3);
	printf("  Four or more contigious characters: %d\n",count4);
	printf("  **** Total character counts: %d\n",i);
	printf("***********************************************************************\n\n");
	//Count and report the number of each occurence of vowels,
	//'A', 'E', 'I', 'O', and 'U'.
	int counta=0,counte=0,counti=0,counto=0,countu=0;
	for(k=0;k<i;k++){
		if(buffer[k]=='A'){
			counta++;
		}
		else if(buffer[k]=='E'){
			counte++;
		}
		else if(buffer[k]=='I'){
			counti++;
		}
		else if(buffer[k]=='O'){
			counto++;
		}
		else if(buffer[k]=='U'){
			countu++;
		}
	}
	printf(">>>> The number of occurences of vowels:\n");
	printf("  Vowel 'A': %d\n",counta);
	printf("  Vowel 'E': %d\n",counte);
	printf("  Vowel 'I': %d\n",counti);
	printf("  Vowel 'O': %d\n",counto);
	printf("  Vowel 'U': %d\n",countu);
	printf("  **** Total vowel count: %d\n",counta+counte+counti+counto+countu);
	printf("***********************************************************************"); 
	//Release memory space of buffer[].
  	free(buffer);
	return 0;
}  
