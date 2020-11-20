/*******************************************************************
* Arvore Binária
* Desenvolvido por: Fábio Gaion
* Observações:
* implementação com vetor
O programa abaixo monta a seguinte arvore binaria
		 F
	  /   \
	B      G
 /  \      \
A    D      I
	 / \    /
	C   E  H

No vetor
			  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 ... 29
Info        F  B  G  A  D  -  I  -  -  C  E  -  -  H  -  - ...  -

*******************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_NO 30

struct No
{
  char Info[10];
  int ExisteNo; //indica se o no existe
};
struct No Arv[MAX_NO];

void InOrder(int T){
  if ( Arv[T].ExisteNo != 0 ){
	 InOrder(2*T + 1);
	 printf("%s ",Arv[T].Info);
	 InOrder(2*T + 2);
  }
}

void PreOrder(int T){
  if ( Arv[T].ExisteNo != 0 ){
	 printf("%s ",Arv[T].Info);
	 PreOrder(2*T + 1);
	 PreOrder(2*T + 2);
  }
}

void PosOrder(int T){
  if ( Arv[T].ExisteNo != 0 ){
	 PosOrder(2*T + 1);
	 PosOrder(2*T + 2);
	 printf("%s ",Arv[T].Info);
  }
}

void monta_arv_exemplo()
{
  strcpy(Arv[ 0].Info,"F"); Arv[ 0].ExisteNo = 1;
  strcpy(Arv[ 1].Info,"B"); Arv[ 1].ExisteNo = 1;
  strcpy(Arv[ 2].Info,"G"); Arv[ 2].ExisteNo = 1;
  strcpy(Arv[ 3].Info,"A"); Arv[ 3].ExisteNo = 1;
  strcpy(Arv[ 4].Info,"D"); Arv[ 4].ExisteNo = 1;
  strcpy(Arv[ 5].Info,"-"); Arv[ 5].ExisteNo = 0;
  strcpy(Arv[ 6].Info,"I"); Arv[ 6].ExisteNo = 1;
  strcpy(Arv[ 7].Info,"-"); Arv[ 7].ExisteNo = 0;
  strcpy(Arv[ 8].Info,"-"); Arv[ 8].ExisteNo = 0;
  strcpy(Arv[ 9].Info,"C"); Arv[ 9].ExisteNo = 1;
  strcpy(Arv[10].Info,"E"); Arv[10].ExisteNo = 1;
  strcpy(Arv[11].Info,"-"); Arv[11].ExisteNo = 0;
  strcpy(Arv[12].Info,"-"); Arv[12].ExisteNo = 0;
  strcpy(Arv[13].Info,"H"); Arv[13].ExisteNo = 1;
  strcpy(Arv[14].Info,"-"); Arv[14].ExisteNo = 0;

  for(int k=15; k < 30; k++) Arv[k].ExisteNo = 0;
}

void main()
{
  monta_arv_exemplo();
//o indice 0 indica a raiz da arvore binaria na representacao sequencial
  printf("\nIn Order: ");
  InOrder(0); 
  printf("\nPre Order: ");
  PreOrder(0);
  printf("\nPos Order: ");
  PosOrder(0);
  printf("\n\n");
}

