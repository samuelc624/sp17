//First, there is the factorial function to be used in the main part of the code. We initialize n to be the row_index and set all our other variables to be of double type. Take the factorial of n and set it to "nfact". Once we do that, we start a for loop and initialize k to 0. As long as k is less than n or equal to n, we continue the loop and update with k+1. In the loop, we do n-k and set it to denom. Take the factorial of that value and set it to denomfact. Do the factorial of k afterwards and once we have  all three factorial values, we compute to find the value and print it out as well as a space after the value. After the loop has finished, we print a new line. 


#include <stdio.h>							//standard libraries
#include <stdlib.h>

double factorial(int x)							//factorial function
{	int i = 1;							//initialize variables
	double fact = 1;
	if (x==0){							//if x is 0, return 1
		return 1;
	}
	else {								//otherwise, do for loop
		for (i=1; i<=x; i++){					//initialize i to 1, if i is <= x, then do i+1
			fact *= i;					//fact=fact*i
			}
		return fact;						//return
	}
	
}

int main()
{
  int row_index;

  printf("Enter the row index : ");
  scanf("%d",&row_index);

  // Your code starts from here
	int n = row_index;						//set n equal to row_index
	double  k, denom, kfact, denomfact, nfact, value;		//initialze variables and type
	nfact = factorial(n);						//declare nfact
	for (k=0; k<=n; k++){						//for loop - initialize k = 0 - if k is <= n, then to k+1
		denom = n-k;						//denominator = n-k
		denomfact = factorial(denom);				//do factorial "subroutine" and set to denomfact
		kfact = factorial(k);					//do factorial "subroutine" for k and set to kfact
		value = (nfact)/(kfact*denomfact);			//value = n!/(k!denom!)
		printf("%.0f", value);					//print out value
		if (k<n){						//if k is less than row index, printf
		printf(" ");						//print space in between nums
		}
	}
  printf("\n");								//print new line
  return 0;
}
