#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "polynomial_product_list_D1228792.h"

// Generate polynomial with a specified degree.
void genePolynomial(Polynomial *P, int deg) {
	srand(time(NULL));
	int i;
	for(i=deg;i>=0;i--){
		if(i==deg){
			replaceTerm(P,i, (rand()%1999-999)/100.0);
		}
		else{
			if((rand()%100)>=50){
				replaceTerm(P,i, (rand()%1999-999)/100.0);
			}
		}
	}	
	//***** Complete this function. 
}

// Evaluate polynomial P(a).
double evalPolynomial(Polynomial P, float a) {
	double ans=0.0;
	int i;
	Term current = P;
	for(i=0;i<getTerm(P);i++){
		ans = ans + current->coeff*pow(a,current->degree);
		current = current->next;
	}
	return ans;
	//***** Complete this function. 
}

int main(void) {
	Polynomial P, Q; // Declare two polynomials. 
	Polynomial prod; // Product of polynomial P and Q. 
	Degree deg; // Degree of the polynomial.
	Coeff coeff; // Coefficient of the polynomial.
	float a; // Value of X to evaluate the polynomial. 
	float eval_P, eval_Q, eval_PQ,ep,eq,epq; // Values of P(a), Q(a), and PQ(a)
	int count;
	
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
	
	// ***** Complete the following steps. 
	
	// Evaluate polynomial P(a).
	// Print the vlaue of P(a).
	eval_P = evalPolynomial(P, a);
	ep = eval_P;
	count=0;
	printf("\n>>>>Evaluation of Polynomial P(a): ");
	if(ep<0.1&&ep>-0.1){
		while(ep<0.1&&ep>-0.1){
			count--;
			ep=ep*10;
		}
	}
	else if(ep>10||ep<-10){
		while(ep>10||ep<-10){
			count++;
			ep=ep/10;
		}
	}
	printf("%5.3fE",ep);
	if(count>0){
		if(count>=100) printf("+%d",count);
		else if(count>=10) printf("+0%d",count);
		else printf("+00%d",count);
	}
	else if(count<0){
		if(count<=-100) printf("%d",count);
		else if(count<=-10) printf("-0%d",-1*count);
		else printf("-00%d",-1*count);
	}
		else printf("+000");
	// Evaluate polynomial Q(a).
	// Print the vlaue of Q(a).
	eval_Q = evalPolynomial(Q, a);
	eq = eval_Q;
	count=0;
	printf("\n>>>>Evaluation of Polynomial Q(a): ");
	if(eq<0.1&&eq>-0.1){
		while(eq<0.1&&eq>-0.1){
			count--;
			eq=eq*10;
		}
	}
	else if(eq>10||eq<-10){
		while(eq>10||eq<-10){
			count++;
			ep=eq/10;
		}
	}
	printf("%5.3fE",eq);
	if(count>0){
		if(count>=100) printf("+%d",count);
		else if(count>=10) printf("+0%d",count);
		else printf("+00%d",count);
	}
	else if(count<0){
		if(count<=-100) printf("%d",count);
		else if(count<=-10) printf("-0%d",-1*count);
		else printf("-00%d",-1*count);
	}
	else printf("+000");
	// Compute product P*Q(X) of polynominals P(X) and Q(X).
	
	// Print polynomial product P*Q(X).
	
	// Evaluate polynomial P*Q(a).
	// Print the vlaue of P*Q(a).
	
	// Print the absolute vlaue of P(a)*Q(a)-P*Q(a).
	
	// Check whether |P(a)*Q(a)-P*Q(a)|<0.000001 or not.

	return 0; 
} 
