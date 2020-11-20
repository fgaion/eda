#include <stdio.h>
#include <string.h>

#define MAX_PECAS 3

struct Peca
{
  float Cod;
  char Desc[40];
  int Qtde;
};
struct Peca Inventario[MAX_PECAS];

int main()
{
  int k,q;
  float c;
  char d[40];
  for(k=0; k<MAX_PECAS; k++)
  {
    printf("\nCodigo:   "); scanf("%f",&c);
    printf("Descricao:  "); scanf("%s",d);
    printf("Quantidade:  "); scanf("%d",&q);
    //printf("\nteste: %f -%s - %d",c,d,q);
    Inventario[k].Cod = c;
    Inventario[k].Qtde = q;
    strcpy(Inventario[k].Desc,d);
  }
  printf("\nListagem de Pecas: ");
  for(k=0; k < MAX_PECAS; k++)
    printf("\n %f - %s - %d",Inventario[k].Cod,Inventario[k].Desc,Inventario[k].Qtde);    
}
