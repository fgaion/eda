/**********************************************************/
/* LISTA ORDENADA UTILIZANDO ESTRUTURA LIGADA COM ALOCACAO*/
/* DINAMICA E  APONTADORES                                */
/* Exemplo com 2 listas ordenadas                         */
/**********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK   1
#define ERRO 0

struct info {
  char dado[21];
  struct info *prox;
};
struct info *CabecA, *CabecB;

void Imp_Lista(struct info *Cabec, char *txt) {
  struct info *p;

  if (Cabec == NULL ) printf("%s - Lista vazia...\n",txt);	 
  else   {
   printf("%s: Cabec -> ",txt);	 
	 p = Cabec;
	 while ( p != NULL ) 	 {
    printf("%s -> ",p->dado);		
		p = p->prox;
	 }
	 printf(" fim da lista");
  }
}

int Ins_Lista(struct info **Cabec, char *Elem) {
  struct info *p,*ant,*aux;
  p = (struct info*) malloc(sizeof(struct info));
  
  if ( !p ) return(ERRO);
  strcpy(p->dado,Elem);
  p->prox = NULL;
  ant = NULL;
  aux = *Cabec;
  while (aux != NULL && (strcmp(aux->dado,Elem) < 0) ) {
    ant = aux;
    aux = aux->prox;
  }
  if ( ant == NULL ) {
    p->prox = *Cabec;
    *Cabec = p;
  }
  else {
    ant->prox = p;
    p->prox = aux;
  }
  return(OK);
}

int Del_Lista(struct info **Cabec, char *Elem)
{
  struct info *ant,*aux;

  if ( *Cabec == NULL )  {
	 printf("\nErro - Removendo de uma Lista Vazia...\n");
	 return(ERRO);
  }
  else  {
	 ant = NULL;
	 aux = *Cabec;
	 while (aux != NULL && (strcmp(aux->dado,Elem) != 0) ) {
	   ant = aux;
	   aux = aux->prox;
	 }
	 if ( aux == NULL ) {
	   printf("\nErro - elemento nao existe...");
	   return(ERRO);
	 }
	 else 	 {
		if ( ant == NULL ) *Cabec = aux->prox;
		else ant->prox = aux->prox;
	 }
	 free(aux);
  }
  return(OK);
}

int Consulta_Lista(struct info **Cabec, char *Elem, struct info **ap)
{
  struct info *aux;

  *ap = NULL;
  if ( Cabec == NULL )  {
	 printf("\nErro - Consultando uma Lista Vazia...\n");
	 return(ERRO);
  }
  else  {
	 aux = *Cabec;
	 while (aux != NULL && (strcmp(aux->dado,Elem) != 0) ) aux = aux->prox;
	 if ( aux == NULL ) {
	   printf("\nErro - elemento nao existe...");
	   return(ERRO);
	 }
	 else *ap = aux;
  }
  return(OK);
}


int main() {
  char str[21];
  int op=0,ok;
  struct info *apont;
  CabecA = CabecB = NULL;

  while ( op != 8 )  {
    printf("\n\nMenu\n1-Inserir Lista A\n2-Inserir Lista B\n3-Remover Lista A\n4-Remover Lista B\n5-Consultar Lista A\n6-Consultar Lista B\
    \n7-Imprime Listas A e B\n8-Fim\nOpcao: ");
    scanf("%d",&op);    

	 if ( op == 1)  {
		printf("\nDigite o elem a ser inserido na Lista A (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(&CabecA,str);
	 }
	 if ( op == 2) {
		printf("\nDigite o elem a ser inserido na Lista B (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(&CabecB,str);
	 }
	 else if ( op == 3 ) {
		printf("\nDigite o elem a ser removido da Lista A (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(&CabecA,str);
		if ( ok != ERRO) printf("\nElemento removido da Lista A: %s",str);
	 }
	 else if ( op == 4 ){
		printf("\nDigite o elem a ser removido da Lista B (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(&CabecB,str);
		if ( ok != ERRO) printf("\nElemento removido da Lista B: %s",str);
	 }
	 else if ( op == 5 ) 	 {
		printf("\nDigite o elem a ser consultado da Lista A (ate 20 caracteres): ");  scanf("%s",str);
		ok = Consulta_Lista(&CabecA,str,&apont);
    if ( ok != ERRO) printf("\nElemento consultado Lista A: %s",apont->dado);
		else printf("Elemento nao existe na Lista A");		
	 }
	 else if ( op == 6 )
	 {
		printf("\nDigite o elem a ser consultado da Lista B (ate 20 caracteres): ");  scanf("%s",str);
		ok = Consulta_Lista(&CabecB,str,&apont);
    if ( ok != ERRO) printf("\nElemento consultado Lista B: %s",apont->dado);
		else printf("Elemento nao existe na Lista A");		

	 }
	 else if ( op == 7 )
	 {
		Imp_Lista(CabecA,"\nLista A:\n");
		Imp_Lista(CabecB,"\nLista B:\n");
	 }
  }
}
