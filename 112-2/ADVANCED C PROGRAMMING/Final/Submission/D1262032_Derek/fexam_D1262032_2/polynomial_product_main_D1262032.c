#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_D1262032.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {	
	int i;
	Term newNode;
	Term current=NULL;
	for(i=deg;i>=0;i--){
	if(i==deg){
		newNode=(Term)malloc(sizeof(Node));
		newNode->degree=i;
		newNode->coeff=(rand()%20001-10000)/1000.0;
		newNode->next=NULL;
		current=newNode;
		*P=newNode;
	}
	if(rand()%2==0){
		newNode=(Term)malloc(sizeof(Node));
		newNode->degree=i;
		newNode->coeff=(rand()%20001-10000)/1000.0;
		newNode->next=NULL;
		current->next=newNode;
		current=newNode;
	}
	
	}
	//***** Complete this function. 
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	int i;
	Term current=P;
	double e=0.0;
	for(i=current->degree;i>=0;i--){
		if(current==NULL) { break; }
			e+=current->coeff*pow(a, current->degree);
			current=current->next;
	}
	return e;
	//***** Complete this function. 
}

int main(void) {
	Polynomial P, Q; // Declare two polynomials. 
	Polynomial prod; // Product of polynomial P and Q. 
	Degree deg; // Degree of the polynomial.
	Coeff coeff; // Coefficient of the polynomial.
	float a; // Value of X to evaluate the polynomial. 
	float eval_P, eval_Q, eval_PQ; // Values of P(a), Q(a), and PQ(a)
	
	srand(time(NULL)); // Seed for the random number generator.
	
	initial(&P); // Initialize P.
	initial(&Q); // Initialize Q.	
	initial(&prod); // Initialize prod.
  
	do {
		printf("Enter degree of polynomial P (between 0 and 20): ");
		scanf("%d", &deg); // Enter a degree.
	} while (deg<0 || deg>20);	
	genePolynomial(&P, deg); // Generate polynomial P.
	
	do {
		printf("Enter degree of polynomial Q (between 0 and 20): ");
		scanf("%d", &deg); // Enter a degree.
	} while (deg<0 || deg>20);	
	genePolynomial(&Q, deg); // Generate polynomial Q.
  
	do {
		printf("Enter value of a (between -1.0 and 1.0): ");
		scanf("%f", &a); // Enter a degree.
	} while (a<-1.0 || a>1.0);
	
	printf("\n>>>> Polynomial P(X) has %d non-zero coefficient terms.\n    ", getTerm(P));
	printPoly(P); // Print polynomial P.
	
	printf("\n>>>> Polynomial Q(X) has %d non-zero coefficient terms.\n    ", getTerm(Q));
	printPoly(Q); // Print polynomial Q.
	printf("\n");
	
	printf(">>>> Evaluation of Polynomial P(a): %E\n", evalPolynomial(P, a));
	printf(">>>> Evaluation of Polynomial Q(a): %E\n", evalPolynomial(Q, a));
	
	prod=productPolynomial(P, Q);
	
	printf("\n>>>> Polynomial product P*Q(X) has %d non-zero coefficient terms.\n    ", getTerm(prod));
	printPoly(prod);
	printf(">>>> Evaluation of Polynomial P*Q(a): %E\n", evalPolynomial(prod, a));
	printf(">>>> |eval_P*eval_Q-eval_PQ| == %E\n", evalPolynomial(P, a)*evalPolynomial(Q, a)-evalPolynomial(prod, a));
	if(evalPolynomial(P, a)*evalPolynomial(Q, a)-evalPolynomial(prod, a)==0) printf(">>>> Verified, P(a)*Q(a) equals to P*Q(a).\n");
	else printf(">>>> Failed, P(a)*Q(a) is not equal to P*Q(a).\n");
	// ***** Complete the following steps. 
	
	// Evaluate polynomial P(a).
	// Print the vlaue of P(a).
	
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	
	// Print polynomial product P*Q(X).
	
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.

	return 0; 
} 
