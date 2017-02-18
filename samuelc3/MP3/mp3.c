#include <stdio.h>
#include <stdlib.h>

double factorial(int x)
{	int i = 1;
	double fact = 1;
	if (x==0){
		return 1;
	}
	else {
		for (i=1; i<=x; i++){
			fact *= i;
			}
		return fact;
	}
	
}

int main()
{
  int row_index;

  printf("Enter the row index : ");
  scanf("%d",&row_index);

  // Your code starts from here
	int n = row_index;
	double  k, denom, kfact, denomfact, nfact, value;
	nfact = factorial(n);
	for (k=0; k<=n; k++){
		denom = n-k;
		denomfact = factorial(denom);
		kfact = factorial(k);
		value = (nfact)/(kfact*denomfact);
		printf("%.0f", value);
		if (k<n){
		printf(" ");
		}
	}
  printf("\n");
  return 0;
}
