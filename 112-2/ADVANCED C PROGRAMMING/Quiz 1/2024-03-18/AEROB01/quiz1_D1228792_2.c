#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	// 1. Declare ¡°char *dataIn, *dataOut¡± to be pointers of input and output data strings,
	//    respectively.
	FILE *fileIn, *fileOut; // Stream pointers for input and output files.
	char *dataIn, *dataOut; // Buffers for input and output data.
	char *ptr1, *ptr2; // String pointers for modifying inptut text data.
	// alhpanumerical characters.
	char alphanum[63] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int lengthIn, lengthOut; // Data length for input and output data.
	int lengthStr; // Legth of consecutive alphanumerical characters.
	int i, j ; // Data indexes.
	int k=1,x=1;
	int count=0;
	// ***** Complete the following steps. 
  
	// 2. Use file FCU.txt as the input testing file.
	fileIn = fopen("FCU.txt","r");
	
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  	dataIn = (char *) malloc(k);
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	do{
  		dataIn[k-1] = fgetc(fileIn);
  		k++;
  		dataIn = (char *) realloc(dataIn,k);
  		if(feof(fileIn)) break;
	  }while(1);
	printf(">>>> Input data string:\n");
	for(i=0;i<k;i++){
		printf("%c",dataIn[i]);
	}
	fclose(fileIn);
	printf("\n\n>>>> Modified data string:");
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
	j=0;
	for(i=0;i<k;i++){
		if(isalnum(dataIn[i])) count++;
	}
	for(i=0;i<k;i++){
		if(isalnum(dataIn[i])){
			dataIn[j]=dataIn[i];
			j++;
		}
	}
	dataIn[count]='\0';
	for(i=0;i<count;i++){
		if(i%80==0){
			printf("\n");
		}
		printf("%c",dataIn[i]); 
	}
	printf("\n\n\n>>>> Output data string:");
	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
	//    80 characters in a line.
	dataOut = (char *) malloc(x);
	do{
  		dataOut[x-1] = dataIn[x-1];
  		x++;
  		dataOut = (char *) realloc(dataOut,x);
	  }while(x<=count);
	  dataOut = (char *) realloc(dataOut,x+5);
	  for(i=x-1;i<x+4;i++){
	  	dataOut[i]='#';
	  }
	  x+=5;
	  i=0;
	do{
		dataOut[x-1] = dataIn[count-1-i];
  		x++;
  		i++;
  		dataOut = (char *) realloc(dataOut,x);
	}while(count-i>0);
	for(i=0;i<x;i++){
		if(i%80==0) printf("\n");
		printf("%c",dataOut[i]);
	}

	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
	//    fputc() in <stdio.h>.
	fileOut = fopen("Result.txt","w");
	for(i=0;i<x;i++){
		fputc(dataOut[i],fileOut);
	}
	fclose(fileOut);
	free(dataOut);
	free(dataIn);
	return 0;
}
