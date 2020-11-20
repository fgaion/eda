//GRAFOS01.CPP
//Grafos - algoritmos utilizando matriz de adjacencias

#include <iostream.h>
#include <stdio.h>
#include <conio.h>

#define TAM_VET 50
#define MAX_NO 5
#define VERD 1
#define FALSO 0

//Grafo qualquer
int G[MAX_NO][MAX_NO];
int Visitado[MAX_NO];
int Rota[MAX_NO];

int Q[TAM_VET],frente,fim;  //fila de numeros inteiros

//Grafo G1- n∆o dirigido
int G1[5][5] = {
		 {0, 1, 1, 1, 5},
		 {1, 0, 0, 1, 5},
		 {1, 1, 0, 1, 5},
		 {1, 1, 1, 0, 5},
		 {5, 5, 5, 5, 5} };

//Grafo G2 - dirigido
int G2[5][5] = {
		 {0, 1, 1, 0, 0},
		 {1, 0, 0, 0, 0},
		 {1, 0, 0, 0, 1},
		 {0, 1, 1, 0, 0},
		 {0, 0, 0, 1, 0} };

//Grafo G3 - n∆o dirigido
int G3[5][5] = {
       {0, 1, 1, 0, 0},
		 {1, 0, 0, 0, 1},
		 {1, 0, 0, 1, 1},
		 {0, 1, 1, 0, 0},
		 {0, 1, 1, 0, 0} };

void Inic_Fila(int &frente, int &fim)
{
  frente = fim = -1;
}

int Fila_Vazia(int frente, int fim)
{
  return(frente==fim?VERD:FALSO);
}

int Ins_Fila(int F[], int &fim, int x)
{
  if (fim == TAM_VET-1)
  {
	 cout << "Erro - Ins. Fila cheia";
	 return(FALSO);
  }
  else
  {
	 fim++;
	 F[fim] = x;
  }
  return(VERD);
}

int Del_Fila(int F[], int &frente, int &fim, int &x)
{
  if (frente == fim)
  {
	 cout << "Erro - Del. Fila vazia";
	 return(FALSO);
  }
  else
  {
	 frente++;
	 x = F[frente];
  }
  return(VERD);
}

void InicVet(int A[MAX_NO], int n, int val=0)
{
  int i;
  for(i=0; i < n; i++) A[i] = val;
}

void ImpVet(int A[MAX_NO], int n)
{
  int i;
  cout << "\nVetor: ";
  for(i=0; i < n; i++) cout << A[i] << " ";
  cout << "\n";
}

void LeGrafo(int A[MAX_NO][MAX_NO],int n)
{
  int k,j;

  for(k=0; k < n; k++)
  {
	 for(j=0; j < n; j++)
	 {
		cout << "G[" << k << "," << j << "] = ";
		cin >> A[k][j];
	 }
  }
}

void ImpMat(int A[MAX_NO][MAX_NO],int n)
{
  int k,j;

  for(k=0; k < n; k++)
  {
	 for(j=0; j < n; j++) cout << A[k][j] << " ";
	 cout << "\n";
  }
  cout << "\n";
}

void ImpGrauGND(int A[MAX_NO][MAX_NO], int n)
{
  int i,j,grau;
  for(i=0; i < n; i++)
  {
	 grau = 0;
	 for(j=0; j < n; j++) grau += A[i][j];
	 cout << "\nNo " << i << " tem grau " << grau;
  }
}

void ImpGrauGD(int A[MAX_NO][MAX_NO], int n)
{
  int i,j,ge,gs;
  for(i=0; i < n; i++)
  {
	 ge = gs = 0;
	 for(j=0; j < n; j++)
	 {
		gs += A[i][j];
		ge += A[j][i];
	 }
	 cout << "\nNo " << i << " tem grau de saida " << gs << "\n"
	 << "grau de entrada " << ge << " e grau " << (ge + gs);
  }
}

void ImpAdjacencias(int A[MAX_NO][MAX_NO], int n)
{
  int i,j;
  for(i=0; i < n; i++)
  {
	 cout << "\nNo " << i << " :";
	 for(j=0; j < n; j++)
		if ( A[i][j] ) cout << j << " ";
  }
}

void PesqProf(int A[MAX_NO][MAX_NO], int n, int v)
{
  int j;
  Visitado[v] = 1;
  cout << "No " << v << " , ";
  for(j=0; j < n; j++)
		if ( A[v][j]==1  && Visitado[j]==0 ) PesqProf(A,n,j);
}

void PesqLargura(int A[MAX_NO][MAX_NO],int n,int v)
{
  int j;
  Visitado[v] = 1;
  Inic_Fila(frente,fim);
  while ( VERD )
  {
	 cout << "No " << v << " , ";
	 for(j=0; j < n; j++)
	 {
		if ( A[v][j]==1  && Visitado[j]==0 )
		{
		  Ins_Fila(Q,fim,j);
		  Visitado[j] = 1;
		}
	 }
	 if ( Fila_Vazia(frente,fim) ) break;
	 Del_Fila(Q,frente,fim,v);
  }
}

void Caminho(int A[MAX_NO][MAX_NO],int n,int v1,int v2,int ord,int &ok)
{
  int j;
  Visitado[v1] = 1;
  Rota[ord]=v1;
  if ( v1 == v2) ok = 1;
  else
  {
	 for(j=0; j < n; j++)
	 {
		if ( A[v1][j]==1  && Visitado[j]==0 ) Caminho(A,n,j,v2,ord+1,ok);
		if (ok) return;
	 }
  }
}

void main()
{
  char txt[10];
  clrscr();
  cout << "\nGrafo G1";
  ImpGrauGND(G1,4);
  cout << "\nGrafo G2";
  ImpGrauGD(G2,5);
  cout << "\nGrafo G3";
  ImpGrauGND(G3,5);

  cout << "\nDigite algo: "; cin >> txt;
  cout << "\nGrafo G1";
  ImpAdjacencias(G1,4);
  cout << "\nGrafo G2";
  ImpAdjacencias(G2,5);
  cout << "\nGrafo G3";
  ImpAdjacencias(G3,5);

  cout << "\nDigite algo: "; cin >> txt;
  cout << "\nPesquisa em Profundidade em G1 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqProf(G1,4,0);
  cout << "\nPesquisa em Profundidade em G2 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqProf(G2,5,0);
  cout << "\nPesquisa em Profundidade em G3 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqProf(G3,5,0);

  cout << "\nDigite algo: "; cin >> txt;
  cout << "\nPesquisa em Largura em G1 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqLargura(G1,4,0);
  cout << "\nPesquisa em Largura em G2 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqLargura(G2,5,0);
  cout << "\nPesquisa em Largura em G3 a partir do no¥ 0\n";
  InicVet(Visitado,MAX_NO,0);
  PesqLargura(G3,5,0);

  cout << "\nDigite algo: "; cin >> txt;
  cout << "\nCaminho em G1 de 0 a 3\n";
  InicVet(Visitado,MAX_NO,0);
  InicVet(Rota,MAX_NO,-1);
  Caminho(G1,4,0,3,0,0);
  ImpVet(Rota,MAX_NO);
  cout << "\nCaminho em G2 de 0 a 3\n";
  InicVet(Visitado,MAX_NO,0);
  InicVet(Rota,MAX_NO,-1);
  Caminho(G2,5,0,3,0,0);
  ImpVet(Rota,MAX_NO);
  cout << "\nCaminho em G3 de 0 a 3\n";
  InicVet(Visitado,MAX_NO,0);
  InicVet(Rota,MAX_NO,-1);
  Caminho(G3,5,0,3,0,0);
  ImpVet(Rota,MAX_NO);
}
