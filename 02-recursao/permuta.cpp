//Permutação de n elementos

#include <iostream.h>
#include <stdio.h>

int A[5] = { 1, 2, 3, 4, 5};

void rotaciona_esq(int A[], int tam)
{
  int k, aux;
  if ( tam > 0 )
  {
    aux = A[0];
    for(k=0; k < tam-1; k++) A[k] = A[k+1];
    A[tam-1] = aux;
  }
}

void imp_vet(int A[], int n)
{
  int k;

  for(k=0; k < n; k++) cout << A[k] << " ";
  cout << "  *  ";
}

void permuta(int A[], int n, int tam)
{
  int i,k;
  for(i=n-1; i >=0; i--)
  for(k=0; k <= i; k++)
  {
    imp_vet(A,tam);
    rotaciona_esq(A,i+1);
  }
}

void main()
{
  cout << "\n\nPermuta‡Æo NÆo recursiva:\n";
  permuta(A,4,4);
}