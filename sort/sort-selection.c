#include <stdio.h>

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void Selection(int x[],int n){
  int i,indx,j,maior;
  for(i=n-1;i>0;i--){
	 maior = x[0];
	 indx = 0;
	 for(j=1; j <= i; j++){
		if ( x[j] > maior )	{
		  maior = x[j];
		  indx = j;
		}
	 }
	 x[indx] = x[i];
	 x[i]=maior;
  }
}

void main(){
	printf("\nSelection sort p/ o vetor A:\n");
	Selection(A,8);
    ImprimeVet(A,8);
	printf("\nSelection sort p/ o vetor B:\n");
	Selection(B,15);
    ImprimeVet(B,15);
}
