#include <stdio.h>

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void Insertion(int x[], int n){
  int i,k,y;
  for(k=1; k<n; k++){
	 y = x[k];
	 for(i=k-1;i >= 0 && y < x[i]; i--) x[i+1] = x[i];
	 x[i+1]=y;	 
  }
}

void main(){	
	printf("\nInsertion sort p/ o vetor A:\n");
	Insertion(A,8);
    ImprimeVet(A,8);
	printf("\nInsertion sort p/ o vetor B:\n");
	Insertion(B,15);
    ImprimeVet(B,15);
}
