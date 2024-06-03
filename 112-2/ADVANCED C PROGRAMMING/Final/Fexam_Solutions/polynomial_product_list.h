// Basic operation interface of single linked ordered linear list.
typedef int Degree; // Polynomial degree.

typedef float Coeff; // Polynomial coefficient. 

typedef struct node { // Define linked list node 
	Degree degree; // Degree of a polynomial term.
	Coeff  coeff; // Coefficient of a polynimial term. 
	struct node* next; // Node link, defined recursively
} Node; // Node type 

typedef Node* Term; // Node link, pointer to a node.

// A polynomial is a pointer to an ordered single-link linear list.
// The linear list is stored in the decreasing order.
// The first node points to the highest degree term.
typedef Term Polynomial; 

// Initialize polynomial.
void initial(Polynomial *);

// Get number of terms of the polynomial. 
int getTerm(Polynomial); 

// Get a polynomial term with given degree.
// If no term with the specified degree, return -99.
Coeff getCoeff(Polynomial, Degree);

// Search a polynomial term with a specified degree. 
// If successful, return the degree of the term; otherwise, return -1.
Degree searchTerm(Polynomial, Degree);  

// Replace a polynomial term of a specified degree with given coefficient.
// If coefficient is 0.0, the correspoinding term is removed. 
// If the term of specified degree does not exist, insert a new term.
// Return degree of the term.
Degree replaceTerm(Polynomial *, Degree, Coeff);

// Clear the polynomial.
void clear(Polynomial *);

// Checks whether the polynomial is empty. Return 1, if empty; otherwise, return 0.
int is_empty(Polynomial); 

// Print the polynomial.
void printPoly(Polynomial);

// Product of polynomial multiplication.
Polynomial productPolynomial(Polynomial, Polynomial);
 

