#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *buffer;
    FILE *datain;
    FILE *dataout;
    int fleng;
    int extend = 0;
    int length = 0;
    int c;
    int i,j;
    int one=0,two=0,three=0,four=0;
    int as=0,es=0,is=0,os=0,us=0;
    datain = fopen("Gift_of_Magi.txt", "r");
    if (datain == NULL) {
        printf("File not found\n");
        return -1;
    }
    buffer = (char*)malloc(512 * sizeof(char));
    while ((c = fgetc(datain)) != EOF) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (length >= extend) {
                extend = extend + 512;
                char *temp = realloc(buffer, extend * sizeof(char));
                buffer = temp;
            }
            if (c >= 'a' && c <= 'z') {
                c = c-32;
            }
            buffer[length++] = c;
            if (buffer[length-1] != buffer[length-2]&&buffer[length-2] != buffer[length-3]){
            	one++;
			}
            if (buffer[length-1] == buffer[length-2]&&buffer[length-2] != buffer[length-3]){
            	two++;
			}
            if (buffer[length-1] == buffer[length-2]&&buffer[length-2] == buffer[length-3]){
            	three++;
			}
            if (buffer[length-1] == buffer[length-2] && buffer[length-2] == buffer[length-3] && buffer[length-3] == buffer[length-4]){
            	four++;
			}
        }
      	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      		if (c=='A'||c=='a'){
      			as = as+1;
			  }
			else if(c=='E'||c=='e'){
      			es = es+1;
			  }
			else if(c=='I'||c=='i'){
      			is = is+1;
			  }
			else if(c=='O'||c=='o'){
      			os = os+1;
			  }
			else if(c=='U'||c=='u'){
      			us = us+1;
			  }
		  }
    }
    two = two -three;
    fclose(datain);
    buffer[length] = '\0';
    dataout = fopen("result.txt", "w");
    fwrite(buffer, sizeof(char), strlen(buffer), dataout);
    fclose(dataout);
	printf(">>>> Total input English characters: %d.\n",length);
	printf("***********************************************************************\n\n");
    printf(">>>> The first 800 characters are:\n");
    int print_length = length < 800 ? length : 800;
    for (i = 0; i < print_length; i++) {
        putchar(buffer[i]);
        if ((i + 1) % 80 == 0)
            putchar('\n');
    }
    printf("\n***********************************************************************\n\n");
	printf(">>>> The number of contiguous letter(s) are:\n");
	printf("One character: %d\n",one);
	printf("Two contiguous characters: %d\n",two);
	printf("Three contiguous characters: %d\n",three);
	printf("Four or more contiguous characters: %d\n",four);
	printf("**** Total characters counts: %d.\n",length);
	printf("***********************************************************************\n\n");
	printf(">>>> The number of occurences of vowels:\n");
	printf("Vowel 'A': %d\n",as);
	printf("Vowel 'E': %d\n",es);
	printf("Vowel 'I': %d\n",is);
	printf("Vowel 'O': %d\n",os);
	printf("Vowel 'U': %d\n",us);
	printf("**** Total vowel count: %d",as+es+is+os+us);
	free(buffer);

    return 0;
}
