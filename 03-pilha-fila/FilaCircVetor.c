/*********************************************************/
/* FILA CIRCULAR UTILIZANDO ESTRUTURA LIGADA COM VETOR   */
/* E APONTADOR                                           */
/* Exemplo com 2 listas ordenadas                        */
/*********************************************************/

#include <stdio.h>
#include <string.h>

#define OK   1
#define ERRO 0
#define TAM_VET 10

struct info {
  char dado[21];
  int  prox;
};

struct info F[TAM_VET];
int fimA, fimB, Livre;


void Inic_Vetor(struct info F[],int *Livre){
  int k;
  *Livre = 0;
  for(k=0; k < TAM_VET; k++) F[k].prox = k+1;
  F[TAM_VET-1].prox = -1;
}

void Inic_Fila(int *fim) {
  *fim = -1;
}

int Ins_Fila(struct info F[], char *Elem, int *fim, int *Livre) {
  int atual;
  if ( *Livre == -1 ){
	 printf("\nInsercao Impossivel - Fila Cheia\n");
	 return(ERRO);
  }
  else {
	 atual = *Livre;
	 *Livre = F[*Livre].prox;
	 strcpy(F[atual].dado,Elem);
	 if ( *fim == -1 ) F[atual].prox = atual;
	 else	 {
		F[atual].prox = F[*fim].prox;
		F[*fim].prox = atual;
	 }
	 *fim = atual;
  }
  return(OK);
}

int Del_Fila(struct info F[], char *Elem, int *fim, int *Livre) {
  int atual;
  if ( *fim == -1 ) {
	 printf("\nDelecao Impossivel - Fila Vazia\n");
	 return(ERRO);
  }
  else   {
	 atual = F[*fim].prox;
	 strcpy(Elem,F[atual].dado);
	 if ( atual == *fim ) *fim = -1;
	 else F[*fim].prox = F[atual].prox;
	 F[atual].prox = *Livre;
	 *Livre = atual;
  }
  return(OK);
}

int Rec_Frente(struct info F[], char *Elem, int fim) {
  if ( fim == -1 ) {
	 printf("\nRecuperar elemento da frente Impossivel - Fila Circular Vazia\n");
	 return(ERRO);
  }
  else strcpy(Elem,F[F[fim].prox].dado);
  return(OK);
}

void Imp_Fila(struct info F[],int fim, char *txt) {
  int k;
  k = F[fim].prox;
  printf("%s  frente -> ",txt);
  while ( k != fim ) {
	 printf("%s -> ",F[k].dado);
	 k = F[k].prox;
  }
  printf("%s -> ",F[k].dado);
  printf("fim da fila");
}


void Imp_Vetor() {
  int k;
  printf("\nind  prox   info\n");
  for(k=0; k < TAM_VET; k++)
    printf("%d    %d    %s\n", k,F[k].prox,F[k].dado);
  printf("fimA = %d\nfimB = %d\nLivre = %d\n",fimA,fimB,Livre);  
}


void main()
{
  char str[21];
  int op=0,ok;

  Inic_Fila(&fimA);
  Inic_Fila(&fimB);
  Inic_Vetor(F,&Livre);
  while ( op != 9 )
  {
    printf("\n\nMenu\n1-Inserir Fila A\n2-Inserir Fila B\n3-Remover Fila A\n4-Remover Fila B\n5-Mostra frente Fila A\n6-Mostra frente Fila B\
    \n7-Imprime Filas A e B\n8-Imp. Vetor\n9-Fim\nOpcao: ");
    scanf("%d",&op);
    if ( op == 1)  {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(F,str,&fimA,&Livre);
    }
    if ( op == 2) {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(F,str,&fimB,&Livre);
    }
    else if ( op == 3 ) {
		ok = Del_Fila(F,str,&fimA,&Livre);
		if ( ok != ERRO) printf("\nElemento removido da Fila A: %s",str);
	 }
	 else if ( op == 4 ) {
		ok = Del_Fila(F,str,&fimB,&Livre);
		if ( ok != ERRO) printf("\nElemento removido da Fila B: %s",str);
	 }
	 else if ( op == 5 ) {
		ok = Rec_Frente(F,str,fimA);
		if ( ok != ERRO) printf("\nElemento do inicio da Fila A: %s",str);
	 }
	 else if ( op == 6 )  {
		ok = Rec_Frente(F,str,fimB);
		if ( ok != ERRO) printf("\nElemento do inicio da Fila B: %s",str);
	 }
	 else if ( op == 7 ) {
		Imp_Fila(F,fimA,"\nFila A:\n");
		Imp_Fila(F,fimB,"\nFila B:\n");
	 }
	 else if ( op == 8 ) Imp_Vetor();
  }
}

