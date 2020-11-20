/****************************************************************
* Arvore Binária de Busca
* Desenvolvido por: Fábio Gaion
* Observações:
* estrutura exemplo que armazena um dado inteiro
****************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct No
{
  int Info;
  struct No *Dir, *Esq;
};
struct No *Raiz;

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

void InsAbb(struct No **T, int Elem) {
  if ( (*T) == NULL ) {
	 (*T) = (struct No*) malloc(sizeof( struct No));
	 (*T)->Info = Elem;
	 (*T)->Dir = NULL;
	 (*T)->Esq = NULL;
  }
  else
  {
	 if ( Elem > (*T)->Info ) InsAbb(&(*T)->Dir,Elem);
	 else if ( Elem < (*T)->Info ) InsAbb(&(*T)->Esq,Elem);
	 else printf("\nErro - Elemento ja existe na arvore");
  }
}

struct No* BuscaAbb(struct No *T, int Elem) {
  if ( T != NULL ) {
	 if ( Elem < T->Info ) return(BuscaAbb(T->Esq,Elem));
	 else if ( Elem > T->Info ) return(BuscaAbb(T->Dir,Elem));
	 else return(T);
  }
  else return(NULL);
}

void Substitue(struct No **T, struct No **suc) {
  struct No *aux;
  if ( (*suc)->Esq == NULL ){
	  (*T)->Info = (*suc)->Info;
	  aux = (*suc);
	  (*suc) = (*suc)->Dir;
	  free(aux);
  }
  else Substitue(&(*T),&(*suc)->Esq);
}

void DelAbb(struct No **T, int Elem) {
  struct No *aux;
  if ( (*T) != NULL ) {
	 if ( Elem < (*T)->Info ) DelAbb(&(*T)->Esq,Elem);
	 else if ( Elem > (*T)->Info ) DelAbb(&(*T)->Dir,Elem);
	 else {
		if ( (*T)->Esq == NULL ) {   //nó a ser removido não tem filho esquerdo
		  aux = (*T);
		  (*T) = (*T)->Dir;
		  free(aux);
		}
		else if ( (*T)->Dir == NULL ) {  //nó a ser removido não tem filho direito
		  aux = (*T);
		  (*T) = (*T)->Esq;
		  free(aux);
		}
		else Substitue(&(*T),&(*T)->Dir);  //nó a ser removido não tem dois filhos
	 }
  }
  else printf("Delecao - Erro - Elemento nao existe");
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

int main()
{
  int dado, op=0;
  struct No *p;

  Raiz = NULL;   
  while ( op != 8 ) {
    printf("\n\n1 - Inserir\n2 - Consultar\n3 - Deletar\n4 - In Order");
    printf("\n5 - Pre Order\n6 - Pos Order\n7 - GraphViz\n8 - Sair\nOpcao: ");
	  scanf("%d",&op);
	 if (op == 1)	 {
     printf("Insercao - entre com a informacao (num. inteiro): ");
		 scanf("%d",&dado);
		 InsAbb(&Raiz,dado);
	 }
	 else if (op == 2) {
		 printf("Busca - entre com a informacao (num. inteiro): ");
		 scanf("%d",&dado);
		 p = BuscaAbb(Raiz,dado);
		 if ( p ) printf("\nElemento encontrado");
		 else printf("\nElemento não encontrado");
	 }
	 else if (op == 3){
		 printf("Delecao - entre com a informacao (num. inteiro): ");
		 scanf("%d",&dado);
		 DelAbb(&Raiz,dado);
	 }
	 else if (op == 4){
     if ( Raiz == NULL ) printf("\nArvore Vazia");
     else{
       printf("\nPercurso In Order:\n");
		   InOrder(Raiz);     
     }  
	 }
   else if (op == 5){
     if ( Raiz == NULL ) printf("\nArvore Vazia");
     else{
		   printf("\nPercurso Pre Order:\n");
		   PreOrder(Raiz);
     }  
	 }
   else if (op == 6){
     if ( Raiz == NULL ) printf("\nArvore Vazia");
     else{
		   printf("\nPercurso Pos Order:\n");
		   PosOrder(Raiz);
     }  
	 }
   else if ( op == 7) geraGraphviz(Raiz);
  }
  return 1;
}
