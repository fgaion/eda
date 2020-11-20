#include <stdio.h>

int mA[4] = {1, 3, 4, 7};
int mB[6] = {2, 5, 6, 8, 9, 10};
int mC[10];

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void MergeArray(int a[],int b[],int c[],int na,int nb,int nc)
{
  int ap, bp, cp;

  if ( nc != na+nb )
  {
	 printf("\nTamanhos dos vetores incompativeis");
	 return;
  }
  ap = bp = 0;
  for(cp = 0; ap < na && bp < nb; cp++)
  {
	 if ( a[ap] < b[bp] ) c[cp] = a[ap++];
	 else c[cp] = b[bp++];
  }
  while ( ap < na ) c[cp++] = a[ap++];
  while ( bp < nb ) c[cp++] = b[bp++];
}

void main(){
	printf("\nMerge Array:\n");
	MergeArray(mA,mB,mC,4,6,10);
    ImprimeVet(mA,4);
    ImprimeVet(mB,6);
    ImprimeVet(mC,10);
}
