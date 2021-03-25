/****************************************************************
* Arvore Binária de Busca - exemplo para estrutura com RA, nome e curso
* Desenvolvido por: Fábio Gaion
* Observações:
* Programa com estrutura da linguagem C porém usando a E/S do c++
****************************************************************/
#include <iostream>
#include <string.h>

using namespace std;

struct Elemento {
  int RA;
  char  Nome[40],Curso[20];
};

struct No {
  struct Elemento Info;
  struct No *Dir, *Esq;
};
struct No *Raiz;

void InOrder(struct No *T) {
  if ( T != NULL ) {
	 InOrder(T->Esq);
	 cout << "\nRA: " << T->Info.RA << " Nome: " << T->Info.Nome
			<< " Curso: " << T->Info.Curso;
	 InOrder(T->Dir);
  }
}

void InsAbb(struct No *&T, struct Elemento Elem) {
  if ( T == NULL ) {
	 T = (struct No*) new struct No;
	 T->Info.RA = Elem.RA;
	 strcpy(T->Info.Nome,Elem.Nome);
	 strcpy(T->Info.Curso,Elem.Curso);
	 T->Dir = NULL;
	 T->Esq = NULL;
  }
  else {
	 if ( Elem.RA > T->Info.RA ) InsAbb(T->Dir,Elem);
	 else if ( Elem.RA < T->Info.RA ) InsAbb(T->Esq,Elem);
	 else cout << "\nErro - Elemento já existe na árvore";
  }
}

struct No* BuscaAbb(struct No *T, struct Elemento Elem) {
  if ( T != NULL ) {
	 if ( Elem.RA < T->Info.RA ) return(BuscaAbb(T->Esq,Elem));
	 else if ( Elem.RA > T->Info.RA ) return(BuscaAbb(T->Dir,Elem));
	 else return(T);
  }
  else return(NULL);
}

void Substitue(struct No *&T, struct No *&suc, struct Elemento &Elem) {
  No *aux;
  if ( suc->Esq == NULL ) {
	 Elem.RA = T->Info.RA;
	 T->Info.RA = suc->Info.RA;
	 strcpy(Elem.Nome,T->Info.Nome);
	 strcpy(T->Info.Nome,suc->Info.Nome);
	 strcpy(Elem.Curso,T->Info.Curso);
	 strcpy(T->Info.Curso,suc->Info.Curso);
	 aux = suc;
	 suc = suc->Dir;
	 delete aux;
  }
  else Substitue(T,suc->Esq,Elem);
}

int DelAbb(struct No *&T, int xRA, struct Elemento &Elem) {
  No *aux;
  if ( T != NULL ) {
	 if ( xRA < T->Info.RA ) return(DelAbb(T->Esq,xRA,Elem));
	 else if ( xRA > T->Info.RA ) return(DelAbb(T->Dir,xRA,Elem));
	 else {
		if ( T->Esq == NULL ) {
		  aux = T;
		  T = T->Dir;
		  Elem.RA = aux->Info.RA;
		  strcpy(Elem.Nome,aux->Info.Nome);
		  strcpy(Elem.Curso,aux->Info.Curso);
		  delete aux;
		}
		else if ( T->Dir == NULL ) {
		  aux = T;
		  T = T->Esq;
		  Elem.RA = aux->Info.RA;
		  strcpy(Elem.Nome,aux->Info.Nome);
		  strcpy(Elem.Curso,aux->Info.Curso);
		  delete aux;
		}
		else Substitue(T,T->Dir,Elem);
		return(1);
	 }
  }
  else cout << "Erro - Elemento não existe";
  return(0);
}

int main() {
  int op=1,xRA;
  struct No *p;
  struct Elemento dado;

  Raiz = NULL;
  while ( op != 0 ) {
	 cout << "\n1 - Inserir\n2 - Consultar\n3 - Deletar"
			<< "\n4 - Percorrer In Order\n0 - Sair\nOpcao: ";
	 cin >> op;
	 if (op == 1) {
		cout << "Inserção - entre com as informação: ";
		cout << "\nRA   : "; cin >> dado.RA;
		cout << "Nome : "; cin >> dado.Nome;
		cout << "Curso: "; cin >> dado.Curso;
		InsAbb(Raiz,dado);
	 }
	 else if (op == 2) {
		cout << "Busca - entre com a informação: ";
		cout << "\nRA   : "; cin >> dado.RA;
		p = BuscaAbb(Raiz,dado);
		if ( p )
		{
		  cout << "\nElemento encontrado"
				 << "\nRA: " << p->Info.RA << "\nNome: " << p->Info.Nome
				 << "\nCurso: " << p->Info.Curso << endl;
		}
		else cout << "\nElemento não encontrado";
	 }
	 else if (op == 3) {
		cout << "Deleção - entre com a informação: ";
		cout << "\nRA   : "; cin >> xRA;
		if ( DelAbb(Raiz,xRA,dado) )
		{
		  cout << "\nElemento removido"
				 << "\nRA: " << dado.RA << "\nNome: " << dado.Nome
				 << "\nCurso: " << dado.Curso << endl;
		}
	 }
	 else if (op == 4) {
		cout << "\nPercurso In Order:\n";
		InOrder(Raiz); cout << "\n\n";
	 }
  }
  return(1);
}
