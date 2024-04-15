#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    FILE *fptrIn, *fptrOut; // Input and output file pointer.
    char *buffer; // Data buffer pointer.
    int capacity = 512;
    int inx = 0; // Index of the input text.

    // Step 1: Dynamically allocate 512 characters as the initial memory space of buffer[]. 
    buffer = (char *)malloc(capacity * sizeof(char)); // Initial memory allocation for text buffer.
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Declare additional necessary variables
    int letterCount = 0;
    int oneCharCount = 0, twoCharCount = 0, threeCharCount = 0, fourOrMoreCharCount = 0;

    // Step 2: Open the input text file "Gift_of_Magi.txt" and read the file using fgetc() 
    //         to input the file character by character until reaching the end of file.
    fptrIn = fopen("Gift_of_Magi.txt", "r");
    if (fptrIn == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }

    int c;
    while ((c = fgetc(fptrIn)) != EOF) {
        if (isalpha(c)) {
            // Step 1: Convert to uppercase
            c = toupper(c);
            // Step 1: Store in buffer, expanding if needed
            if (inx >= capacity - 1) {
                capacity += 512;
                buffer = (char *)realloc(buffer, capacity * sizeof(char));
                if (buffer == NULL) {
                    printf("Memory reallocation failed!\n");
                    return 1;
                }
            }
            buffer[inx++] = c;
            letterCount++;
        }
    }
    // Step 3: Insert end-of-string '\0' following the last input character. 
    buffer[inx] = '\0';
    printf(">>>> Total input English characters: %d.\n", letterCount);
    printf("***********************************************************************\n\n");

    // Step 4: Open an output text file "result.txt" and write the file using fwrite(). 
    fptrOut = fopen("result.txt", "w");
    if (fptrOut == NULL) {
        printf("Error opening output file!\n");
        return 1;
    }
    fwrite(buffer, sizeof(char), strlen(buffer), fptrOut);
    fclose(fptrOut);

    // Step 5: Print the first 800 characters of the modified text on the monitor,
    //         80 characters in a line.
    printf(">>>> The first 800 characters are:\n  ");
    int i;
    for (i = 0; i < 800 && buffer[i] != '\0'; i++) {
        putchar(buffer[i]);
        if ((i + 1) % 80 == 0) {
            putchar('\n');
            printf("  ");
        }
    }
    putchar('\n');
    printf("***********************************************************************\n\n");

    // Step 6: Count contiguous character counts
    printf(">>>> The number of contiguous letter (s) are:\n");
    for (i = 0; i < letterCount; i++) {
        if (buffer[i] == buffer[i + 1]) {
            if (buffer[i] == buffer[i + 2]) {
                if (buffer[i] == buffer[i + 3]) {
                    fourOrMoreCharCount++;
                } else {
                    threeCharCount++;
                }
                i += 2;
            } else {
                twoCharCount++;
                i++;
            }
        } else {
            oneCharCount++;
        }
    }
    printf("  One character: %d\n", oneCharCount);
    printf("  Two contiguous characters: %d\n", twoCharCount);
    printf("  Three contiguous characters: %d\n", threeCharCount);
    printf("  Four or more contiguous characters: %d\n", fourOrMoreCharCount);
    printf("  **** Total characater counts: %d\n", letterCount);
    printf("***********************************************************************\n\n");

    // Step 7: Count and report the number of each occurrence of vowels,
    //         'A', 'E', 'I', 'O', and 'U'.
    printf(">>>> The number of occurences of vowels:\n");
    const char *vowels = "AEIOU";
    int totalVowelCount = 0; // Total count of all vowels
    for (i = 0; i < strlen(vowels); i++) {
        char *ptr = buffer;
        int vowelCount = 0;
        while ((ptr = strchr(ptr, vowels[i])) != NULL) {
            vowelCount++;
            ptr++;
        }
        printf("  Vowel '%c': %d\n", vowels[i], vowelCount);
        totalVowelCount += vowelCount; // Add the count of current vowel to total count
    }
    printf("  **** Total vowel count: %d\n", totalVowelCount);
    printf("***********************************************************************\n");

    // Step 8: Release memory space of buffer[].
    free(buffer);
    fclose(fptrIn);

    return 0;
}
