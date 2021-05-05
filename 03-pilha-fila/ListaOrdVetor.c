/*********************************************************/
/* LISTA ORDENADA UTILIZANDO ESTRUTURA LIGADA COM VETOR  */
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

struct info Lista[TAM_VET];
int Cabec1, Cabec2, Livre;

void Inic_Vetor(struct info Lista[],int *Livre) {
  int k;
  *Livre = 0;
  for(k=0; k < TAM_VET; k++) Lista[k].prox = k+1;
  Lista[TAM_VET-1].prox = -1;
}

void Inic_Lista(int *Cabec) {
  *Cabec = -1;
}

int Ins_Lista(struct info Lista[], char *Elem, int *Cabec, int *Livre) {
  int ant,aux,atual;
  if ( *Livre == -1 ) {
	 printf("\nInsercao Impossivel - Lista Cheia\n");
	 return(ERRO);
  }
  else {
	 if ( *Cabec == -1 )
	 {
		 *Cabec = *Livre;
		 strcpy(Lista[*Cabec].dado,Elem);
		 *Livre = Lista[*Livre].prox;
		 Lista[*Cabec].prox = -1;
	 }
	 else {
		aux = *Cabec;
		ant  =  -1;
		while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) < 0) ) {
		  ant = aux;
		  aux = Lista[aux].prox;
		}
		atual = *Livre;
		*Livre = Lista[*Livre].prox;
		strcpy(Lista[atual].dado,Elem);
		if (ant == -1) {
		  Lista[atual].prox = *Cabec;
		  *Cabec = atual;
		}
		else Lista[ant].prox  =  atual;
		Lista[atual].prox = aux;
	 }
  }
  return(OK);
}

int Del_Lista(struct info Lista[], char *Elem, int *Cabec, int *Livre)
{
  int ant,aux,atual;
  if ( *Cabec == -1 )   {
	 printf("\nDelecao Impossivel - Lista Vazia\n");
	 return(ERRO);
  }
  else {
	 aux = *Cabec;
	 ant  =  -1;
	 while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) !=0 ) ) {
		 ant = aux;
		 aux = Lista[aux].prox;
	 }
	 if ( aux == -1 ) {
		 printf("\nErro - elemento nao existe...");
		 return(ERRO);
	 }
	 else {
		strcpy(Elem,Lista[aux].dado);
		if ( ant == -1 ) *Cabec = Lista[aux].prox;
		else Lista[ant].prox = Lista[aux].prox;
	 }
	 Lista[aux].prox = *Livre;
	 *Livre = aux;
  }
  return(OK);
}

//Devolve em posicao o elemento encontrado
int Consulta_Lista(struct info Lista[], char *Elem, int *Cabec, int *posicao)
{
  int aux;
  if ( *Cabec == -1 )   {
	 printf("\nConsulta Impossivel - Lista Vazia\n");
	 return(ERRO);
  }
  else {
	 aux = *Cabec;
	 *posicao=-1;
	 while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) !=0 ) ) aux = Lista[aux].prox;
	 if ( aux == -1 ) {
	   printf("\nElemento nao existe...");
	   return(ERRO);
	 }
	 else *posicao = aux;
  }
  return(OK);
}

void Imp_Lista(struct info Lista[],int Cabec, char *txt) {
  int k;
  k = Cabec;  
  printf("%s Cabec-> ",txt);
  while ( k != -1 ) {
	 printf("%s -> ",Lista[k].dado);
	 k = Lista[k].prox;
  }
  printf("fim da lista");
}

void Imp_Vetor()
{
  int k;
  printf("\nind  prox   info\n");
  for(k=0; k < TAM_VET; k++)
	  printf("%d    %d    %s\n",k,Lista[k].prox,Lista[k].dado);
  printf("CabecA = %d  \nCabecB = %d  \nLivre = %d\n",Cabec1,Cabec2,Livre);
}


int main()
{
  char str[21];
  int op=0,pos,ok;

  Inic_Lista(&Cabec1);
  Inic_Lista(&Cabec2);
  Inic_Vetor(Lista,&Livre);
  while ( op != 9 ) {
   printf("\n\nMenu\n1-Inserir Lista A\n2-Inserir Lista B\n3-Remover Lista A\n4-Remover Lista B\n5-Consulta Lista A\n6-Consulta Lista B\
    \n7-Imprime Listas A e B\n8-Imp. Vetor\n9-Fim\nOpcao: ");
    scanf("%d",&op);
	 
	 if ( op == 1) 	 {
		printf("\nDigite o elem a ser inserido na Lista A (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(Lista,str,&Cabec1,&Livre);
	 }
	 if ( op == 2) {
		printf("\nDigite o elem a ser inserido na Lista A (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(Lista,str,&Cabec2,&Livre);
   }
	 else if ( op == 3 ) {
		printf("\nDigite o elem a ser removido da Lista A (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(Lista,str,&Cabec1,&Livre);
		if ( ok != ERRO) printf("\nElemento removido da Lista A: %s",str);
	 }
	 else if ( op == 4 ) {
		printf("\nDigite o elem a ser removido da Lista B (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(Lista,str,&Cabec2,&Livre);
		if ( ok != ERRO) printf("\nElemento removido da Lista B: %s",str);
	 }
	 else if ( op == 5 )	 {
		printf("\nDigite o elem a ser consultado da Lista A (ate 20 caracteres): ");  scanf("%s",str);
		ok = Consulta_Lista(Lista,str,&Cabec1,&pos);
		if ( ok != ERRO) printf("\nElemento consultado Lista A: %s",Lista[pos].dado);
		else printf("Elemento nao existe na Lista A");
	 }
	 else if ( op == 6 ) {
		printf("\nDigite o elem a ser consultado da Lista B (ate 20 caracteres): ");  scanf("%s",str);
		ok = Consulta_Lista(Lista,str,&Cabec2,&pos);
		if ( ok != ERRO) printf("\nElemento consultado Lista B: %s",Lista[pos].dado);
		else printf("Elemento nao existe na Lista B");
	 }
	 else if ( op == 7 ) {
		Imp_Lista(Lista,Cabec1,"\nLista A:\n");
		Imp_Lista(Lista,Cabec2,"\nLista B:\n");
	 }
	 else if ( op == 8 ) Imp_Vetor();
  }
}
