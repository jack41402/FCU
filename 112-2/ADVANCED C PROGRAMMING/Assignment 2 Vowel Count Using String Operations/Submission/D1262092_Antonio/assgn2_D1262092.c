#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void extendBuffer(char **buffer, int *capacity) {
    *capacity += 512;
    *buffer = (char *)realloc(*buffer, *capacity * sizeof(char));
    if (*buffer == NULL) {
        printf("Memory reallocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int capacity = 512;
    char *buffer = (char *)malloc(capacity * sizeof(char));
    FILE *inputFile, *outputFile;
    inputFile = fopen("Gift_of_Magi.txt", "r");
    // Step 2
    int length = 0;
    int vowels[] = {0, 0, 0, 0, 0};  // A, E, I, O, U
    int oneCharCount = 0, twoCharCount = 0, threeCharCount = 0, moreThanThreeCount = 0;
    int currentContiguous = 0;
    int totalCharCount = 0;
    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Convert to uppercase
            if (c >= 'a' && c <= 'z') {
                c -= ('a' - 'A');
            }
            
            // Step 6: Count contiguous letters
            if (currentContiguous > 0 && buffer[length - 1] == c) {
                currentContiguous++;
            } else {
                if (currentContiguous == 1) {
                    oneCharCount++;
                } else if (currentContiguous == 2) {
                    twoCharCount++;
                } else if (currentContiguous == 3) {
                    threeCharCount++;
                } else if (currentContiguous >= 4) {
                    moreThanThreeCount++;
                }
                
                currentContiguous = 1;  // Reset to count current character
            }
            totalCharCount++; 
            
            // Step 7: Count vowels
            if (c == 'A' || c == 'a') {
                vowels[0]++;
            } else if (c == 'E' || c == 'e') {
                vowels[1]++;
            } else if (c == 'I' || c == 'i') {
                vowels[2]++;
            } else if (c == 'O' || c == 'o') {
                vowels[3]++;
            } else if (c == 'U' || c == 'u') {
                vowels[4]++;
            }

            // Step 1 & 2: Store in buffer and extend if needed
            buffer[length++] = c;
            if (length >= capacity) {
                extendBuffer(&buffer, &capacity);
            }
        } 
}
    // Add null terminator
    buffer[length] = '\0';
    
    // Step 3: Print number of input English letters
    printf("The input English character: %d\n", length);
    printf("***********************************************************************\n\n");
    
    // Step 4: Open output file and write
    outputFile = fopen("result.txt", "w");
    fwrite(buffer, sizeof(char), length, outputFile);
    fclose(outputFile);

    // Step 5: Print first 800 characters, 80 per line
    for (int i = 0; i < 800 && buffer[i] != '\0'; ++i) {
        putchar(buffer[i]);
        if ((i + 1) % 80 == 0) {
            putchar('\n');
        }
    }
	printf("***********************************************************************\n\n");

    // Step 6: Report contiguous letters count
    if (currentContiguous == 1) {
        oneCharCount++;
    } else if (currentContiguous == 2) {
        twoCharCount++;
    } else if (currentContiguous == 3) {
        threeCharCount++;
    } else if (currentContiguous >= 4) {
        moreThanThreeCount++;
    }
    
    printf(">>>> The number of contiguous letter(s) are:\n");
    printf("  One character: %u\n", oneCharCount);
    printf("  Two contiguous characters: %u\n", twoCharCount);
    printf("  Three contiguous characters: %u\n", threeCharCount);
    printf("  Four or more contiguous characters: %u\n", moreThanThreeCount);
    printf("  **** Total characater counts: %u\n", totalCharCount); // Total letter count.

    printf("***********************************************************************\n\n");

    

    // Step 7: Report and print total vowel count
    int totalVowels = vowels[0] + vowels[1] + vowels[2] + vowels[3] + vowels[4];
	printf(">>>> The number of occurences of vowels:\n");
    printf("  Vowel 'A': %d\n", vowels[0]);
    printf("  Vowel 'E': %d\n", vowels[1]);
    printf("  Vowel 'I': %d\n", vowels[2]);
    printf("  Vowel 'O': %d\n", vowels[3]);
    printf("  Vowel 'U': %d\n", vowels[4]);
    printf("  **** Total vowel count: %u\n", totalVowels);
    printf("***********************************************************************\n\n");


    // Step 8: Free allocated memory
    free(buffer);
    fclose(inputFile);
}

