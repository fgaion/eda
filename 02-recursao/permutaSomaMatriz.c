//Permutação de n elementos
// gerar uma matriz 4x4 com os números abaixo na varável A onde
//a soma das linhas, colunas e diagonais seja igual a 47


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int A[16] = {16,18,20,5,6,8,9,9,10,11,11,12,13,13,13,14};
int tamA = 16, s4 = 47;
long int iter=1, iter2=1;

int soma4elem(int a,int b, int c, int d){
  return(a+b+c+d);
}  

void imp_vet(int A[], int n) {
  int k;
  printf("\n=========================================================\nVetor A: ");
  for(k=0; k < n; k++) printf("%d  ",A[k]);
  printf("\n============================================================\n ");
}

void swap(int *x, int *y){
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
void permutation(int *a, int l, int r)
{
   int i,sd1,sd2,sl1,sl2,sl3,sl4,sc1,sc2,sc3,sc4;
   
   if (l == r){
     sd1 = soma4elem(a[0],a[5],a[10],a[15]);
     sd2 = soma4elem(a[3],a[6],a[9],a[12]);
     sl1 = soma4elem(a[0],a[1],a[2],a[3]);
     sl2 = soma4elem(a[4],a[5],a[6],a[7]);
     sl3 = soma4elem(a[8],a[9],a[10],a[11]);
     sl4 = soma4elem(a[12],a[13],a[14],a[15]);
     sc1 = soma4elem(a[0],a[4],a[8],a[12]);
     sc2 = soma4elem(a[1],a[5],a[9],a[13]);
     sc3 = soma4elem(a[2],a[6],a[10],a[14]);
     sc4 = soma4elem(a[3],a[7],a[11],a[15]);
     
     //if(sd1==s4) printf("%d-",sd1);
     iter++;
     if (iter == 100000000) { printf("%d ",iter2); iter2++; iter = 1;}
     if ((sd1==s4)&&(sd2==s4) \
          &&(sl1==s4)&&(sl2==s4)&&(sl3==s4)&&(sl4==s4) \
          &&(sc1==s4)&&(sc2==s4)&&(sc3==s4)&&(sc4==s4)   ) imp_vet(a,l+1);
   }  
   else {
       for (i = l; i <= r; i++){
          swap((a+l), (a+i));
          permutation(a, l+1, r);
          swap((a+l), (a+i));
       }
   }
}


int main() {
  printf("\n\nPermutacao - matriz 4x4:\n");
  permutation(A,0,tamA-1);
  printf("\n\n");
}
