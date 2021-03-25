/**********************************************************/
/* LISTA ORDENADA UTILIZANDO ESTRUTURA LIGADA COM ALOCACAO*/
/* DINAMICA E  APONTADORES                                */
/* Exemplo com 2 listas ordenadas                         */
/**********************************************************/

#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define OK   1
#define ERRO 0

struct info
{
  char dado[21];
  struct info *prox;
};
struct info *CabecA, *CabecB;

void Imp_Lista(struct info *Cabec, char *txt)
{
  struct info *p;

  if (Cabec == NULL )
	 cout << txt << "Lista vazia...\n";
  else
  {
	 cout << txt << "Cabec -> ";
	 p = Cabec;
	 while ( p != NULL )
	 {
		cout << p->dado << " -> ";
		p = p->prox;
	 }
	 cout << " fim da lista";
  }
}

int Ins_Lista(struct info *&Cabec, char *Elem)
{
  struct info *p,*ant,*aux;
  p = new struct info;
  if ( !p ) return(ERRO);
  strcpy(p->dado,Elem);
  p->prox = NULL;
  ant = NULL;
  aux = Cabec;
  while (aux != NULL && (strcmp(aux->dado,Elem) < 0) )
  {
    ant = aux;
    aux = aux->prox;
  }
  if ( ant == NULL )
  {
    p->prox = Cabec;
    Cabec = p;
  }
  else
  {
    ant->prox = p;
    p->prox = aux;
  }
  return(OK);
}

int Del_Lista(struct info *&Cabec, char *Elem)
{
  struct info *ant,*aux;

  if ( Cabec == NULL )
  {
	 cout << "\nErro - Removendo de uma Lista Vazia...\n";
	 return(ERRO);
  }
  else
  {
	 ant = NULL;
	 aux = Cabec;
	 while (aux != NULL && (strcmp(aux->dado,Elem) != 0) )
	 {
	   ant = aux;
	   aux = aux->prox;
	 }
	 if ( aux == NULL )
	 {
	   cout << "\nErro - elemento nao existe...";
	   return(ERRO);
	 }
	 else
	 {
		if ( ant == NULL ) Cabec = aux->prox;
		else ant->prox = aux->prox;
	 }
	 delete aux;
  }
  return(OK);
}

int Consulta_Lista(struct info *&Cabec, char *Elem, struct info *&ap)
{
  struct info *aux;

  ap = NULL;
  if ( Cabec == NULL )
  {
	 cout << "\nErro - Consultando uma Lista Vazia...\n";
	 return(ERRO);
  }
  else
  {
	 aux = Cabec;
	 while (aux != NULL && (strcmp(aux->dado,Elem) != 0) ) aux = aux->prox;
	 if ( aux == NULL )
	 {
	   cout << "\nErro - elemento nao existe...";
	   return(ERRO);
	 }
	 else ap = aux;
  }
  return(OK);
}


void main()
{
  char str[21];
  int op=0,ok;
  struct info *apont;
  CabecA = CabecB = NULL;

  while ( op != 8 )
  {
	 cout << "\n\nMenu\n1-Inserir Lista A\n2-Inserir Lista B"
	 << "\n3-Remover Lista A\n4-Remover Lista B"
	 << "\n5-Consulta Lista A\n6-Consulta Lista B"
	 << "\n7-Imprime Listas A e B\n8-Fim\nOpcao: ";
	 cin >> op;
	 if ( op == 1)
	 {
		cout << "\nDigite o elemento a ser inserido na Lista A (ate 20 caracteres): "; cin >> str;
		Ins_Lista(CabecA,str);
	 }
	 if ( op == 2)
	 {
		cout << "\nDigite o elemento a ser inserido na Lista B (ate 20 caracteres): "; cin >> str;
		Ins_Lista(CabecB,str);
	 }
	 else if ( op == 3 )
	 {
		cout << "\nDigite o elemento a ser removido da Lista A (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(CabecA,str);
		if ( ok != ERRO) cout << "\nElemento removido da Lista A: " << str;
	 }
	 else if ( op == 4 )
	 {
		cout << "\nDigite o elemento a ser removido da Lista B (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(CabecB,str);
		if ( ok != ERRO) cout << "\nElemento removido da Lista B: " << str;
	 }
	 else if ( op == 5 )
	 {
		cout << "\nDigite o elemento a ser consultado da Lista A (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(CabecA,str,apont);
		if ( ok != ERRO) cout << "\nElemento consultado da Lista A: " << apont->dado;
	 }
	 else if ( op == 6 )
	 {
		cout << "\nDigite o elemento a ser consultado da Lista B (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(CabecB,str,apont);
		if ( ok != ERRO) cout << "\nElemento consultado da Lista B: " << apont->dado;
	 }
	 else if ( op == 7 )
	 {
		Imp_Lista(CabecA,"\nLista A:\n");
		Imp_Lista(CabecB,"\nLista B:\n");
	 }
  }
}