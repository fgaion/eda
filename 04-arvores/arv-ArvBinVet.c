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
			  00 01 02 03 04 05 06 07 08 09 10 11
Info        E  G  H  D  F  A -- --  B  C  I --
Filho Esq  -1 -1 -1  9  8 -1 11  6  5 -1  2 -1
Filho Dir  -1 10 -1  0  1 -1 -- --  3 -1 -1 --

				Raiz = 4 e Livre = 7
*******************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_NO 20

struct No
{
  char Info[10];
  int Dir,Esq;
};
struct No Arv[MAX_NO];

int Raiz, Livre;

void InOrder(int T){
  if ( T != -1 ){
	 InOrder(Arv[T].Esq);
	 printf("%s ",Arv[T].Info);
	 InOrder(Arv[T].Dir);
  }
}

void PreOrder(int T){
  if ( T != -1 ){
	 printf("%s ",Arv[T].Info);
	 PreOrder(Arv[T].Esq);
	 PreOrder(Arv[T].Dir);
  }
}

void PosOrder(int T){
  if ( T != -1 ){
	 PosOrder(Arv[T].Esq);
	 PosOrder(Arv[T].Dir);
	 printf("%s ",Arv[T].Info);
  }
}

void monta_arv_exemplo(){
  Raiz = 4;
  Livre = 7;

  strcpy(Arv[0].Info,"E");  Arv[0].Esq=-1; Arv[0].Dir=-1;
  strcpy(Arv[1].Info,"G");  Arv[1].Esq=-1; Arv[1].Dir=10;
  strcpy(Arv[2].Info,"H");  Arv[2].Esq=-1; Arv[2].Dir=-1;
  strcpy(Arv[3].Info,"D");  Arv[3].Esq=9;  Arv[3].Dir=0;
  strcpy(Arv[4].Info,"F");  Arv[4].Esq=8;  Arv[4].Dir= 1;
  strcpy(Arv[5].Info,"A");  Arv[5].Esq=-1; Arv[5].Dir=-1;
  strcpy(Arv[6].Info,"--"); Arv[6].Esq=11; Arv[6].Dir=-1;
  strcpy(Arv[7].Info,"--"); Arv[7].Esq=6;  Arv[7].Dir=-1;
  strcpy(Arv[8].Info,"B");  Arv[8].Esq=5;  Arv[8].Dir=3;
  strcpy(Arv[9].Info,"C");  Arv[9].Esq=-1; Arv[9].Dir=-1;
  strcpy(Arv[10].Info,"I"); Arv[10].Esq=2; Arv[10].Dir=-1;
  strcpy(Arv[11].Info,"--");Arv[11].Esq=-1;Arv[11].Dir=-1;
}

void main()
{
  Raiz = -1;
  monta_arv_exemplo();
  printf("\nIn Order: ");
  InOrder(Raiz); 
  printf("\nPre Order: ");
  PreOrder(Raiz);
  printf("\nPos Order: ");
  PosOrder(Raiz);
  printf("\n\n");
}
