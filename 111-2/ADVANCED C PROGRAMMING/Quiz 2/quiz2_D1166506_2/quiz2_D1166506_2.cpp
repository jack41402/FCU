#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "CStack_D1166506.h" 

using namespace std;

int length ;

// ***** Complete the following three functions.
 
// Check whether string str contains all parenthesis symbols,
// '(', ')', '[', ']', '{', or '}'. 
int allParenthesis(char *str)
{
	bool flag ;
	for (int i=0 ; i<length ; ++i)
	{
		if (str[i]=='(' || str[i]==')' || str[i]=='[' || str[i]==']' || str[i]=='{' || str[i]=='}')
		{
			flag = true ;
		}
		else
		{
			flag = false ;
			break ;
		}
	}
	return flag;
}

// Check if two characters are matching parentheses. 
int isMatching(char e, char c)
{
	if (e=='(' && c==')') return true;
	else if (e=='[' && c==']') return true;
	else if (e=='{' && c=='}') return true;
	return false;
} 

// Check if a string contains matching parentheses.
bool parenthesisMatching(char *str)
{

	CStack s ;
	for (int i=0 ; i<length ; ++i)
	{
		if (str[i]=='(' || str[i]=='[' || str[i]=='{')
		{
			s.push(str[i]) ;
		}
		else if (str[i]==')' || str[i]==']' || str[i]=='}')
		{
//			cout << str[i] << '\n' ;
//			cout << s.top() << '\n' ;
			bool check=isMatching(s.top() , str[i]) ;
			if (check) s.pop() ;
			else return false;
		}
	}
	if (s.isEmpty()) return true;
	else return false;
} 

int main() {
  char str[100]; // String of parentheses.
  	do { // Repeat until the input string is "stop".
    	do { // Input a string of parenthese.
		  	printf("Input a string of parentheses ('(', ')', '[', ']', '{', '}'): ");
			scanf("%s", &str);
			length = 0 ;
			while (str[length]) length++ ;
			if (!strcmp(str, "stop")) return 0; // If the string is "stop", program terminates. 
		} while (!allParenthesis(str));
		
		if (parenthesisMatching(str)) printf("**** String %s is all matching parentheses.\n", str);
		else printf("**** String %s is not all matching parentheses.\n", str); 
	
		printf("\n----------------------------------------\n\n"); // Print a separate line. 		
	} while (1);

  	return 0; 	 
}
