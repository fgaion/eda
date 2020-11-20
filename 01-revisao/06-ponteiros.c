#include <stdio.h>
int main()
{
  int x=5, y=9;
  int *px, *py;

  int k, a[10];
  for(k=0; k<10; k++) a[k] = k;
  int *pa;

 printf("\nPonteiros para inteiros\n");
  printf("\n x = %d e y = %d",x,y);
  px = &x;         //atribui o endereço de x a px
  py = &y;         //atribui o endereço de y a py
  *px = *px + 10;  //soma 10 ao conteudo de x
  *py = 2 * (*py); //multiplica o conteudo de y por 2
  printf("\n x = %d e y = %d\n",x,y);
  
 
  printf("\nPonteiros para arrays\n");
  pa = &a[0];  //equivalente a  pa = a;
  x  = *pa;    //equivalente a  x = a[0];
  printf("\n x = a[0] = %d",x);
  pa++;
  x = *pa;     // equivalente a  x = a[1];
  printf("\n x = a[1] = %d",x);
  pa += 3;
  x = *pa;     // equivalente a  x = a[4];
  printf("\n x = a[4] = %d",x);
  pa += 5;
  x = *pa;     // equivalente a  x = a[9];
  printf("\n x = a[9] = %d",x);
  pa -= 2;
  x = *pa;     // equivalente a  x = a[7];
  printf("\n x = a[7] = %d\n",x);
}
