//Combinacao de m elementos p a p

#include <stdio.h>

int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int P[10];

void imp_vet(int A[], int n)
{
  int k;
  for(k=0; k < n; k++) printf("%d ",A[k]);
  printf("\n");
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
  int n,p;
  printf("\nCombinacao de n (ate 10) elementos p a p:\n");
  printf("Entre com n: ");
  scanf("%d",&n);
  printf("Entre com p: ");
  scanf("%d",&p);
  Combina(A,n,p,P,0);
}