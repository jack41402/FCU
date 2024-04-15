#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{
    char *buffer; //declare a character pointer for buffer
    int capacity = 512; //initialize capacity for buffer
    FILE *inputFile, *outputFile; //declare file pointers for input and output
    int character, lettersCount = 0;  //declare variables for characters and letter counts
    int vowelCounts[5] = {0}; //array to store counts for vowels 'A', 'E', 'I', 'O', 'U'
    int i; //declare i for loop variable
    int OneCharacterCount = 0, TwoCharactersCount = 0, ThreeCharactersCount = 0, FourOrMoreCharactersCount = 0; //declare for contiguous count
    
    //Dynamically allocate memory for buffer
    buffer = (char *)malloc(capacity * sizeof(char)); //allocate memory for buffer dynamic
    if (buffer == NULL) 
	{
        return 1; //return 1 indicate failure
    }
    
    //Open input file and read content
    inputFile = fopen("Gift_of_Magi.txt", "r"); //open input file
    if (inputFile == NULL) 
	{
        free(buffer); //free allocated file
        return 1; //return 1 indicate failure
    }
    
    while ((character = fgetc(inputFile)) != EOF) //reading characters until end of file
	{
        // Convert to uppercase and store in buffer if it's an English letter
        // Extend buffer size if needed
        // Remember to ignore non-English letters
        if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) 
		{
            if (lettersCount == capacity) //check if buffer is full
			{
                capacity += 512; //extending buffer size.
                buffer = realloc(buffer, capacity * sizeof(char)); //reallocate memory for buffer
                if (buffer == NULL)
				{
                    fclose(inputFile); //close input file
                    free(buffer); //free allocated memory
                    return 1; //return 1 indicate failure
                }
            }
            if(character >= 'a' && character <= 'z') //check if character is lowercase
			{
                buffer[lettersCount++] = character - 'a' + 'A'; //convert to uppercase
            } 
			else //if character is uppercase.
			{
                buffer[lettersCount++] = character; //storing in buffer
            }
        }
    }
    
    //Insert end-of-string '\0' and print the length of string
    if (lettersCount == capacity) //checking if buffer is full.
	{
        capacity++; //increase the capacity
        buffer = realloc(buffer, capacity * sizeof(char)); //reallocate memory for buffer
        if (buffer == NULL) 
		{
            fclose(inputFile); //closing input file.
            free(buffer); //freeing allocated memory
            return 1; //return 1 indicate failure
        }
    }
    buffer[lettersCount] = '\0'; //adding end-of-string character
    printf(">>>> Total input English characters: %d.\n", lettersCount); //printing total English characters
    
    fclose(inputFile); //close the input file
    printf("***********************************************************************\n\n");
    
    //Open output file and write the buffer content
    outputFile = fopen("result.txt", "w"); //opening output file
    if (outputFile == NULL) 
	{
        free(buffer); //freeing allocated memory.
        return 1; //return 1 indicate failure
    }
    fwrite(buffer, sizeof(char), strlen(buffer), outputFile); //write buffer content to output file
    fclose(outputFile); //close the output file.
    
    //Print the first 800 characters of the input text
    printf(">>>> The first 800 characters are:\n  ");
    for (i = 0; i < 800 && buffer[i] != '\0'; i++) 
	{
        printf("%c", buffer[i]); //print character.
        if ((i + 1) % 80 == 0) printf("\n  ");  //print newline after every 80 characters
    }
    printf("\n");
    printf("***********************************************************************\n\n");
    
    //Count contiguous letters
    for (i = 0; buffer[i] != '\0'; i++) 
	{
        int j = i; //initialize j as i
        
        //Count contiguous characters
        while (buffer[j] == buffer[i] && buffer[j] != '\0') //loop through contiguous characters
		{
            j++; //Move to next character
        }
        int length = j - i; //calculate length of contiguous characters
        if (length == 1) OneCharacterCount++; //count one contiguous character
        else if (length == 2) TwoCharactersCount++; //count two contiguous characters
        else if (length == 3) ThreeCharactersCount++; //count three contiguous characters
        else if (length >= 4) FourOrMoreCharactersCount++; //count four or more contiguous characters
        i = j - 1; //move i to the next character after the contiguous characters
    }
    
    printf(">>>> Contiguous character counts:\n"); 
    printf("  One character: %d\n", OneCharacterCount); //print count of one contiguous character
    printf("  Two contiguous characters: %d\n", TwoCharactersCount); //print count of two contiguous characters
    printf("  Three contiguous characters: %d\n", ThreeCharactersCount); //print count of three contiguous characters
    printf("  Four or more contiguous characters: %d\n", FourOrMoreCharactersCount); //print count of four or more contiguous characters
    printf("  **** Total character counts: %d\n", lettersCount); //print count of total characters
    
    printf("***********************************************************************\n\n");
    
    //Count vowels and print the total vowel count
    for (i = 0; buffer[i] != '\0'; i++) 
	{
        if (buffer[i] == 'A' || buffer[i] == 'a') vowelCounts[0]++; //counting 'A' or 'a'
        else if (buffer[i] == 'E' || buffer[i] == 'e') vowelCounts[1]++; //counting 'E' or 'e'
        else if (buffer[i] == 'I' || buffer[i] == 'i') vowelCounts[2]++; //counting 'I' or 'i'
        else if (buffer[i] == 'O' || buffer[i] == 'o') vowelCounts[3]++; //counting 'O' or 'o'
        else if (buffer[i] == 'U' || buffer[i] == 'u') vowelCounts[4]++; //counting 'U' or 'u'
    }
    //calculating total vowel count
    int totalVowels = vowelCounts[0] + vowelCounts[1] + vowelCounts[2] + vowelCounts[3] + vowelCounts[4]; 
    printf(">>>> The number of occurrences of vowels:\n");
    printf("  Vowel 'A': %d\n", vowelCounts[0]); //print count of vowel 'A'
    printf("  Vowel 'E': %d\n", vowelCounts[1]); //print count of vowel 'E'
    printf("  Vowel 'I': %d\n", vowelCounts[2]); //print count of vowel 'I'
    printf("  Vowel 'O': %d\n", vowelCounts[3]); //print count of vowel 'O'
    printf("  Vowel 'U': %d\n", vowelCounts[4]); //print count of vowel 'U'
    printf("  **** Total vowel count: %d\n", totalVowels); //print total vowel count
    printf("***********************************************************************\n\n");
    
    //Closing files and freeing allocated memory
    free(buffer); //free allocated memory
    
    return 0; //return 0 indicate success
}

