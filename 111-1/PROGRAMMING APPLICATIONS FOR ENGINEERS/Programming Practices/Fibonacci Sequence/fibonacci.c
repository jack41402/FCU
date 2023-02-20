#include<stdio.h>
#include<stdlib.h>

// Recursive Fibonacci function
unsigned long long fibonacci_recu(int n) {
  if (n==0) return 1;
  else if (n==1) return 1;
  else return fibonacci_recu(n-1) + fibonacci_recu(n-2);
}

// Iterative Fibonacci function
unsigned long long fibonacci_iter(int n) {
  unsigned long long last1, last2, result;
  int i;
  
  if (n==0 || n==1) return 1;
  else {
	  last1 = 1; last2 = 1;
	  for (i=2; i<=n; i++) {
		  result = last1 + last2;
		  last2 = last1;
		  last1 = result; }
	  return result;
  }
}

// Fast recursive Fibonacci function
unsigned long long fibonacci_fast(int n) {
  if (n==0 || n==1) return 1;
  if (n==2) return 2;  
  if (n % 2 == 0) {
    return fibonacci_fast(n/2+1)*fibonacci_fast(n/2)-fibonacci_fast(n/2-1)*fibonacci_fast(n/2-2); } 
  else {
    return fibonacci_fast(n/2+1)*fibonacci_fast(n/2)+fibonacci_fast(n/2)*fibonacci_fast(n/2-1); }
}


int main(void) {
	int n; // Input data.
	
	printf("Enter n: "); // Read an integer.
	scanf("%d", &n);
	while (n>=0) {
	  printf("Recursive Fibonacci of %d: %llu\n", n, fibonacci_recu(n));
	  printf("Iterative Fibonacci of %d: %llu\n", n, fibonacci_iter(n));
	  printf("     Fast Fibonacci of %d: %llu\n", n, fibonacci_fast(n));
	  printf("\n**********************************************\n\n");	  
	  printf("Enter n: "); // Read an integer.
	  scanf("%d", &n);
	};
	  
  return 0; 
}

