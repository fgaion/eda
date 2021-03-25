#include <stdio.h>

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void Particionar(int x[],int lb,int ub, int *j){
  int a,temp, down, up;
  a = x[lb];
  up = ub;
  down = lb;
  while ( down < up ){
	 while ( x[down] <= a && down < ub ) down++;
	 while ( x[up] > a ) up--;
	 if ( down < up ){
		temp = x[down];
		x[down]=x[up];
		x[up] = temp;
	 }
  }
  x[lb]=x[up];
  x[up]=a;
  *j = up;
}

void QuickSort(int x[],int lb, int ub,int n) {
  int j;
  if ( lb >= ub ) return;
  Particionar(x,lb,ub,&j);
  QuickSort(x,lb,j-1,n);
  QuickSort(x,j+1,ub,n);
}

void main() {
	printf("\nQuick sort p/ o vetor A:\n");
	QuickSort(A,0,7,8);
    ImprimeVet(A,8);
	printf("\nQuick sort p/ o vetor B:\n");
	QuickSort(B,0,14,15);
    ImprimeVet(B,15);
}

