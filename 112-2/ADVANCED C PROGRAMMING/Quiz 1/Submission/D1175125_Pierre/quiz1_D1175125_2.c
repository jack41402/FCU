#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
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
	
	// ***** Complete the following steps. 
  
	// 2. Use file FCU.txt as the input testing file.
FILE *input_file = fopen("FCU.txt","r");
if(input_file == NULL){
	fprintf(stderr,"Error opening input file\n");
	return 1;
}
	// 3. Dynamically allocate memory space for dataIn[] to hold the text data of FCU.txt.
  dataIn = NULL;
  size_t dataIn_size = 0;
  int c;
  while((c=fgetc(input_file))!=EOF){
  	dataIn = realloc(dataIn,(dataIn_size +1)*sizeof(char));
  	if(dataIn == NULL){
  		fprintf(stderr,"Memory allocation failed\n");
  		fclose(input_file);
  		return 1;
	  }
	  dataIn[dataIn_size++]=(char)c;
  }
  dataIn[dataIn_size]='\0';
  fclose(input_file);
  printf("dataIn: \n%s\n",dataIn); 
	// 4. Read the data string dataIn from file FCU.txt character by character using 
	//    function fgetc() in <stdio.h> until end of file. Print string dataIn.
	
	// 5. Remove all non-alphanumerical characters from string dataIn using functions strpbrk(), 
	//    strspn(), and strncpy() in <string.h>. Print string dataIn with alphanumerical characters
	//    only 80 characters in a line.
//	void remove_non_alphanumeric(char *str ){
//		char *src = str;
//		char *dst = str;
//		while(*src){
//			if(isalmun((unsigned char)*src)){
//				*dst++ = * src;
//			}
//			src++;
//		}
//		*dst='\0';
//	} 
//	remove_non_alphanumeric(dataIn);
//	for(i=0;i<strlen(dataIn); i += MAX_LINE_LENGTH){
//		printf("%.80s\n",dataIn+i);
//	}
//	// 6. Dynamically allocate memory space for dataOut[] such that string dataOut is the result of 
//	//    concatenating dataIn, ¡°#####¡±, and the reversal string of dataIn. Print string dataOut 
//	//    80 characters in a line.
//	char *reverse_string(const char *str){
//		size_t len= strlen(str);
//		char *reversed = malloc((len+1)*sizeof(char));
//		if(reversed==NULL){
//			fprintf(stderr,"Memory allocation failed\n");
//			exit(EXIT_FAILURE);
//		}
//		for(i = 0;i<len;i++){
//			reversed[i]=str[len-i+1]; 
//		}
//		reversed[len]='\0';
//		return reversed;
//	}
//	char *reversed = *reverse_string(dataIn);
//	*dataOut = malloc((strlen(dataIn)+strlen(reversed)+6)*sizeof(char));
//	if(dataOut == NULL){
//		fprintf(stderr, "Memory alloztion failed\n");
//		free(dataIn);
//		free(reversed);
//		return 1;
//	}
//	sprintf(dataOut,"%s#####%s",dataIn,reversed);
//	free(reversed);
//	for(i = 0; i<strlen(dataOut);i+=MAX_LINE_LENGTH){
//		printf("%.80s\n",dataOut + i);
//	}
//	// 7. Write the data string dataOut to file ¡°Result.txt¡± character by character using function 
//	//    fputc() in <stdio.h>.
//	FILE *output_file = fopen("Result.txt","w");
//	if(output_file==NULL){
//		fprintf(stderr,"Error opening output file\n");
//		free(dataIn);
//		free(dataOut);
//		return 1;
//	}
//	for(i = 0; i<strlen(dataOut);i++){
//		fputc(dataOut[i],output_file);
//	}
//	fclose(output_file);
//	free(dataIn);
//	free(dataOut);
//	printf("Data written to Result.txt \n");
//	
	return 0;
}
