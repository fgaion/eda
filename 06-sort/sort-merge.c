#include <stdio.h>
#define NUMELEM 100

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void MergeSort(int x[], int n){
  int aux[NUMELEM],i,j,k,a1,a2,u1,u2,tam;
  tam = 1; //intercala subvetores de tamanho 1
  while (tam < n ){
	 a1 = k = 0;
	 while ((a1 + tam) < n ){
		a2 = a1 + tam;
		u1 = a2 - 1;
		u2 = (a2+tam-1 < n) ? a2+tam-1 : n-1;
		for(i = a1, j = a2; i <= u1 && j <= u2; k++){
		  if (x[i] <= x[j]) aux[k] = x[i++];
		  else aux[k] = x[j++];
		}
		for( ; i <= u1; k++) aux[k] = x[i++];
		for( ; j <= u2; k++) aux[k] = x[j++];
		a1 = u2+1;
	 }
	 //copia o restante de x em aux
	 for(i = a1; k < n; i++) aux[k++] = x[i];
	 //copia aux em x
	 for(i = 0; i < n; i++) x[i] = aux[i];
	 tam *= 2;
  }  
}

void main(){
	printf("\nMerge sort p/ o vetor A:\n");
	MergeSort(A,8);
    ImprimeVet(A,8);
	printf("\nMerge sort p/ o vetor B:\n");
	MergeSort(B,15);
    ImprimeVet(B,15);
}

