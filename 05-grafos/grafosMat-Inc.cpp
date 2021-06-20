//GRAFOS02.CPP
//Grafos utilizando matriz de incidˆncias

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
#define MAX_NO 5
#define MAX_ARESTA 10

int G1[MAX_NO][MAX_ARESTA] = {
	   {1,0,0,0,0,0,1,5,5,5},
	   {1,1,1,0,0,1,0,5,5,5},
	   {0,1,0,1,0,0,0,5,5,5},
	   {0,0,1,0,1,0,1,5,5,5},
	   {0,0,0,1,1,1,0,5,5,5} };

int G2[MAX_NO][MAX_ARESTA] = {
	   { 1,-1, 1, 0, 0, 0,-1, 0, 0, 5},
	   { 0, 0,-1,-1, 0, 0, 0, 2, 0, 5},
	   {-1, 1, 0, 0, 0, 1, 0, 0, 0, 5},
	   { 0, 0, 0, 1, 1, 0, 1, 0,-1, 5},
	   { 0, 0, 0, 0,-1,-1, 0, 0, 1, 5} };

void ImpMat(int A[MAX_NO][MAX_ARESTA],int m,int n) {
  int i,j;
  for(i=0; i < m; i++) {
    for(j=0; j < n; j++) cout << A[i][j] << " ";
    cout << "\n";
   }
}

void ImpGrauGND(int A[MAX_NO][MAX_ARESTA],int m,int n) {
  int i,j,grau;
  for(i=0; i < m; i++) {
    grau = 0;
    for(j=0; j < n; j++)
      if ( A[i][j] == 1 ) grau++;
    cout << "\nNo' " << i << " tem grau " << grau;
  }
}

void ImpGrauGD(int A[MAX_NO][MAX_ARESTA],int m,int n) {
  int i,j,gs,ge;
  for(i=0; i < m; i++) {
    gs = ge = 0;
    for(j=0; j < n; j++) {
      if ( A[i][j] == 1  ) gs++;
      else
      if ( A[i][j] == -1 ) ge++;
      else
      if ( A[i][j] == 2 ) {
	       gs++;
	       ge++;
      }
    }
    cout << "\nNo' " << i << " tem grau de saida " << gs
	 << ", grau de entrada " << ge << " e grau total " << gs+ge;
  }
}

void ImpAdjacenciasGND(int A[MAX_NO][MAX_ARESTA],int m,int n) {
  int i,j,k;
  for(i=0; i<m; i++) {
    cout << "\nNo' " << i << " e' adjacente a: ";
    for(j=0; j < n; j++) {
      if ( A[i][j] == 2 ) cout << j << " ";
      else
      if ( A[i][j] == 1 ) {
	      for(k=0; k < m; k++)
	        if ( k != i && A[k][j] == 1 ) cout << k << " ";
      }
    }
  }
}

void ImpAdjacenciasGD(int A[MAX_NO][MAX_ARESTA],int m,int n) {
  int i,j,k;
  for(i=0; i<m; i++) {
    cout << "\nNo' " << i << " e' adjacente a: ";
    for(j=0; j < n; j++)
    {
      if ( A[i][j] == 2 ) cout << i << " ";
      else
      if ( A[i][j] == 1 ) {
	      for(k=0; k < m; k++)
          if ( k != i &&  A[k][j] == -1 ) cout << k << " ";
      }
    }
  }
}

int main() {  
  ImpGrauGND(G1,5,7);
  cout << "\n";
  ImpGrauGD(G2,5,9);
  cout << "\n";
  ImpAdjacenciasGND(G1,5,7);
  cout << "\n";
  ImpAdjacenciasGD(G2,5,9);
  cout << endl;
}





