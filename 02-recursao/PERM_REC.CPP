//Combinação de m elementos p a p

#include <iostream.h>
#include <stdio.h>

int A[5] = { 1, 2, 3, 4, 5};
int P[5];

void imp_vet(int A[], int n)
{
  int k;
  for(k=0; k < n; k++) cout << A[k] << " ";
  cout << "\n";
}

void Combina(int A[], int n, int p, int P[], int indP)
{
  int k;
  if ( p == 1 )
  {
    for(int i=n-1; i>=0; i--)
    {
      P[indP] = A[i];
      imp_vet(P,indP+1);
    }
    return;
  }
  else
  {
    for(k=n-1; k >= p-1; k--)
    {
      P[indP] = A[k];
      if (p-1 > 0) Combina(A,k,p-1,P,indP+1);
    }
  }
}

void main()
{
  cout << "\nCombinacao de 5 elementos 3 a 3:\n";
  Combina(A,5,3,P,0);
}