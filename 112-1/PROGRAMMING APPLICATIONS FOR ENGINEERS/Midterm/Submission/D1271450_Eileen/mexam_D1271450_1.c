#include <stdio.h>

int main(void) {
	// (1) Declare integer arrays A[9][9] for coefficients and C[9] 

	//     for constants (the maximum value of n is 9). 
	int n; // Rank of a linear equation system.
	int A[9][9]={{0,1,2,3,4,5,6,7,8},{0,1,2,3,4,5,6,7,8}}; // Maximum 9 coefficients for each of maximum 9 equations.
	int C[9]={0,1,2,3,4,5,6,7,8}; // Maximum 9 constants.
	int non_zero_coeff; // Flag to indicate a non_zero coefficient in an equation or for a variable.
	int leading_term; // Flag to indicate whether a leading term or not. 
	int i, j; // Loop variables.
	int a,b,c,d,e,f,g,h,k,l,m,o,p,q,r,s,t,u,v,w,x,y,z,ab,ac,ad,ae,af,ag,ah,ai,aj,ak,al,am,an,ao,ap,aq,ar,as,at,au,aa,bb,cc,dd,ee,ff,gg,hh,ii,jj,kk;
	
	do {
		// (2) Input the rank of the linear equation system n, where 1<=n<=9.
		do {
			printf("Enter the rank of linear equation system (1 to 9 and 0 to stop): "); // Print a message.
			scanf("%d", &n); // Number of coefficients of a linear equation.
		} while (n<0 || n>9);
		if (n==0) return 0; // Program terminates, if n is 0.
		for(i=0;i<n;++i){
		printf(">>>> Enter %d coefficients and a constant for equation %d (between-99 and 99):",n,i);
		if(n==1){
		scanf("%d", &a,&dd);}
		else if(n==2){
			scanf("%d%d", &b,&c,&d);
		}
			else if(n==3){
			scanf("%d%d%d", &e,&f,&g,&ee);
		}
			else if(n==4){
			scanf("%d%d%d%d", &h,&aa,&bb,&k,&ff);
		}
			else if(n==5){
			scanf("%d%d%d%d%d", &l,&m,&cc,&o,&p,&gg);
		}
			else if(n==6){
			scanf("%d%d%d%d%d%d", &q,&r,&s,&t,&u,&v,&hh);
		}
			else if(n==7){
			scanf("%d%d%d%d%d%d%d", &w,&x,&y,&z,&ab,&ac,&ad,&ii);
		}
			else if(n==8){
			scanf("%d%d%d%d%d%d%d%d", &ae,&af,&ag,&ah,&ai,&aj,&ak,&al,&jj);
		}
		else{
			scanf("%d%d%d%d%d%d%d%d%d", &am,&an,&ao,&ap,&aq,&ar,&as,&at,&au,&kk);
		}
		
		}
		printf("<<<< The linear equation system of rank n is:");
		printf("\n");
		if(n==9){
		for(i=0;i<9;++i){
		printf("          %d X0 %d X1 %d X2 %d X3 %d X4 %d X5 %d X6 %d X7 %d X8 =%d\n ",am,an,ao,ap,ar,as,at,au,kk);}
		}
		else if(n==8){
		for(i=0;i<8;++i){
		printf("          %d X0 %d X1 %d X2 %d X3 %d X4 %d X5 %d X6 %d X7  =%d\n ",ae,af,ag,ah,ai,aj,ak,al,jj);}
			}
			else if(n==7){
		for(i=0;i<7;++i){
		printf("          %d X0 %d X1 %d X2 %d X3 %d X4 %d X5 %d X6  =%d\n ",w,x,y,z,ab,ac,ad,ii);}
			;}
			else if(n==6){
		for(i=0;i<6;++i){
		printf("          %d X0 %d X1 %d X2 %d X3 %d X4 %d X5  =%d\n ",q,r,s,t,u,v,hh);}
			}
			else if(n==5){
		for(i=0;i<5;++i){
		printf("          %d X0 %d X1 %d X2 %d X3 %d X4  =%d\n ",l,m,cc,o,p,gg);}
			}
			else if(n==4){
		for(i=0;i<4;++i){
		printf("          %d X0 %d X1 %d X2 %d X3  =%d\n",h,aa,bb,k,ff);}
			}
			else if(n==3){
		for(i=0;i<3;++i){
		printf("          %d X0 %d X1 %d X2 =%d\n ",e,f,g,ee);}
		}
			else if(n==2){
		for(i=0;i<2;++i){
		printf("          %d X0 %d X1 =%d\n ",b,c,d);}
		}
			else {
		for(i=0;i<1;++i){
		printf("          %d X0  =%d\n ",a,dd);}}
		
		// ***** Complete program of the following steps.
		
		// (3) For equation i, A[i][0] X0 +A[i][1] X1 + ... + A[i][n-1] Xn-1 = Ci, where 0<=i<=n-1, 
		//     input n integers of coefficients and a constant to store them in A[i][j] 
		//     and C[i], where 0<=j<=n-1, such that -99<=A[i][j], C[i]<=99. Verify that 
		//     (a) there is no equation with all zero coefficients, and 
		//     (b) there is no variable Xj with all zero coefficients.
		
		
		// (4) Print the linear equation one equation in a line, leave 10 leading blanks before
		//     each equation. For each equation, print all terms in the way that 
		//     (a) if a term is of coefficient zero, print blanks only, 
		//     (b) if a term is the first non-zero coefficient term in an equation, do not print 
		//         its operator, but print only the coefficient value and its variable name, 
		//     (c) if a coefficient is either 1 or -1, omit the coefficient value and print 
		//         operator '+' or '-', blanks, and its variable name, 
		//     (d) for coefficients other than 0, 1, and -1, print '+' or '-', coefficient 
		//         value without sign, and its variable name, 
		//     (e) Align operators '+' or '-' for the terms of the same Xi and '=' 
		//         in the vertical direction. 
		// Repeat steps (2) to (4) until the value of n is 0.
	
		printf("\n----------------------------------\n"); // Print a separating line. 
	} while (1); // Repeat the loop.
}

