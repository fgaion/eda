#include <stdio.h>

struct Data
{
  int ano,mes,dia;
};

struct Cheque
{
  int Num;
  float Valor;
  struct Data Cdt;
};

void main()
{
  struct Cheque c1, c2;

  printf("\nNumero do Cheque: "); scanf("%d",&c1.Num);
  printf("Valor  do Cheque  : "); scanf("%f",&c1.Valor);
  printf("Dia: "); scanf("%d",&c1.Cdt.dia);
  printf("Mes: "); scanf("%d",&c1.Cdt.mes);
  printf("Ano: "); scanf("%d",&c1.Cdt.ano);

  printf("\nNumero do Cheque: "); scanf("%d",&c2.Num);
  printf("Valor  do Cheque  : "); scanf("%f",&c2.Valor);
  printf("Dia: "); scanf("%d",&c2.Cdt.dia);
  printf("Mes: "); scanf("%d",&c2.Cdt.mes);
  printf("Ano: "); scanf("%d",&c2.Cdt.ano);


  if ( c1.Valor > c2.Valor )
    printf("\nMaior Cheque: %d Valor R$: %5.2f\nData: %d/%d/%d\n",c1.Num,c1.Valor,c1.Cdt.dia,c1.Cdt.mes,c1.Cdt.ano);
  else
    printf("\nMaior Cheque: %d Valor R$: %5.2f\nData: %d/%d/%d\n",c2.Num,c2.Valor,c2.Cdt.dia,c2.Cdt.mes,c2.Cdt.ano);

}
