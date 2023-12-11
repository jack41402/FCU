#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char in_name[31], out_name[31]; // Names of the input and output file.
	FILE *in_file, *out_file; // Pointers of the input and output file stream.
	// A string is represented as a character array.
	// A word of string is of maximum 30 characters.
	char word[31];
	int word_count = 0; // Word count; initial value is 0.
	int vowel_count = 0; // Vowel count; initial value is 0.
	int i; // Loop variable.
	
	do {
		printf("Input the name of the testing text file: ");
		scanf("%s", in_name); // Testing file name.
		printf("\n");
		in_file = fopen(in_name, "r"); // Open the testing file.
	} while (in_file==NULL);	
	
	printf("Input the name of the resulting text file: ");
	scanf("%s", out_name); // Resulting file name.
	printf("\n");
	out_file = fopen(out_name, "w"); // Open the Resulting file.
	
	while (fscanf(in_file, "%s", word)==1) { // Input a string until no more in the input stream.
		printf("%s#", word); // Output the word with '#' sign to the console.
		fprintf(out_file, "%s#", word); // Output the word with '#' sign to the resulting file.
		word_count = word_count + 1; // Increment the word count.
		if (word_count==12) { // If the number of words reaches 12.
			printf("\n"); // Output a newline to the console.
			fprintf(out_file, "\n"); // Output a newline to the resulting file.
			word_count = 0; // Reset the word count to 0.
		}
		for (i=0; i<strlen(word); i++) // Check every character is word.
		// If it is a vowel.
		if (word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' ||word[i]=='U' ||
			word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')
			vowel_count = vowel_count + 1; // Increment the vowel count.
	}
	fclose(in_file); // Close the testing file.
	fclose(out_file); // Close the resulting file.
  
	if (word_count!=0) printf("\n"); // The current line is not finished. Output a newline. 
	// Print a newline before the line contents. That is, print an empty line. 
	printf("\nTotal %d vowels.\n", vowel_count); // Output the total number of vowels.
  
	return 0;
}
