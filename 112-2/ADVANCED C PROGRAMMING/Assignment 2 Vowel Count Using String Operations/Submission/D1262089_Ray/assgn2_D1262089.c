#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_INITIAL_SIZE 512
#define BUFFER_SIZE_INCREMENT 512
#define INPUT_FILE_NAME "Gift_of_Magi.txt"
#define OUTPUT_FILE_NAME "result.txt"

void resizeBuffer(char **buffer, size_t *capacity, size_t newSize) {
    *buffer = realloc(*buffer, newSize);
    if (*buffer == NULL) {
        printf("Memory allocation failed.\n");
        return; // return without performing any further actions
    }
    *capacity = newSize;
}

int main() {
    // Step 1
    size_t capacity = BUFFER_INITIAL_SIZE;
    char *buffer = (char *)malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // return an error code
    }
    size_t length = 0;

    // Step 2
    FILE *inputFile = fopen(INPUT_FILE_NAME, "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        free(buffer);
        return 1; // return an error code
    }

    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            // Convert to uppercase and store in buffer
            if (length + 1 >= capacity) {
                resizeBuffer(&buffer, &capacity, capacity + BUFFER_SIZE_INCREMENT);
            }
            buffer[length++] = (char)toupper(c);
        }
    }
    fclose(inputFile);

    // Step 3
    buffer[length] = '\0';
    printf(">>>> Total input English characters: %zu.\n", length);

    // Step 4
    FILE *outputFile = fopen(OUTPUT_FILE_NAME, "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        free(buffer);
        return 1; // return an error code
    }
    fwrite(buffer, sizeof(char), length, outputFile);
    fclose(outputFile);

    // Step 5
    printf("*********************************************************************\n\n");
    printf(">>>> The first 800 characters are:\n");
    size_t i;
    for (i = 0; i < 800 && buffer[i] != '\0'; ++i) {
        putchar(buffer[i]);
        if ((i + 1) % 80 == 0) {
            putchar('\n');
        }
    }
    printf("\n*********************************************************************\n");

    // Step 6
    printf("\n>>>> The number of contiguous letter(s) are:\n");
    size_t oneCharCount = 0, twoCharCount = 0, threeCharCount = 0, fourOrMoreCharCount = 0 ,contiguousCharCount = 0;
    for (i = 0; i < length; ++i) {
        if (buffer[i] != buffer[i + 1]) {
            if (contiguousCharCount == 0) {
                oneCharCount++;
            } else if (contiguousCharCount == 1) {
                twoCharCount++;
            } else if (contiguousCharCount == 2) {
                threeCharCount++;
            } else if (contiguousCharCount == 3) {
                fourOrMoreCharCount++;
            }
            contiguousCharCount = 0;
        } else {
            contiguousCharCount++;
        }
    }
    printf("  One character: %zu\n", oneCharCount);
    printf("  Two contiguous characters: %zu\n", twoCharCount);
    printf("  Three contiguous characters: %zu\n", threeCharCount);
    printf("  Four or more contiguous characters: %zu\n", fourOrMoreCharCount);
    printf("  **** Total characater counts:%zu\n", length);
    printf("*********************************************************************\n");

    // Step 7
    printf("\n>>>> The number of occurences of vowels:\n");
    int vowels[5] = {0}; // A, E, I, O, U
    const char *vowelList = "AEIOU";
    int j=0;
    for (i = 0; i < length; ++i) {
        for (j = 0; j < 5; ++j) {
            if (buffer[i] == vowelList[j]) {
                vowels[j]++;
            }
        }
    }
    size_t totalVowelCount = 0;
    for (i = 0; i < 5; ++i) {
        printf("  Vowel '%c': %d\n", vowelList[i], vowels[i]);
        totalVowelCount += vowels[i];
    }
    printf("  **** Total vowel count: %zu\n", totalVowelCount);
    printf("*********************************************************************\n");

    // Step 8
    free(buffer);

    return 0; // return success code
}
