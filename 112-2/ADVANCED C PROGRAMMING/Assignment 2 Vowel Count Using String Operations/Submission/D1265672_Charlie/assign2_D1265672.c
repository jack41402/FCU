#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i, j ,k;
    int capacity = 512;
    int countEnglishLetters = 0;
    int bufferSize = 0;
    char ch;
    int oneCharCount = 0, twoCharCount = 0, threeCharCount = 0, moreCharCount = 0;
    int vowelCount[5] = {0}; 
    char vowels[6] = {'A', 'E', 'I', 'O', 'U', '\0'};
    int totalVowelCount = 0;
    
    // create space
    char *buffer = (char *)malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
	
	//open file
    FILE *inputFile = fopen("Gift_of_Magi.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
	
	// read file only save alpabet into array
    while ((ch = fgetc(inputFile)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (bufferSize >= capacity) {
                capacity += 512;
                buffer = (char *)realloc(buffer, capacity * sizeof(char));
                if (buffer == NULL) {
                    printf("Memory reallocation failed.\n");
                    fclose(inputFile);
                    return 1;
                }
            }
            buffer[bufferSize] = (ch >= 'a' && ch <= 'z') ? (ch - 32) : ch;
            bufferSize++;
            countEnglishLetters++;
        } else if (ch == '\n' || ch == ' ' || ch == '\t') {
            continue;
        }
        
    }
    fclose(inputFile);
	
    buffer[bufferSize] = '\0';
	
	// output alphabet to result.txt
    FILE *outputFile = fopen("result.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        free(buffer);
        return 1;
    }
    fwrite(buffer, sizeof(char), strlen(buffer), outputFile);
    fclose(outputFile);
	
	// output first 800 word
    printf(">>>> Total input English characters: %d.\n", countEnglishLetters);
	printf("******************************************************************\n\n");
    printf(">>>> The first 800 characters are:\n");
    printf("  ");
    for (i = 0; i < 800; i++) {
        printf("%c", buffer[i]);
        if ((i + 1) % 80 == 0) {
            printf("\n");
            printf("  ");
        }
    }
    printf("\n");
	printf("******************************************************************\n\n");
	
	// count consecutive number
	countEnglishLetters = 0;
    for (i = 0; i < strlen(buffer); i++) {
    	countEnglishLetters++;
        

        int consecutiveLetters = 1;
        for (j = i + 1; buffer[j] == buffer[i]; j++, consecutiveLetters++) {
        	countEnglishLetters++;
            if (consecutiveLetters == 4) {
                moreCharCount++;
                consecutiveLetters = 0;
                break;
            }
        }
		if (consecutiveLetters == 1){
			oneCharCount++;
		}
		if(consecutiveLetters == 2){
			i++;
			twoCharCount++;
		}
		if(consecutiveLetters == 3){
			i+=2;
			threeCharCount++;
		}
    }
	printf(">>>> The number of contiguous letter(s) are:\n");
    printf("  One character: %d\n", oneCharCount);
    printf("  Two contiguous characters: %d\n", twoCharCount);
    printf("  Three contiguous characters: %d\n", threeCharCount);
    printf("  Four or more contiguous characters: %d\n", moreCharCount);
    printf("  **** Total character counts: %d\n", countEnglishLetters);
	printf("******************************************************************\n\n");
	
	// count vowel
	for (i = 0; i < strlen(buffer); i++){
		for (k = 0; k < 5; k++) {
            if (buffer[i] == vowels[k]) {
                vowelCount[k]++;
            }
        }
	}
    printf(">>>> The number of occurrences of vowels:\n");
    for (i = 0; i < 5; i++) {
        printf("  Vowel '%c': %d\n", vowels[i], vowelCount[i]);
        totalVowelCount += vowelCount[i];
    }
    printf("  **** Total vowel count: %d\n", totalVowelCount);
	printf("******************************************************************");

    free(buffer);

    return 0;
}
