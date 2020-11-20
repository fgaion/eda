#include <stdio.h>
int funcV(int a, int b)
{
  a = a + 5;
  b = b + 2;
  printf("\nDentro de funcV: a = %d e b = %d",a,b);
}

int funcR(int *a, int *b)
{
  *a = *a + 5;
  *b = *b + 2;
  printf("\nDentro de funcR: a = %d e b = %d",*a,*b);  
}

void main()
{
  int x=10, y=6;
  printf("\nPassagem de parametros por valor:");
  printf("\nDentro de main, antes da chamada a funcV: x = %d e y = %d",x,y);
  funcV(x,y);
  printf("\nDentro de main, depois da chamada a funcV: x = %d e y = %d",x,y);

  printf("\n\nPassagem de parametros por referencia:");
  printf("\nDentro de main, antes da chamada a funcR: x = %d e y = %d",x,y);
  funcR(&x,&y);
  printf("\nDentro de main, depois da chamada a funcR: x = %d e y = %d\n",x,y);
}
