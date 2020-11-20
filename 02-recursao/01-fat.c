#include <stdio.h>
long int fat(int n)
{
  if ( n < 0 ) return(-1);
  if ( n == 0 || n == 1 ) return(1);
  return( n * fat(n-1) );
}
void main()
{
  int k;
  printf("\nFatorial");
  for(k=1; k <= 10; k++)
    printf("\nFatorial de %d = %ld",k,fat(k));
  printf("\n");  
}
