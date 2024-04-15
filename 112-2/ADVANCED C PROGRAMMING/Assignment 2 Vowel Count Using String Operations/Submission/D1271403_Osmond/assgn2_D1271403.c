#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(void) {
    
    int capacity=512, total=0, counts=0, one=0, two=0, three=0, fourormore=0, countmore=0;  //define all variables
    
    int i;
    FILE *dataIn;
    FILE *dataOut;
    
    char *buffer;
    
    buffer=(char *)malloc(capacity*sizeof(char)); //Use dynamic space allocation to open space
    
    dataIn=fopen("Gift_of_Magi.txt", "r"); //Open file
    
    if (dataIn==NULL) {
        printf("\nText file \"Gift_of_Magi.txt\" does not exist.\n");
        system("pause");
        return -1;
    }
    
    int a;
    while(!feof(dataIn)){ //Determine whether it is the end of the string
        a=fgetc(dataIn);
        if(isalpha(a)){
            if(total==capacity){
                buffer=(char *)realloc(buffer, (capacity+512)*sizeof(char));
                capacity+=512;
            }
            buffer[total++]=toupper(a); // Make letters uppercase one by one
        }
    }
    buffer[total]='\0'; //end of string
    fclose(dataIn);
    
    printf(">>>> Total input English characters: %d.\n", total);
    
    
    for(i=0;i<71;i++) 
    {
        printf("*");
    }
    printf("\n");
    
    
    //Open file in writing format
    dataOut=fopen("result.txt", "w");
    fwrite(buffer, sizeof(char), total, dataOut);
    printf("\n>>>> The first 800 characters are:\n  ");
    for(i=0;i<800;i++){
        if(i%80==0 && i!=0) printf("\n  ");
        printf("%c", buffer[i]);
    }
    
    printf("\n\n");
    
    for(i=0;i<71;i++)
    {
        printf("*");
    }
    printf("\n");
    
    
    i = 0;
        while (buffer[i] != '\0') {
            int count = 1;
            while (buffer[i] == buffer[i + count]) {
                count++;
            }
            // Statistics based on the number of consecutive identical characters
            switch (count) {
                case 1:
                    one++;
                    counts++;
                    break;
                case 2:
                    two++;
                    counts += 2;
                    break;
                case 3:
                    three++;
                    counts += 3;
                    break;
                default:
                    fourormore++;
                    counts += count;
                    break;
            }

            // Update index
            i += count;
        }
    

    // print out the result
    printf("\n>>>> The number of contiguous letter(s) are:");
    printf("\n  One character: %d", one);
    printf("\n  Two contiguous characters: %d", two);
    printf("\n  Three contiguous characters: %d", three);
    printf("\n  Four or more contiguous characters: %d", fourormore);
    printf("\n  **** Total character counts: %d\n", counts);
    
    
    for(i=0;i<71;i++)
    {
        printf("*");
    }
    printf("\n");
    
    
    
    int count_A=0, count_E=0, count_I=0, count_O=0, count_U=0, total_vowel_count=0;
    char vowel[]="AEIOU";
    
    //Traverse vowel strings
    for(i=0;vowel[i]!='\0';i++){
        char *ptr;
        ptr=buffer;
        
        if(i==0) ptr=strpbrk(ptr, "A");
        else if(i==1) ptr=strpbrk(ptr, "E");
        else if(i==2) ptr=strpbrk(ptr, "I");
        else if(i==3) ptr=strpbrk(ptr, "O");
        else if(i==4) ptr=strpbrk(ptr, "U");
        
        //Loop until the vowel is not found
        while(ptr!=NULL){
            total_vowel_count++;
            
            if(i==0) {count_A++; ptr=strpbrk(ptr+1, "A");}
            else if(i==1) { count_E++; ptr=strpbrk(ptr+1, "E");}
            else if(i==2) { count_I++; ptr=strpbrk(ptr+1, "I");}
            else if(i==3) { count_O++; ptr=strpbrk(ptr+1, "O");}
            else if(i==4) { count_U++; ptr=strpbrk(ptr+1, "U");}
        }
    }
    
    //printf out the result
    printf("\n>>>> The number of occurences of vowels:");
    printf("\n  Vowel 'A': %d", count_A);
    printf("\n  Vowel 'E': %d", count_E);
    printf("\n  Vowel 'I': %d", count_I);
    printf("\n  Vowel 'O': %d", count_O);
    printf("\n  Vowel 'U': %d", count_U);
    printf("\n  **** Total vowel count: %d\n", total_vowel_count);
    
    for(i=0;i<71;i++)
    {
        printf("*");
    }
    printf("\n");
    
    fclose(dataOut);
    free(buffer);
    return 0;
}
