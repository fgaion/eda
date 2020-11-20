/****************************************************************
* Arvore Binária de Busca
* Desenvolvido por: Fábio Gaion
* Observações:
* estrutura exemplo que armazena um dado inteiro
* utiliza a estrutura da linguagem C e a E/S do C++
****************************************************************/

#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
using namespace std;

struct No
{
  int Info;
  struct No *Dir, *Esq;
};
struct No *Raiz;

void InOrder(struct No *T) {
  if ( T != NULL )
  {
	  InOrder(T->Esq);
	  cout << T->Info << " ";
	  InOrder(T->Dir);
  }
}

void PreOrder(struct No *T) {
  if ( T != NULL ){
    cout << T->Info << " ";
	  PreOrder(T->Esq);
	  PreOrder(T->Dir);
  }
}

void PosOrder(struct No *T) {
  if ( T != NULL ){
	  PosOrder(T->Esq);
    cout << T->Info << " ";
	  PosOrder(T->Dir);
  }
}

void InsAbb(struct No *&T, int Elem){
  if ( T == NULL ){
	  T = (struct No*) new struct No;
	  T->Info = Elem;
	  T->Dir = NULL;
	  T->Esq = NULL;
  }
  else{
	  if ( Elem > T->Info ) InsAbb(T->Dir,Elem);
	  else if ( Elem < T->Info ) InsAbb(T->Esq,Elem);
	  else cout << "\nErro - Elemento ja existe na arvore";
  }
}

struct No* BuscaAbb(struct No *T, int Elem){
  if ( T != NULL ){
	 if ( Elem < T->Info ) return(BuscaAbb(T->Esq,Elem));
	 else if ( Elem > T->Info ) return(BuscaAbb(T->Dir,Elem));
	 else return(T);
  }
  else return(NULL);
}

void Substitue(struct No *&T, struct No *&suc) {
  No *aux;
  if ( suc->Esq == NULL ){
	  T->Info = suc->Info;
	  aux = suc;
	  suc = suc->Dir;
	  delete aux;
  }
  else Substitue(T,suc->Esq);
}

void DelAbb(struct No *&T, int Elem) {
  No *aux;
  if ( T != NULL )
  {
	  if ( Elem < T->Info ) DelAbb(T->Esq,Elem);
	  else if ( Elem > T->Info ) DelAbb(T->Dir,Elem);
	  else{
		  if ( T->Esq == NULL ){
		    aux = T;
		    T = T->Dir;
		    delete aux;
		  }
		 else if ( T->Dir == NULL ) {
		   aux = T;
		   T = T->Esq;
		   delete aux;
		 }
		 else Substitue(T,T->Dir);
	 }
  }
  else cout << "Erro - Elemento nao existe";
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
  while ( op != 8 ){
	 cout << "\n1 - Inserir\n2 - Consultar\n3 - Deletar"
			<< "\n4 - In Order\n5 - Pre Order\n6 - Pos Order"
      << "\n7 - GraphViz\n8 - Sair\nOpcao: ";
	 cin >> op;
	 if (op == 1){
		 cout << "Insercao - entre com a informaao (n. inteiro): ";
		 cin >> dado;
		 InsAbb(Raiz,dado);
	 }
	 else if (op == 2){
		 cout << "Busca - entre com a informacao (n. inteiro): ";
		 cin >> dado;
		 p = BuscaAbb(Raiz,dado);
		 if ( p ) cout << "\nElemento encontrado";
		 else cout << "\nElemento não encontrado";
	 }
	 else if (op == 3){
		 cout << "Delecao - entre com a informacao (n. inteiro): ";
		 cin >> dado;
		 DelAbb(Raiz,dado);
	 }
	 else if (op == 4){
		 cout << "\nPercurso In Order:\n";
		 InOrder(Raiz); cout << "\n\n";
	 }
   else if (op == 5){
		 cout << "\nPercurso Pre Order:\n";
		 PreOrder(Raiz); cout << "\n\n";
	 }
   else if (op == 6){
		 cout << "\nPercurso Pos Order:\n";
		 PosOrder(Raiz); cout << "\n\n";
	 }
   else if (op == 7) geraGraphviz(Raiz);
  }
  return(1);
}
