//﻿#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>  
#include <stdlib.h>

int buffer_size = 512;
char* buffer;
int bn = 0;

void enlarge()
{
    int new_buffer_size = buffer_size + 512;
    char * new_buffer = (char*)malloc(sizeof(char) * new_buffer_size);
    for (int i = 0; i < buffer_size; i++)
    {
        new_buffer[i] = buffer[i];
    }
    free(buffer);
    buffer = new_buffer;
    buffer_size = new_buffer_size;
}

int cont[105] = { 0 };

int vowels[300] = { 0 };

int continues(int index)
{
    if (index - 1 >= 0 && buffer[index - 1] == buffer[index])
        return 0;
    int cnt = 0;
    for (int i = 0; i < bn; i++)
    {
        if (index + i >= bn)
            break;
        if (buffer[index + i] == buffer[index])
            cnt++;
        else
            break;
    }
    return cnt;
}

int main() {

    buffer = (char*)malloc(sizeof(char) * buffer_size);

    FILE* file = fopen("Gift_of_Magi.txt", "r");

    char ch;
    while ((ch = fgetc(file)) != EOF) {

        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - 'a' + 'A';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {

        }
        else
        {
            continue;
        }
        if (bn >= buffer_size)
        {
            enlarge();
        }
        buffer[bn++] = ch;
    }
    buffer[bn] = '\0';

    fclose(file);

    FILE* out = fopen("result.txt", "w");
    fwrite(buffer, sizeof(char), bn, out);
    fclose(out);

    printf(">>> Total input English characters: %d.\n", bn);
    printf("*******************************************************************\n\n");

    printf(">>> The first 800 characters are:");
    for (int i = 0; i < 800; i++)
    {
        if (i % 80 == 0)
        {
            printf("\n  ");
        }
        printf("%c", buffer[i]);
    }
    printf("\n\n*******************************************************************\n\n");

    for (int i = 0; i < bn; i++)
    {
        int cnt = continues(i);
        if (cnt >= 4)
            cnt = 4;
        cont[cnt] += 1;
    }
    printf(">>>> The number of continues letter(s) are:\n");
    printf("  One character: %d\n", cont[1]);
    printf("  Two continueous character: %d\n", cont[2]);
    printf("  Three continueous character: %d\n", cont[3]);
    printf("  Four or more continueous character: %d\n", cont[4]);

    int total = 0;
    for (int i = 0; i < 5; i++)
        total += cont[i];
    printf("  **** Total character counts: %d\n", total);
    printf("*******************************************************************\n\n");

    for(int i=0;i<bn;i++)
        vowels[buffer[i]]++;
    printf(">>>> The number of occurences of vowels:\n");
    printf("  Vowel '%c': %d\n", 'A', vowels['A']);
    printf("  Vowel '%c': %d\n", 'E', vowels['E']);
    printf("  Vowel '%c': %d\n", 'I', vowels['I']);
    printf("  Vowel '%c': %d\n", 'O', vowels['O']);
    printf("  Vowel '%c': %d\n", 'U', vowels['U']);
    printf("  **** Total vowel count: %d\n", vowels['A'] + vowels['E'] + vowels['I'] + vowels['O'] + vowels['U']);

    printf("*******************************************************************\n\n");



    return 0;
}


