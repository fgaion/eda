#include <stdio.h>
int fib(int n)
{
  if ( n <= 2 ) return(1);
  else return( fib(n-1) + fib(n-2) );
}

void main()
{
  int k;
  printf("\nFibonacci");
  for(k=1; k <= 20; k++)
    printf("\nFibonacci de %d = %d",k,fib(k));
  printf("\n");  
}
