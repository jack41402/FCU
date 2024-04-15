#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INITIAL_BUFFER_SIZE 512

// Function to check if a character is a vowel
int is_vowel(char ch) {
    static const char vowels[] = "AEIOU";
    int i;
    for (i = 0; vowels[i] != '\0'; ++i) {
        if (ch == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to write data to a file
void write_to_file(const char *filename, const char *data, size_t size) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        perror("Error opening file to write");
        exit(EXIT_FAILURE);
    }
    fwrite(data, sizeof(char), size, f);
    fclose(f);
}
void print_first_800_characters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return; // Exit the function if file can't be opened
    }
    
    int c;
    int char_count = 0;
    while ((c = fgetc(file)) != EOF && char_count < 800) {
        putchar(c);
        char_count++;
        if (char_count % 80 == 0) { // After every 80 characters, print a newline
            putchar('\n');
        }
    }
    if (char_count % 80 != 0) { // Print a newline if the last line wasn't exactly 80 characters long
        putchar('\n');
    }
    fclose(file);
}
// Function to count vowels and total letters
void count_letters(const char *text, size_t size, int *total_letters, int vowel_counts[5]) {
    size_t i;
    char c;

    for (i = 0; i < size; ++i) {
        c = text[i];
        if (is_vowel(c)) {
            switch (c) {
                case 'A': ++vowel_counts[0]; break;
                case 'E': ++vowel_counts[1]; break;
                case 'I': ++vowel_counts[2]; break;
                case 'O': ++vowel_counts[3]; break;
                case 'U': ++vowel_counts[4]; break;
            }
        }
        ++(*total_letters);
    }
}

// Function to count contiguous characters
void count_contiguous_characters(const char *text, size_t length, int *single_count, int *double_count, int *triple_count, int *four_or_more_count) {
    int current_streak = 1;
	size_t i;
    // Start from second character to compare with the previous one
    for (i = 1; i < length; ++i) {
        if (text[i] == text[i - 1]) {
            ++current_streak;
        } else {
            switch (current_streak) {
                case 1: ++(*single_count); break;
                case 2: ++(*double_count); break;
                case 3: ++(*triple_count); break;
                default: ++(*four_or_more_count); break;
            }
            current_streak = 1;
        }
    }

    // Handle the last streak in the text
    switch (current_streak) {
        case 1: ++(*single_count); break;
        case 2: ++(*double_count); break;
        case 3: ++(*triple_count); break;
        default: ++(*four_or_more_count); break;
    }
}

int main() {
    char *buffer = (char *)malloc(INITIAL_BUFFER_SIZE);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    size_t capacity = INITIAL_BUFFER_SIZE;
    size_t size = 0;
    int c;

    // Open the input file
    FILE *file = fopen("Gift_of_Magi.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        free(buffer);
        return 1;
    }

    // Read characters from the file
    while ((c = fgetc(file)) != EOF) {
        if (size >= capacity - 1) {
            capacity *= 2;
            char *temp = (char *)realloc(buffer, capacity);
            if (temp == NULL) {
                fprintf(stderr, "Memory reallocation failed.\n");
                free(buffer);
                fclose(file);
                return 1;
            }
            buffer = temp;
        }

        if (isalpha(c)) { // If c is an English letter
            buffer[size++] = toupper(c); // Convert to uppercase and store in the buffer
        }
    }
    buffer[size] = '\0'; // Null-terminate the buffer

    // Close the input file
    fclose(file);

    // Write to "result.txt"
    write_to_file("result.txt", buffer, size);

    // Count vowels and letters
    int total_letters = 0;
    int vowel_counts[5] = {0}; // For 'A', 'E', 'I', 'O', 'U'
    count_letters(buffer, size, &total_letters, vowel_counts);

    // Count contiguous characters
    int single_count = 0, double_count = 0, triple_count = 0, four_or_more_count = 0;
    count_contiguous_characters(buffer, size, &single_count, &double_count, &triple_count, &four_or_more_count);
    int total_vowels = 0;
    int i;
    for(i = 0; i < 5; i++){
    	total_vowels += vowel_counts[i];
	}
	printf(">>>> Toal input English characters: %d\n", total_letters);
	printf("**************************************************\n");
	print_first_800_characters("Gift_of_Magi.txt");

    // Print the results for contiguous characters
    printf("**************************************************");
    printf("\n>>>>> The number of contiguous letter(s) are:\n");
    printf("One character: %d\n", single_count);
    printf("Two contiguous characters: %d\n", double_count);
    printf("Three contiguous characters: %d\n", triple_count);
    printf("Four or more contiguous characters: %d\n", four_or_more_count);
    printf("**** Total character counts: %d\n", total_letters);
	printf("**************************************************\n");
    // Print the results for vowels
    printf(">>>>> The number of occurences of vowels: \n");
    printf("Vowel 'A': %d\n", vowel_counts[0]);
    printf("Vowel 'E': %d\n", vowel_counts[1]);
    printf("Vowel 'I': %d\n", vowel_counts[2]);
    printf("Vowel 'O': %d\n", vowel_counts[3]);
    printf("Vowel 'u': %d\n", vowel_counts[4]);
    printf("Total vowels: %d\n", total_vowels);

    // Free the allocated memory
    free(buffer);

    return 0; // Indicate successful completion
}


