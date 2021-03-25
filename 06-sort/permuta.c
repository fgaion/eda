//Permutacao de n elementos - corrigir
//123, 132, 213, 231, 312, 321

#include <stdio.h>

int A[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

// exchange two integers
void swap(int *i, int *j){
  int t = *i;
  *i = *j;
  *j = t;
}

// full permutation
void perm(int nums[],int n, int i){
  if (i == (n-1)){
    for (int j =0; j < n; j ++) printf("%d",nums[j]);
    printf("\n");
  }
  else {
    for (int j =i; j < n; j ++){
      swap(&nums[i],&nums[j]); // swap
      perm(nums,n,i + 1);         // recursive
      swap(&nums[i],&nums[j]); // swap it back
    }
  }
}

// main entry
int main(){
  int n;
  printf("\nEntre com o tamanho do vetor n = ");
  scanf("%d",&n);
  perm(A,n, 0);
  return 0;
}

