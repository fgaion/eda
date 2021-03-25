#include <stdio.h>

int A[]={25,57,48,37,12,92,86,33};
int B[]={45,37,76,10,65,8,16,29,52,98,4,35,50,63,70};

void ImprimeVet(int x[],int n) {
  int j;
  for(j=0; j<n; j++) printf("%d ",x[j]);
  printf("\n");
}

void ShellSort(int x[], int n, int incrmnts[], int numinc){
  int incr,j,k,tam,y;
  for(incr = 0; incr < numinc; incr++){
	 tam = incrmnts[incr];
	 for(j = tam; j < n; j++){
		y = x[j];
		for(k = j-tam; k >= 0 && y < x[k]; k -= tam) x[k+tam]=x[k];
		x[k+tam] = y;
	 }
  }
}

void main(){
	int pos, k[]={5,3,1};

	printf("\nShell sort p/ o vetor A:\n");
	ShellSort(A,8,k,3);
    ImprimeVet(A,8);
	printf("\nShell sort p/ o vetor B:\n");
	ShellSort(B,15,k,3);
    ImprimeVet(B,15);
}
