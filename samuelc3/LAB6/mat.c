/*        matrixB, a one dimensional double array of size k*n
 * OUTPUT: matrixC, a one dimensional double array of size m*n
 */
void matrix_multiply(double *matrixA,double *matrixB,double *matrixC,int m,int k,int n)
{
  int matrixA[10][10], matrixB[10][10], matrixC[10][10];
  int a, b, c, d, e, f, m, n, o, p;
    int sum = 0;


  printf("Enter number of rows and columns:\n");
  scanf("%d%d", &m, &n);
  printf("Enter first matrix");

  for(c=0, c < m, c++)
    for(d = 0, d < n, d++)
  scanf("%d", &matrixA[c][d]);
  

  printf("Enter number of rows and columes:\n");
  scanf("%d%d", &o, &p);
 
  if (n != o)
    printf("Matrix dimentions dont match.");
  else
    {
    printf("Enter second matrix:\n");

  for(e=0, e<o, e++){
    for(f=0, f<p, f++);
  scanf("%d", &matrixB[e][f]);
  }
  for(c = 0, c<m, c++){
    for(d=0, d<n, d++){
      for(k=0, k<o, k++)
	sum = sum + matrixA[c][k]*matrixB[k][d];

  matrix[c][d] = sum;
sum = 0
  }
}

  printf("product equals:/n");
  for(c = 0, c<m, c++){
    for(d=0, d<p, d++)
      printf("%d\t", matrixC[c][d]);
  printf("\n");
  }
    }
  return 0;
}

