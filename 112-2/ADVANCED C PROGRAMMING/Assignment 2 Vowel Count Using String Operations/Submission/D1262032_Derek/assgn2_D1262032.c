#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void printChar(int q){
    int i;
    for(i=0;i<q;i++) printf("*");
    printf("\n");
}

int main(void) {
    char *buffer;
    int capacity=512, index=0, i, counts=0, ONE=0, TWO=0, THREE=0, FOURorMORE=0, countmore=0;//"counts" is the counts of contiguous letter; "countmore" is the count number that needs to be increased when there are four or more contiguous characters.
    FILE *dataIn, *dataOut;
    
    buffer=(char *)malloc(capacity*sizeof(char));
    dataIn=fopen("Gift_of_Magi.txt", "r");
    if (dataIn==NULL) {
        printf("\nText file \"Gift_of_Magi.txt\" does not exist.\n");
        system("pause");
        return -1;
    }
    int c;
    while(!feof(dataIn)){//input the file character by character until reaching the end of file
        c=fgetc(dataIn);
        if(isalpha(c)){
            if(index==capacity){
                buffer=(char *)realloc(buffer, (capacity+512)*sizeof(char));
                capacity+=512;
            }
            buffer[index++]=toupper(c);
        }
    }
    buffer[index]='\0';
    fclose(dataIn);
    printf(">>>> Total input English characters: %d.\n", index);
    printChar(71);
    dataOut=fopen("result.txt", "w");
    fwrite(buffer, sizeof(char), index, dataOut);
    printf("\n>>>> The first 800 characters are:\n  ");
    for(i=0;i<800;i++){ // Print the first 800 characters of the input text
        if(i%80==0 && i!=0) printf("\n  ");
        printf("%c", buffer[i]);
    }
    printf("\n\n");
    printChar(71);
    i=0;
    while(buffer[i]!='\0'){//count the number of contiguous letters
        if(buffer[i]==buffer[i+1]){
            if(buffer[i+1]==buffer[i+2]){
                if(buffer[i+2]==buffer[i+3]){
                    FOURorMORE++;
                    counts+=4;
                    for(i=i+3;i<index;i++){//check it whether over four contiguous characters
                        if(buffer[i]!=buffer[i+1]){break;}
                        countmore++;
                    }
                    counts+=countmore;
                }
                else{ THREE++; i=i+2; counts+=3;}
            }
            else{TWO++; i=i+1; counts+=2;}
        }
        else {ONE++; counts+=1;}
        i++;
    }
    printf("\n>>>> The number of contiguous letter(s) are:");
    printf("\n  One character: %d", ONE);
    printf("\n  Two contiguous characters: %d", TWO);
    printf("\n  Three contiguous characters: %d", THREE);
    printf("\n  Four or more contiguous characters: %d", FOURorMORE);
    printf("\n  **** Total character counts: %d\n", counts);
    printChar(71);
    int count_A=0, count_E=0, count_I=0, count_O=0, count_U=0, total_vowel_count=0;
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
            if(i==0) { count_A++; ptr=strpbrk(ptr+1, "A"); }
            else if(i==1) { count_E++; ptr=strpbrk(ptr+1, "E"); }
            else if(i==2) { count_I++; ptr=strpbrk(ptr+1, "I"); }
            else if(i==3) { count_O++; ptr=strpbrk(ptr+1, "O"); }
            else if(i==4) { count_U++; ptr=strpbrk(ptr+1, "U"); }
        }
    }
    printf("\n>>>> The number of occurences of vowels:");
    printf("\n  Vowel 'A': %d", count_A);
    printf("\n  Vowel 'E': %d", count_E);
    printf("\n  Vowel 'I': %d", count_I);
    printf("\n  Vowel 'O': %d", count_O);
    printf("\n  Vowel 'U': %d", count_U);
    printf("\n  **** Total vowel count: %d\n", total_vowel_count);
    printChar(71);
    fclose(dataOut);
    free(buffer);
    return 0;
}
