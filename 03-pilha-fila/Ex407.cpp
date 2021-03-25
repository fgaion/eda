/*********************************************************/
/* LISTA ORDENADA UTILIZANDO ESTRUTURA LIGADA COM VETOR  */
/* E APONTADOR                                           */
/* Exemplo com 2 listas ordenadas                        */
/*********************************************************/

#include <iostream.h>
#include <string.h>
#include <conio.h>

#define OK   1
#define ERRO 0
#define TAM_VET 10

struct info
{
  char dado[21];
  int  prox;
};

struct info Lista[TAM_VET];
int Cabec1, Cabec2, Livre;

void Inic_Vetor(struct info Lista[],int &Livre)
{
  int k;
  Livre = 0;
  for(k=0; k < TAM_VET; k++) Lista[k].prox = k+1;
  Lista[TAM_VET-1].prox = -1;
}

void Inic_Lista(int &Cabec)
{
  Cabec = -1;
}

int Ins_Lista(struct info Lista[], char *Elem, int &Cabec, int &Livre)
{
  int ant,aux,atual;
  if ( Livre == -1 )
  {
	 cout << "\nInsercao Impossivel - Lista Cheia\n";
	 return(ERRO);
  }
  else
  {
	 if ( Cabec == -1 )
	 {
		Cabec = Livre;
		strcpy(Lista[Cabec].dado,Elem);
		Livre = Lista[Livre].prox;
		Lista[Cabec].prox = -1;
	 }
	 else
	 {
		aux = Cabec;
		ant  =  -1;
		while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) < 0) )
		{
		  ant = aux;
		  aux = Lista[aux].prox;
		}
		atual = Livre;
		Livre = Lista[Livre].prox;
		strcpy(Lista[atual].dado,Elem);
		if (ant == -1)
		{
		  Lista[atual].prox = Cabec;
		  Cabec = atual;
		}
		else Lista[ant].prox  =  atual;
		Lista[atual].prox = aux;
	 }
  }
  return(OK);
}

int Del_Lista(struct info Lista[], char *Elem, int &Cabec, int &Livre)
{
  int ant,aux,atual;
  if ( Cabec == -1 )
  {
	 cout << "\nDelecao Impossivel - Lista Vazia\n";
	 return(ERRO);
  }
  else
  {
	 aux = Cabec;
	 ant  =  -1;
	 while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) !=0 ) )
	 {
		ant = aux;
		aux = Lista[aux].prox;
	 }
	 if ( aux == -1 )
	 {
		cout << "\nErro - elemento nao existe...";
		return(ERRO);
	 }
	 else
	 {
		strcpy(Elem,Lista[aux].dado);
		if ( ant == -1 ) Cabec = Lista[aux].prox;
		else Lista[ant].prox = Lista[aux].prox;
	 }
	 Lista[aux].prox = Livre;
	 Livre = aux;
  }
  return(OK);
}

//Devolve em posicao o elemento encontrado
int Consulta_Lista(struct info Lista[], char *Elem, int &Cabec, int &posicao)
{
  int aux;
  if ( Cabec == -1 )
  {
	 cout << "\nConsulta Impossivel - Lista Vazia\n";
	 return(ERRO);
  }
  else
  {
	 aux = Cabec;
	 posicao=-1;
	 while ( aux != -1 && (strcmp(Lista[aux].dado,Elem) !=0 ) ) aux = Lista[aux].prox;
	 if ( aux == -1 )
	 {
	   cout << "\nErro - elemento nao existe...";
	   return(ERRO);
	 }
	 else posicao = aux;
  }
  return(OK);
}

void Imp_Lista(struct info Lista[],int Cabec, char *txt)
{
  int k;
  k = Cabec;
  cout << txt << "Cabec-> ";
  while ( k != -1 )
  {
	 cout << Lista[k].dado << " -> ";
	 k = Lista[k].prox;
  }
  cout << "fim da lista";
}

void Imp_Vetor()
{
  int k;
  cout << "\nind    prox   info\n";
  for(k=0; k < TAM_VET; k++)
	 cout << " " << k << "     " << Lista[k].prox << "     " << Lista[k].dado << "\n";
  cout << "  Cabec1 = " << Cabec1 << "  Cabec2 = " << Cabec2
       << "  Livre = " << Livre << "\n";
}


void main()
{
  char str[21];
  int op=0,pos,ok;

  Inic_Lista(Cabec1);
  Inic_Lista(Cabec2);
  Inic_Vetor(Lista,Livre);
  while ( op != 9 )
  {
	 cout << "\n\nMenu\n1-Inserir Lista A\n2-Inserir Lista B"
	 << "\n3-Remover Lista A\n4-Remover Lista B"
	 << "\n5-Consultar Lista A\n6-Consultar Lista B"
	 << "\n7-Imprime Lista A e B\n8-Imp. Vetor\n9-Fim\nOpcao: ";
	 cin >> op;
	 if ( op == 1)
	 {
		cout << "\nDigite o elem a ser inserido na Lista A (ate 20 caracteres): "; cin >> str;
		Ins_Lista(Lista,str,Cabec1,Livre);
	 }
	 if ( op == 2)
	 {
		cout << "\nDigite o elem a ser inserido na Lista B (ate 20 caracteres): "; cin >> str;
		Ins_Lista(Lista,str,Cabec2,Livre);
	 }
	 else if ( op == 3 )
	 {
		cout << "\nDigite o elem a ser removido da Lista A (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(Lista,str,Cabec1,Livre);
		if ( ok != ERRO) cout << "\nElemento removido da Fila A: " << str;
	 }
	 else if ( op == 4 )
	 {
		cout << "\nDigite o elem a ser removido da Lista B (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(Lista,str,Cabec2,Livre);
		if ( ok != ERRO) cout << "\nElemento removido da Fila B: " << str;
	 }
	 else if ( op == 5 )
	 {
		cout << "\nDigite o elem a ser consultado na Lista A (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(Lista,str,Cabec1,pos);
		if ( ok != ERRO) cout << "\nElemento consultado Lista A: " << Lista[pos].dado;
		else cout << "Elemento nao existe na Lista A";
	 }
	 else if ( op == 6 )
	 {
		cout << "\nDigite o elem a ser consultado na Lista B (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(Lista,str,Cabec2,pos);
		if ( ok != ERRO) cout << "\nElemento consultado Lista B: " << Lista[pos].dado;
		else cout << "Elemento nao existe na Lista B";
	 }
	 else if ( op == 7 )
	 {
		Imp_Lista(Lista,Cabec1,"\nLista A:\n");
		Imp_Lista(Lista,Cabec2,"\nLista B:\n");
	 }
	 else if ( op == 8 ) Imp_Vetor();
  }
}