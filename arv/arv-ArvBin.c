/****************************************************************
* Arvore Binária
* Desenvolvido por: Fábio Gaion
* Observações:
* O programa abaixo monta a seguinte arvore binaria
     5
   /   \
  3     7
 / \   / \
2  4  6   8
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct No
{
  int Info;
  struct No *Dir, *Esq, *Pai;
};

struct No *Raiz;

struct No *CriaArv(int x){
  struct No *p;
  p = (struct No*) malloc(sizeof (struct No));
  p->Info = x;
  p->Esq = p->Dir = p->Pai = NULL;
  return(p);
}

void InsEsq(struct No *p, int x){
  if ( p == NULL) printf("\nErro: Arvore Vazia");
  else if (p->Esq != NULL ) printf("\nErro: insercao incorreta");
  else {
    p->Esq = CriaArv(x);
    p->Esq->Pai = p;
  }
}

void InsDir(struct No *p, int x){
  if ( p == NULL) printf("\nErro: Arvore Vazia");
  else if (p->Dir != NULL ) printf("\nErro: insercao incorreta");
  else {
    p->Dir = CriaArv(x);
    p->Dir->Pai = p;
  }
}

int Info(struct No *p){
  if (p != NULL ) return(p->Info);
  return(-1);
}

struct No* FilhoEsq(struct No *p){
  if (p != NULL ) return(p->Esq);
  return(NULL);
}

struct No* FilhoDir(struct No *p) {
  if (p != NULL ) return(p->Dir);
  return(NULL);
}

struct No* Pai(struct No *p) {
  if (p != NULL ) return(p->Pai);
  return(NULL);
}

struct No* Irmao(struct No *p) {
  struct No *q;
  if (p != NULL ) {
	 q = p->Pai;
	 if (q == NULL ) return NULL; //No raiz não tem irmão
	 if ( q->Esq == p ) return(q->Dir);
	 else return(q->Esq);
  }
  return(NULL);
}

void InOrder(struct No *T) {
  if ( T != NULL ) {
	 InOrder(T->Esq);
	 printf("%d ",T->Info);
	 InOrder(T->Dir);
  }
}

void PreOrder(struct No *T) {
  if ( T != NULL ) {
	 printf("%d ",T->Info);
	 PreOrder(T->Esq);
	 PreOrder(T->Dir);
  }
}

void PosOrder(struct No *T) {
  if ( T != NULL ) {
	 PosOrder(T->Esq);
	 PosOrder(T->Dir);
	 printf("%d ",T->Info);
  }
}

void geraGraphvizPreOrdem(struct No *T) {
  if (T != NULL) {
    if (T->Esq)
      printf("\n%d->%d",T->Info,T->Esq->Info);
    if (T->Dir)
      printf("\n%d->%d",T->Info,T->Dir->Info);
    geraGraphvizPreOrdem(T->Esq);
    geraGraphvizPreOrdem(T->Dir);
  }  
}      

void geraGraphviz(struct No *T){
  if ( T == NULL ) printf("\nArvore Vazia");
  else {
    printf("\nCopiar para http://www.webgraphviz.com/\ndigraph G {");
    geraGraphvizPreOrdem(T);
    printf("}\n");
  }
}    
    
void main() {
  struct No *pe,*pd;

  Raiz = CriaArv(5);
  InsEsq(Raiz,3);
  InsDir(Raiz,7);
  pe = FilhoEsq(Raiz);
  pd = FilhoDir(Raiz);
  InsEsq(pe,2);
  InsDir(pe,4);
  InsEsq(pd,6);
  InsDir(pd,8);
  printf("\nIn Order: ");
  InOrder(Raiz);
  printf("\nPre Order: ");
  PreOrder(Raiz);
  printf("\nPos Order: ");
  PosOrder(Raiz);
  
  printf("\nGraphViz:\n");
  geraGraphviz(Raiz);
}
