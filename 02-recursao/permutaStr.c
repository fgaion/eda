//Permutação de n elementos de uma string

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void SwapChar( char* str, int p1, int p2) {
   char tmp;
   tmp = str[p1];
   str[p1] = str[p2];
   str[p2] = tmp;
}

void PermutaStr( char* str, int k) {
   int i, len;

   len = strlen( str);
   if (k == len) {
      printf( "%s\n", str);
   } else {
      for (i = k; i < len; i++) {
         SwapChar(str, k, i);
         //printf("k= %d",k);
         PermutaStr(str, k + 1);
         SwapChar(str, i, k);
      }
   }
}

int main() {
  char str[10];
  strcpy(str,"ABCD");  
  printf("\n\nPermutacao String %s:\n",str);
  PermutaStr( str, 0);
  printf("\n\n");
}
