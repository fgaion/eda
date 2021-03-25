/*********************************************************/
/* LISTA ORDENADA DUPLAMENTE LIGADA UTILIZANDO ESTRUTURA */
/* LIGADA COM VETOR E APONTADOR                          */
/* Exemplo com 2 listas duplamente ligadas e ordenadas   */
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
  int  ant,prox;
};

struct info ListaDL[TAM_VET];
int Cabec1, Fim1, Cabec2, Fim2, Livre;

void Inic_Vetor(struct info ListaDL[],int &Livre)
{
  int k;
  Livre = 0;
  for(k=0; k < TAM_VET; k++)
  {
	 ListaDL[k].prox = k+1;
	 ListaDL[k].ant = -1;
	 strcpy(ListaDL[k].dado,"***");
  }
  ListaDL[TAM_VET-1].prox = -1;
}

void Inic_Lista(int &Cabec,int &Fim)
{
  Cabec = Fim = -1;
}

int Ins_Lista(struct info ListaDL[], char *Elem, int &Cabec, int &Fim,int &Livre)
{
  int aux,atual;
  if ( Livre == -1 )
  {
	 cout << "\nInsercao Impossivel - Lista Cheia\n";
	 return(ERRO);
  }
  else
  {
	 atual = Livre;
	 Livre = ListaDL[Livre].prox;
	 strcpy(ListaDL[atual].dado,Elem);
	 ListaDL[atual].prox = -1;
	 ListaDL[atual].ant = -1;

	 if ( Cabec == -1 ) Cabec = Fim = atual;
	 else
	 {
		aux = Cabec;
		while ( aux != -1 && (strcmp(ListaDL[aux].dado,Elem) < 0) )
		  aux = ListaDL[aux].prox;

		if ( Cabec == aux )
		{
		  ListaDL[atual].prox = aux;
		  ListaDL[aux].ant = atual;
		  Cabec = atual;
		}
		else
		if (aux == -1)
		{
		  ListaDL[atual].ant = Fim;
		  ListaDL[Fim].prox = atual;
		  Fim = atual;
		}
		else
		{
		  ListaDL[ListaDL[aux].ant].prox  =  atual;
		  ListaDL[atual].ant = ListaDL[aux].ant;
		  ListaDL[atual].prox = aux;
		  ListaDL[aux].ant = atual;
		}
	 }
  }
  return(OK);
}

int Del_Lista(struct info ListaDL[], char *Elem, int &Cabec, int &Fim, int &Livre)
{
  int aux;
  if ( Cabec == -1 )
  {
	 cout << "\nDelecao Impossivel - Lista Vazia\n";
	 return(ERRO);
  }
  else
  {
	 aux = Cabec;
	 while ( aux != -1 && (strcmp(ListaDL[aux].dado,Elem) !=0 ) )
		aux = ListaDL[aux].prox;

	 if ( aux == -1 )
	 {
		cout << "\nErro - elemento nao existe...";
		return(ERRO);
	 }
	 else
	 {
		strcpy(Elem,ListaDL[aux].dado);
		strcpy(ListaDL[aux].dado,"***");
		if (aux == Cabec)
		{
		  Cabec = ListaDL[aux].prox;
		  if (Cabec != -1) ListaDL[Cabec].ant = -1;
		  else Cabec = Fim = -1;
		}
		else
		{
		  if (aux == Fim)
		  {
			 ListaDL[ListaDL[aux].ant].prox = -1;
			 Fim = ListaDL[aux].ant;
		  }
		  else
		  {
			 ListaDL[ListaDL[aux].ant].prox = ListaDL[aux].prox;
			 ListaDL[ListaDL[aux].prox].ant = ListaDL[aux].ant;
		  }
		}
		ListaDL[aux].prox = Livre;
		Livre = aux;
	 }
  }
  return(OK);
}

//Devolve em posicao o elemento encontrado
int Consulta_Lista(struct info ListaDL[], char *Elem, int &Cabec, int &posicao)
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
	 while ( aux != -1 && (strcmp(ListaDL[aux].dado,Elem) !=0 ) ) aux = ListaDL[aux].prox;
	 if ( aux == -1 )
	 {
	   cout << "\nErro - elemento nao existe...";
	   return(ERRO);
	 }
	 else posicao = aux;
  }
  return(OK);
}

void Imp_Lista(struct info ListaDL[],int Cabec, char *txt)
{
  int k;
  k = Cabec;
  cout << txt << "Cabec-> ";
  while ( k != -1 )
  {
	 cout << ListaDL[k].dado << " -> ";
	 k = ListaDL[k].prox;
  }
  cout << "fim da lista";
}

void Imp_Vetor()
{
  int k;
  cout << "\nind    ant   info   prox\n";
  for(k=0; k < TAM_VET; k++)
	 cout << " " << k << "     " << ListaDL[k].ant << "     "
			<< ListaDL[k].dado << "     " << ListaDL[k].prox << "\n";
  cout << "  Cabec1 = " << Cabec1 << "  Cabec2 = " << Cabec2
		 << "  Fim1 = " << Fim1 << "  Fim2 = " << Fim2
		 << "  Livre = " << Livre << "\n";
}


void main()
{
  char str[21];
  int op=0,pos,ok;

  Inic_Lista(Cabec1,Fim1);
  Inic_Lista(Cabec2,Fim2);
  Inic_Vetor(ListaDL,Livre);
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
		Ins_Lista(ListaDL,str,Cabec1,Fim1,Livre);
	 }
	 if ( op == 2)
	 {
		cout << "\nDigite o elem a ser inserido na Lista B (ate 20 caracteres): "; cin >> str;
		Ins_Lista(ListaDL,str,Cabec2,Fim2,Livre);
	 }
	 else if ( op == 3 )
	 {
		cout << "\nDigite o elem a ser removido da Lista A (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(ListaDL,str,Cabec1,Fim1,Livre);
		if ( ok != ERRO) cout << "\nElemento removido da Fila A: " << str;
	 }
	 else if ( op == 4 )
	 {
		cout << "\nDigite o elem a ser removido da Lista B (ate 20 caracteres): "; cin >> str;
		ok = Del_Lista(ListaDL,str,Cabec2,Fim2,Livre);
		if ( ok != ERRO) cout << "\nElemento removido da Fila B: " << str;
	 }
	 else if ( op == 5 )
	 {
		cout << "\nDigite o elem a ser consultado na Lista A (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(ListaDL,str,Cabec1,pos);
		if ( ok != ERRO) cout << "\nElemento consultado Lista A: " << ListaDL[pos].dado;
		else cout << "Elemento nao existe na Lista A";
	 }
	 else if ( op == 6 )
	 {
		cout << "\nDigite o elem a ser consultado na Lista B (ate 20 caracteres): "; cin >> str;
		ok = Consulta_Lista(ListaDL,str,Cabec2,pos);
		if ( ok != ERRO) cout << "\nElemento consultado Lista B: " << ListaDL[pos].dado;
		else cout << "Elemento nao existe na Lista B";
	 }
	 else if ( op == 7 )
	 {
		Imp_Lista(ListaDL,Cabec1,"\nLista A:\n");
		Imp_Lista(ListaDL,Cabec2,"\nLista B:\n");
	 }
	 else if ( op == 8 ) Imp_Vetor();
  }
}