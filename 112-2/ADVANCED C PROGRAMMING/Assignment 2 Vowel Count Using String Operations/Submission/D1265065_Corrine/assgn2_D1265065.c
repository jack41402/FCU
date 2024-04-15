//
//  main.c
//  assgn_D1265065
//
//  Created by Corrine  on 2024/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    FILE *fileIn, *fileOut; // Input and Ouput file pointer
    char *buffer; // Data buffer pointer
    char *char_ptr; // char pointers
    char one_char[2]; // one character string
    char vowels[] = "AEIOU"; // vowels
    int index = 0; // Index of input text
    int capacity = 512; // capacity of buffer
    int i; // loop variable
    int total_count; // total characters
    int length; // length of letters
    unsigned int char_count[4] = {0, 0, 0, 0}; // Number of contiguous letters
    unsigned int vowel_count[5] = {0, 0, 0, 0, 0}; // Number of vowels count
    buffer = (char *) malloc(capacity); //allocate 512 characters as initial memory space of buffer
    fileIn = fopen("Gift_of_Magi.txt","r"); // Open the input
    while (!feof(fileIn)) { // if fileIn is not end of file, execute the follwing program.
        buffer[index] = fgetc(fileIn); // insert the file into buffer.
        if (isalpha(buffer[index])) { // if the first letter of content is alphabet
            buffer[index] = toupper(buffer[index]); // Make every letter convert into upper case
            index++; // index = index + 1
            if(index==capacity) { // if index equals capacity, which means the memory of buffer isn't enough.
                capacity += 512; // capacity = capacity + 512
                buffer = (char *) realloc( buffer, capacity); //expand the memory of buffer.
            }
        }
    }
    buffer[index] = '\0'; // insert the end of string
    fclose(fileIn); // close the file
    printf(">>>> Total input English characters: %d.\n", index);
    printf("***********************************************************************\n\n"); // printout the total of English character
    fileOut = fopen("result.txt","w"); //Open an output text file “result.txt”
    fwrite(buffer, sizeof(char), index, fileOut);// write the file using fwrite()
    fclose(fileOut); // close the file
    // Print the first 800 characters of the input text on the console, 80 characters in a line.
    printf(">>>> The first 800 characters are:\n  ");
    for (i=0; i<800; i++) { // 800 characters in a line.
        if ((i+1)%80==0)  printf("%c\n  ", buffer[i]); // If it is not a full line, print the character only.
        else printf("%c", buffer[i]); // If it is a full line, print the character and a new line.
    }
    printf("\n");
    printf("***********************************************************************\n\n");
    // Count and report the number of one character letter, two contiguous character letters, three contiguous character letters, and four or more contiguous character letters
    char_ptr = buffer;
    one_char[1] = '\0';
    total_count = 0;
    while (char_ptr[0] != '\0') {
        one_char[0] = char_ptr[0];
        length = strspn(char_ptr, one_char);
        total_count = total_count + length;
        char_ptr = char_ptr + length;
        //length = length < 4 ? length : 4;
        if (length < 4) length = length;
        else length = 4;
        char_count[length-1] = char_count[length-1] + 1;
    }
    printf(">>>> The number of contiguous letter(s) are:\n");
    printf("  One character: %u\n", char_count[0]);
    printf("  Two contiguous characters: %u\n", char_count[1]);
    printf("  Three contiguous characters: %u\n", char_count[2]);
    printf("  Four or more contiguous characters: %u\n", char_count[3]);
    printf("  **** Total characater counts: %u\n", total_count);
    printf("***********************************************************************\n\n");
    // Count and report the number of each occurrence of vowels, 'A', 'E', 'I', 'O', and 'U'. Print the total vowel count.
    char_ptr = (char *) strpbrk(buffer, vowels);
    total_count = 0;
    while (char_ptr!=NULL) {
        switch (*char_ptr) {
            case 'A': {++vowel_count[0]; break;}
            case 'E': {++vowel_count[1]; break;}
            case 'I': {++vowel_count[2]; break;}
            case 'O': {++vowel_count[3]; break;}
            case 'U': {++vowel_count[4]; break;}
        }
        char_ptr = (char *) strpbrk(char_ptr+1, vowels);
        total_count++;
    }
    printf(">>>> The number of occurences of vowels:\n");
    for (i=0; i<5; i++)
        printf("  Vowel \'%c\': %u\n", vowels[i], vowel_count[i]);
    printf("  **** Total vowel count: %u\n", total_count);
    printf("***********************************************************************\n\n");
    // Release memory space of buffer[].
    free(buffer);
    return 0;
        }
