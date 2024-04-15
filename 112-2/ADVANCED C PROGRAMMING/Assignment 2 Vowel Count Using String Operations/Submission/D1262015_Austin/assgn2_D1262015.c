#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h> 
#define INITIAL_CAPACITY 512
#define EXTEND_SIZE 512
#define FILENAME "Gift_of_Magi.txt"
#define OUTPUT_FILENAME "result.txt"

// Function to read input text file, process data, and write output
void printchar(char c, int count) {
    int i; 
    for (i = 0; i < count; i++) {
        printf("%c", c);
    }
    printf("\n");
}


void processFile() {
    FILE *inputFile, *outputFile;
    char *buffer = (char *)malloc(INITIAL_CAPACITY * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    int capacity = INITIAL_CAPACITY;
    int size = 0;
    int letterCount = 0;
    int oneLetterCount = 0, twoLetterCount = 0, threeLetterCount = 0, moreLetterCount = 0;
    int A_Count = 0 ;
    int E_Count = 0 ;
    int I_Count = 0 ;
    int O_Count = 0 ;
    int U_Count = 0 ;// A, E, I, O, U
    int i;
    int count; 
    // Add semicolon here
    // Open input file
    inputFile = fopen(FILENAME, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read characters from input file
    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (isalpha(c)) { // If character is an English letter
            c = toupper(c); // Convert to uppercase
            buffer[size++] = c;
            letterCount++;

            // Check for contiguous letter counts
            if (size >= 4 && buffer[size - 4] == buffer[size - 3] && buffer[size - 3] == buffer[size - 2] && buffer[size - 2] == buffer[size - 1]) {
                moreLetterCount++;
            } else if (size >= 3 && buffer[size - 3] == buffer[size - 2] && buffer[size - 2] == buffer[size - 1])  {
                threeLetterCount++;
            } else if (size >= 2 && buffer[size - 2] == buffer[size - 1]) {
                twoLetterCount++;
            } else if (size >= 1) {
                oneLetterCount++;
            }

            // Extend buffer if needed
            if (size >= capacity) {
                capacity += EXTEND_SIZE;
                buffer = (char *)realloc(buffer, capacity * sizeof(char));
                if (buffer == NULL) {
                    printf("Memory reallocation failed.\n");
                    exit(1);
                }
            }
        } else if (c == '\n') {
            // Newline character - for printing 80 characters per line
            buffer[size++] = c;
        }
        // Ignore non-English letters
    }
    oneLetterCount -= (twoLetterCount+threeLetterCount*2+moreLetterCount*3);

    // Add null terminator
    buffer[size] = '\0';

    // Close input file
    fclose(inputFile);

    // Open output file
    outputFile = fopen(OUTPUT_FILENAME, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write buffer to output file
    fwrite(buffer, sizeof(char), size, outputFile);

    // Close output file
    fclose(outputFile);

    // Print first 800 non-space characters (80 characters per line)
    printf(">>>>Total input English letters: %d\n", letterCount);
    printchar('*', 71);
    printf("\n>>>>First 800 characters are:\n  ");
    for (i = 0, count = 0; count < 800 && buffer[i] != '\0'; i++) {
    if (!isspace(buffer[i])) { // Check if character is not a space
        putchar(buffer[i]);
        count++;
        if (count % 80 == 0) // Output newline every 80 characters
            
		printf("\n  ");
            
        }
     }


    // Print counts
    printf("\n");
    printchar('*', 71);
    printf("\n>>>>The number of contiguous letter(s) are :\n");
    
    printf("  One character: %d\n", oneLetterCount);
    printf("  Owo contiguous characters: %d\n", twoLetterCount);
    printf("  Ohree contiguous characters: %d\n", threeLetterCount);
    printf("  Four or more contiguous characters: %d\n", moreLetterCount);
    printf("  ****Total character count: %d\n", letterCount);
    // Count and report vowels
    int total_vowel_count=0;
    char vowel[]="AEIOU";
    for(i=0;vowel[i]!='\0';i++){
        char *ptr=buffer;
        if(i==0) ptr=strpbrk(ptr, "A");
        else if(i==1) ptr=strpbrk(ptr, "E");
        else if(i==2) ptr=strpbrk(ptr, "I");
        else if(i==3) ptr=strpbrk(ptr, "O");
        else if(i==4) ptr=strpbrk(ptr, "U");
        while(ptr!=NULL){
            total_vowel_count++;
            if(i==0) { A_Count++; ptr=strpbrk(ptr+1, "A"); }
            else if(i==1) { E_Count++; ptr=strpbrk(ptr+1, "E"); }
            else if(i==2) { I_Count++; ptr=strpbrk(ptr+1, "I"); }
            else if(i==3) { O_Count++; ptr=strpbrk(ptr+1, "O"); }
            else if(i==4) { U_Count++; ptr=strpbrk(ptr+1, "U"); }
        }
    }
    printchar('*', 71);

    printf("\n>>>>Occurrences of vowels:\n");
    printf("  Vowel 'A': %d\n", A_Count);
    printf("  Vowel 'E': %d\n", E_Count);
    printf("  Vowel 'I': %d\n", I_Count);
    printf("  Vowel 'O': %d\n", O_Count);
    printf("  Vowel 'U': %d\n", U_Count);
    printf("  ****Total vowel count: %d\n", total_vowel_count);
    printchar('*', 71); 
    // Release memory
    free(buffer);
}

int main() {
    processFile();
    return 0;
}

