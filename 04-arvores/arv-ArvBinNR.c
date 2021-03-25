/*******************************************************************
* Arvore Binária não recursiva
* Desenvolvido por: Fábio Gaion
* Observações:
* programa incompleto - falta algumas implementações
* O programa abaixo monta a seguinte arvore binaria
     F
   /   \
  B      G
 /  \      \
A    D      I
    / \    /
   C   E  H
*******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX 100

struct No {
  char Info[10];
  struct No *Dir, *Esq;
};
struct No *Raiz;

struct Pilha {
  int Topo;
  struct No *apontNo[TAM_MAX];
};

void InicPilha(struct Pilha *s) {
  s->Topo = -1;
}

void ImpPilha(char *msg,struct Pilha *s) {
  char ch[10];
  printf("\n%s",msg);
  if ( s-> Topo == -1 ) printf("\nPilha Vazia");
  else {    
    for (int i=s->Topo; i > -1; i--)
      printf("\nInd: %d  Valor: %s",i,s->apontNo[i]->Info);
  }
  printf("\nDigite algo para continuar: ");
  scanf("%s",&ch);
}  
  

int PilhaVazia(struct Pilha *s) {
  if ( s->Topo == -1 ) return(1);
  return(0);
}

void Empilha(struct Pilha *s, struct No *p) {
  if ( s->Topo < TAM_MAX ) {
	 s->Topo++;
	 s->apontNo[s->Topo] = p;
  }
}

struct No* Desempilha(struct Pilha *s){
  if ( s->Topo > -1 ) {
    s->Topo--; 
	  return(s->apontNo[s->Topo]);
  }
  else return(NULL);
}

struct No * RecTopo(struct Pilha *s){
  if ( s->Topo > -1 ) return(s->apontNo[s->Topo]);
  else return(NULL);
}
/*
void InOrderNR(struct No *T){
  struct Pilha s;
  struct No *p;

  InicPilha(&s);
  ImpPilha(&s);
  p = T;
  do {
	 while ( p != NULL ) {
		Empilha(&s,p);
    ImpPilha(&s);
		p = p->Esq;
	 }
	 if ( !PilhaVazia(&s) ) {
		p = Desempilha(&s);
    ImpPilha(&s);
		printf("%s ",p->Info);
		p = p->Dir;
	 }
  } while ( !PilhaVazia(&s) || p != NULL );
}

void PreOrderNR(struct No *T){
  struct Pilha s;
  struct No *p;

  InicPilha(&s);
  ImpPilha("Inicio",&s);
  p = T;
  do {
	 while ( p != NULL ) {
		printf("%s ",p->Info);
		Empilha(&s,p);
    ImpPilha("Empilha",&s);
		p = p->Esq;
	 }
	 if ( !PilhaVazia(&s) ) {
		p=Desempilha(&s);
    ImpPilha("Desempilha",&s);
		p = p->Dir;
	 }
  } while ( !PilhaVazia(&s) || p != NULL );
}


procedimento incompleto
void PosOrderNR(struct No *T)
{
  struct Pilha s;
  struct No *p;

  InicPilha(s);
  p = T;
  do
  {
	 while ( p != NULL )
	 {
		Empilha(s,p);
		p = p->Esq;
	 }
	 if ( !PilhaVazia(s) )
	 {
		Desempilha(s,p);
		cout << p->Info << " ";
		p = p->Dir;
	 }
  } while ( !PilhaVazia(s) || p != NULL );
}
*/

void InOrder(struct No *T) {
  if ( T != NULL ) {
	 InOrder(T->Esq);
	 printf("%s ",T->Info);
	 InOrder(T->Dir);
  }
}

void PreOrder(struct No *T) {
  if ( T != NULL ) {
	 printf("%s ",T->Info);
	 PreOrder(T->Esq);
	 PreOrder(T->Dir);
  }
}

void PosOrder(struct No *T) {
  if ( T != NULL ) {
	 PosOrder(T->Esq);
	 PosOrder(T->Dir);
	 printf("%s ",T->Info);
  }
}

void monta_arv_exemplo()
{
  struct No *p,*pe,*pd;

  Raiz = p = (struct No*) malloc( sizeof(struct No));
  strcpy(Raiz->Info,"F"); Raiz->Esq=NULL; Raiz->Dir=NULL;
  pe = (struct No*) malloc( sizeof(struct No));
  strcpy(pe->Info,"B"); pe->Esq=NULL; pe->Dir=NULL;
  pd = (struct No*) malloc( sizeof(struct No));
  strcpy(pd->Info,"G"); pd->Esq=NULL; pd->Dir=NULL;
  p->Esq = pe; p->Dir = pd;

  p = Raiz->Esq;  //p aponta p/ o elemento B da arvore
  pe = (struct No*) malloc( sizeof(struct No));
  strcpy(pe->Info,"A"); pe->Esq=NULL; pe->Dir=NULL;
  pd = (struct No*) malloc( sizeof(struct No));
  strcpy(pd->Info,"D"); pd->Esq=NULL; pd->Dir=NULL;
  p->Esq = pe; p->Dir = pd;

  p = pd; //p aponta p/ o elemento D da arvore
  pe = (struct No*) malloc( sizeof(struct No));
  strcpy(pe->Info,"C"); pe->Esq=NULL; pe->Dir=NULL;
  pd = (struct No*) malloc( sizeof(struct No));
  strcpy(pd->Info,"E"); pd->Esq=NULL; pd->Dir=NULL;
  p->Esq = pe; p->Dir = pd;

  p = Raiz->Dir;  //p aponta p/ o elemento G da arvore
  pd = (struct No*) malloc( sizeof(struct No));
  strcpy(pd->Info,"I"); pd->Esq=NULL; pd->Dir=NULL;
  p->Dir = pd;

  p = pd;  //p aponta p/ o elemento I da arvore
  pe = (struct No*) malloc( sizeof(struct No));
  strcpy(pe->Info,"H"); pe->Esq=NULL; pe->Dir=NULL;
  p->Esq = pe;
}

void main()
{
  Raiz = NULL;
  monta_arv_exemplo();
  printf("\nIn Ordem Recursiva: ");
  InOrder(Raiz);   //funcao recursiva
  printf("\nIn Ordem NR: ");
  //InOrderNR(Raiz); //funcao nao recursiva
  printf("\nPre Ordem Recursiva: ");
  PreOrder(Raiz); //funcao recursiva
  printf("\nPre Ordem Nao Recursiva: ");
  //PreOrderNR(Raiz); //funcao nao recursiva
  printf("\nPos Ordem Recursiva: ");
  PosOrder(Raiz); //funcao recursiva
  //PosOrderNR(Raiz); cout << endl;//funcao nao recursiva
}
