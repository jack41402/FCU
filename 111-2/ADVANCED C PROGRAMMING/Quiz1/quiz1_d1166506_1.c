#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
	FILE *fptrIn, *fptrOut; // Input and output file pointer.
	// Setp a: Let capacity be the size of a data buffer with initial value 512. 
	//         Declare a pointer to character ¡°char *buffer;¡±
	char *buffer , temp ; // Data buffer pointer.
	int capacity = 512 , count=0 ;
	int inx = 0; // Index of the input text.
	
	// ***** Declare additional necessary variables in the solution.
	int j ;
	
    // Step a: Dynamically allocate 512 characters as the initial memory space of buffer[]. 
	buffer = (char *) malloc(capacity); // Initial memory allocation for text buffer.
	
	// ***** Complete the following steps.
	 
	// Step b. Open the input text file "Gift_of_Magi.txt" and read the file using fgetc()   		 
	//         to input the file character by character until reaching the end of file.
	//    1) If the input character is an English letter, convert it to uppercase letter 
	//       and store in buffer[], starting from index 0. When the memory space of buffer[] 
	//       becomes full, extend the size of buffer 512 bytes more.
	//    2) If the input character is not an English letter, ignore it.
	fptrIn = fopen ("Gift_of_Magi.txt" , "r") ;
	// 65 A , 90 Z , 97 a , 122 z
	while (1)
	{
		if (feof(fptrIn)) break ;
		temp = fgetc(fptrIn) ;
		if (!isalpha(temp)) continue ;
		else if (islower(temp)) buffer[count] = temp-32 ;
		else buffer[count] = temp ;
//		printf ("%c" , buffer[count]) ;
		if (count==capacity-1)
		{
			buffer = (char *) realloc(buffer , capacity+512) ;
			capacity += 512 ;
		}
		count++ ;
	}
	printf(">>>> Total input English charaters: %d\n\n" , count) ;
	// Step c: Insert end-of-string ¡®\0¡¯ following the last input character. 
	//         Print the number of input English letters, i.e., the length of string.
	buffer[count] = '\0' ;
	// Step d: Open an output text file "result.txt" and write the file using fwrite(). 
	
	
	// Step e: Print the first 800 characters of the modified text on the monitor,
	//         80 characters in a line.
	fptrOut = fopen("result.txt" , "w") ;
	printf (">>>> The first 800 charaters are:\n") ;
	for (j=0 ; j<800 ; ++j)
	{
		fwrite (buffer+j , sizeof(char) , 1 , fptrOut) ;
		printf("%c" , buffer[j]) ;
		if ((j+1)%80==0) printf("\n") ;
	}
	// Step f: Count and report the number of one character letter, two contiguous
	//         character letters, three contiguous character letters, and four or
	//         more contiguous character letters.
	int one=0 , two=0 , three=0 , four=0 ;
	for (j=0 ; j<strlen(buffer) ; ++j)
	{
		if (j<strlen(buffer)-3)
		{
			if (buffer[j]==buffer[j+1] && buffer[j+1]==buffer[j+2] && buffer[j+2]==buffer[j+3])
			{
				four++ ;
				j += 3 ;
				continue ;
			}
		}
		if (j<strlen(buffer)-2)
		{
			if (buffer[j]==buffer[j+1] && buffer[j+1]==buffer[j+2])
			{
				three++ ;
				j += 2 ;
				continue ;
			}
		}
		if (j<strlen(buffer)-1)
		{
			if (buffer[j]==buffer[j+1])
			{
				two++ ;
				j += 1 ;
				continue ;
			}
		}
		one++ ;
	}
	printf ("\n>>>> The number of contiguous letter(s) are:\n") ;
	printf ("One charater: %d\n" , one) ;
	printf ("Two charater: %d\n" , two) ;
	printf ("Three charater: %d\n" , three) ;
	printf ("Four charater: %d\n" , four) ;
	printf ("Total charater count: %d\n\n" , one+two*2+three*3+four*4) ;
	// Step g: Count and report the number of each occurence of vowels,
	//         'A', 'E', 'I', 'O', and 'U'.
	int a=0 , e=0 , i=0 , o=0 , u=0 ;
	for (j=0 ; j<strlen(buffer) ; ++j)
	{
		if (buffer[j]=='A')
		{
			a++ ;
			continue ;
		}
		if (buffer[j]=='E')
		{
			e++ ;
			continue ;
		}
		if (buffer[j]=='I')
		{
			i++ ;
			continue ;
		}
		if (buffer[j]=='O')
		{
			o++ ;
			continue ;
		}
		if (buffer[j]=='U')
		{
			u++ ;
			continue ;
		}
	}
	printf ("The number of occurences of vowels:\n") ;
	printf ("Vowel 'A': %d\n" , a) ;
	printf ("Vowel 'E': %d\n" , e) ;
	printf ("Vowel 'I': %d\n" , i) ;
	printf ("Vowel 'O': %d\n" , o) ;
	printf ("Vowel 'U': %d\n" , u) ;
	printf ("Total vowel count: %d\n" , a+e+i+o+u) ;
	// Step h: Release memory space of buffer[].
  
	return 0;
}  
