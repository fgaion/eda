/**********************************************************/
/* LISTA ORDENADA DUPLAMENTE LIGADA UTILIZANDO COM ALOCA- */
/* CAO DINAMICA E  APONTADORES                            */
/* Exemplo com 2 listas duplamente ligadas e ordenadas    */
/**********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OK   1
#define ERRO 0

struct info {
  char dado[21];
  struct info *ant,*prox;
};

struct info *CabecA,*FimA,*CabecB,*FimB;

void Imp_Lista(struct info *Cabec, struct info *Fim, char *txt) {
  struct info *p;

  if (Cabec == NULL ) printf("%s - Lista vazia...\n",txt);
  else   {
	 printf("%s: Cabec -> ",txt);	
	 p = Cabec;
	 while ( p != NULL ) {
		printf("%s -> ",p->dado);
		p = p->prox;
	 }
	 printf(" fim da lista\nFim -> ");
	 p = Fim;
	 while ( p != NULL ) {
		printf("%s -> ",p->dado);
		p = p->ant;
	 }
	 printf(" inicio da lista");
  }
}

int Ins_Lista(struct info **Cabec, struct info **Fim, char *Elem)
{
  struct info *p,*aux;
  p = (struct info*) malloc(sizeof(struct info));
  
  if ( !p ) return(ERRO);
  strcpy(p->dado,Elem);
  p->prox = p->ant = NULL;
  if ( *Cabec == NULL ) *Cabec = *Fim = p;
  else {
	 aux = *Cabec;
	 while (aux != NULL && (strcmp(aux->dado,Elem) < 0) ) aux = aux->prox;
	 if ( *Cabec == aux ) {
		p->prox = aux;
		aux->ant = p;
		*Cabec = p;
	 }
	 else if (aux == NULL) {
		p->ant = *Fim;
		(*Fim)->prox = p;
		*Fim = p;
	 }
	 else {
		aux->ant->prox  =  p;
		p->ant = aux->ant;
		p->prox = aux;
		aux->ant = p;
	 }
  }
  return(OK);
}

int Del_Lista(struct info **Cabec, struct info **Fim, char *Elem)
{
  struct info *aux;

  if ( *Cabec == NULL ) {
	 printf("\nErro - Removendo de uma Lista Vazia...\n");
	 return(ERRO);
  }
  else  {
	 aux = *Cabec;
	 while ( aux != NULL && (strcmp(aux->dado,Elem) !=0 ) ) aux = aux->prox;

	 if ( aux == NULL ) {
		printf("\nErro - elemento nao existe...");
		return(ERRO);
	 }
	 else {
		strcpy(Elem,aux->dado);
		if (aux == *Cabec) {
		  *Cabec = aux->prox;
		  if (*Cabec != NULL) (*Cabec)->ant = NULL;
		  else *Cabec = *Fim = NULL;
		}
		else {
		  if (aux == *Fim) {
			 aux->ant->prox = NULL;
			 *Fim = aux->ant;
		  }
		  else {
			 aux->ant->prox = aux->prox;
			 aux->prox->ant = aux->ant;
		  }
		}
		free(aux);
	 }
  }
  return(OK);
}

int Consulta_Lista(struct info **Cabec, char *Elem, struct info **ap)
{
  struct info *aux;

  *ap = NULL;
  if ( *Cabec == NULL ) {
	 printf("\nErro - Consultando uma Lista Vazia...\n");
	 return(ERRO);
  }
  else {
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


void main()
{
  char str[21];
  int op=0,ok;
  struct info *apont;
  CabecA = FimA = CabecB = FimB = NULL;
  
  while ( op != 8 )  {
    printf("\n\nMenu\n1-Inserir Lista A\n2-Inserir Lista B\n3-Remover Lista A\n4-Remover Lista B\n5-Consultar Lista A\n6-Consultar Lista B\
    \n7-Imprime Listas A e B\n8-Fim\nOpcao: ");
    scanf("%d",&op);    

	 if ( op == 1)  {
		printf("\nDigite o elem a ser inserido na Lista A (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(&CabecA,&FimA,str);
	 }
	 if ( op == 2) {
		printf("\nDigite o elem a ser inserido na Lista B (ate 20 caracteres): "); scanf("%s",str);
		Ins_Lista(&CabecB,&FimB,str);
	 }
	 else if ( op == 3 ) {
		printf("\nDigite o elem a ser removido da Lista A (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(&CabecA,&FimA,str);
		if ( ok != ERRO) printf("\nElemento removido da Lista A: %s",str);
	 }
	 else if ( op == 4 ){
		printf("\nDigite o elem a ser removido da Lista B (ate 20 caracteres): ");  scanf("%s",str);
		ok = Del_Lista(&CabecB,&FimB,str);
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
		Imp_Lista(CabecA,FimA,"\nLista A:\n");
		Imp_Lista(CabecB,FimB,"\nLista B:\n");
	 }
  }
}  

  
