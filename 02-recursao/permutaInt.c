//Permutação de n elementos de um vetor de inteiros

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int A[5] = { 1, 2, 3, 4, 5};
int tamA = 4;

void imp_vet(int A[], int n) {
  int k;

  for(k=0; k < n; k++) printf("%d  ",A[k]);
  printf(" ; ");
}

void swap(int *x, int *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permutaVetor(int *a, int l, int r) {
   int i;
   
   if (l == r)
     imp_vet(a,l+1);
   else {
       for (i = l; i <= r; i++){
          swap((a+l), (a+i));
          permutaVetor(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}

int main() {
  printf("\n\nPermutacao nao recursiva:\n");
  permutaVetor(A,0,tamA-1);
  printf("\n\n");
}
