#include <stdio.h>


void Binary(int);
void ReverseBinary(int);
void hexadecimal(int);
void Reversehexadecimal(int);



int main(void) {
	unsigned num, rev; // Two 32-bit integers.. 
	int i; // Loop variable.
	
	do {
		// a. Input a 32-bit non-negative integer num, i.e., 0¡Ünum¡Ü4,294,967,295.
		printf("Input a 32-bit unsigned integer num, 0<=num<=4,294,967,295: ");
		scanf("%u", &num); // Input 32-bit integer.		
		if (num==0) return 0;
		
		
		printf("Binary representation of num:\n");
		Binary(num);
		printf("\n\n");
		
		
		
		
		printf("hexadecimal representation of num:\n");
		hexadecimal(num);
		printf("\n\n");
		
		
		printf("Binary representation of rev:\n");
		ReverseBinary(num);
		printf("\n\n");
		
		
		
		printf("hexadecimal representation of rev:\n");
		Reversehexadecimal(num);
		printf("\n\n");
		

		printf("\n----------------------------------\n"); // Print a separating line.
		
	} while (1); // Repeat the loop until input value of num is 0.
	
}



void Binary(int a){
	int i;
	for(i=31;i>=0;i--){
		int list=(a>>i)&1;
		printf("%d",list);
		if((i+1)%8==1){
			printf(" ");
		}
	}
}
void ReverseBinary(int a){
	int i;
	for(i=0;i<=31;i++){
		int list=(a>>i)&1;
		printf("%d",list);
		if((i+1)%8==0){
			printf(" ");
	}
  }
}

void hexadecimal(int a){
	int i;
	for(i=7;i>=0;i--){
		int N[32];
		int j;
		for(j=31;j>=0;j--){
		int list=(a>>j)&1;
		N[j]=list;
		}
		int sum;
		sum=N[i*4+3]*8+N[i*4+2]*4+N[i*4+1]*2+N[i*4]*1;
		printf("%X",sum);
		if((i)%2==0){
			printf(" ");
		}
	}
	
}

void Reversehexadecimal(int a){
	int i;
	for(i=0;i<=7;i++){
		int N[32];
		int j;
		for(j=0;j<=31;j++){
		int list=(a>>j)&1;
		N[j]=list;
		}
		int sum;
		sum=N[i*4]*8+N[i*4+1]*4+N[i*4+2]*2+N[i*4+3]*1;
		printf("%X",sum);
		if((i)%2==1){
			printf(" ");
		}
	}

}



	



