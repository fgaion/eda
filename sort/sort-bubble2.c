#include <stdio.h>

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void Bubble(int x[], int n){
	int aux,j,passo,chave=1;
	for(passo=0; passo<n-1 && chave; passo++){
	  chave=0;
	  for(j=0;j < n-passo-1;j++){
		 if(x[j] > x[j+1]){
			chave=1;
			aux=x[j];
			x[j]=x[j+1];
			x[j+1]=aux;
		 }
	  }	  
	}
}

void main(){
	printf("\nBuble sort p/ o vetor A:\n");
	Bubble(A,8);
    ImprimeVet(A,8);
	printf("\nBuble sort p/ o vetor B:\n");
	Bubble(B,15);
    ImprimeVet(B,15);
}
