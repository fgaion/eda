//CUSTOMIN.CPP
//Custo M¡nimo utilizando matriz de adjacˆncias

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAX_NO   5
#define INFINITO 99

int G[MAX_NO][MAX_NO] = {
   {99,17, 5,99,99},
   {15,99,10, 6,15},
   { 5,10,99,20,99},
   {99, 6,20,99, 5},
   {99,15,99, 5,99}};


void CustoMin(int A[MAX_NO][MAX_NO],int s,int t,int &pd, int precede[]) {
  int distance[MAX_NO], perm[MAX_NO];
  int current, i, k, dc, smalldist, newdist;

  for(i=0; i < MAX_NO; i++) {
    perm[i] = 0;
    distance[i] = INFINITO;
  }
  perm[s] = 1;
  distance[s] = 0;
  current = s;
  while ( current != t ) {
    smalldist = INFINITO;
    dc = distance[current];
    for(i=0; i < MAX_NO; i++) {
      if ( perm[i] == 0 )
      {
	      newdist = dc + A[current][i];
	      if ( newdist < distance[i] ){
	        distance[i] = newdist;
	         precede[i] = current;
	      }
	      if ( distance[i] < smalldist ) {
	        smalldist = distance[i];
	        k = i;
	      }
      }
    }
    current = k;
    perm[current] = 1;
  }
  pd = distance[t];
}

int main() {
  int i, orig, dest, custo, caminho[MAX_NO];

  for(i=0; i < MAX_NO; i++) caminho[i] = 0;
  orig = 0;
  dest = 4;
  CustoMin(G,orig,dest,custo,caminho);
  cout << "\nCusto Minimo: " << custo << "\nCaminho: ";
  i=dest;
  while ( i != orig ) {
    cout << i << " <- ";
    i = caminho[i];
  }
  cout << orig;
}
