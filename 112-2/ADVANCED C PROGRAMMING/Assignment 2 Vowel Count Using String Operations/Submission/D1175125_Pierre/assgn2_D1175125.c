#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    int vowelCount[5] = {0}; // A, E, I, O, U
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
    for (i = 0; buffer[i] != '\0'; i++) {
        switch (buffer[i]) {
            case 'A':
                vowelCount[0]++;
                break;
            case 'E':
                vowelCount[1]++;
                break;
            case 'I':
                vowelCount[2]++;
                break;
            case 'O':
                vowelCount[3]++;
                break;
            case 'U':
                vowelCount[4]++;
                break;
            default:
                break;
        }
    }
    printchar('*', 71);

    printf("\n>>>>Occurrences of vowels:\n");
    printf("  Vowel 'A': %d\n", vowelCount[0]);
    printf("  Vowel 'E': %d\n", vowelCount[1]);
    printf("  Vowel 'I': %d\n", vowelCount[2]);
    printf("  Vowel 'O': %d\n", vowelCount[3]);
    printf("  Vowel 'U': %d\n", vowelCount[4]);
    int totalVowelCount = vowelCount[0] + vowelCount[1] + vowelCount[2] + vowelCount[3] + vowelCount[4];
    printf("  ****Total vowel count: %d\n", totalVowelCount);
    printchar('*', 71);
    // Release memory
    free(buffer);
}

int main() {
    processFile();
    return 0;
}
