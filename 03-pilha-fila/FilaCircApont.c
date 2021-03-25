/*********************************************************/
/* FILA CIRCULAR UTILIZANDO ESTRUTURA LIGADA COM ALOCACAO*/
/* DINAMICA E  APONTADORES                               */
/* Exemplo com 2 filas circulares                        */
/*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK   1
#define ERRO 0

struct info {
  char dado[21];
  struct info *prox;
};
struct info *fimA, *fimB;

void Imp_Lista(struct info *fim, char *txt) {
  struct info *p;

  if (fim == NULL ) printf("%s - Fila vazia...\n",txt);
  else {
    printf("%s: frente -> ",txt);
    p = fim->prox;
    while ( p != fim ) {
      printf("%s -> ",p->dado);      
      p = p->prox;
    }
    printf("%s  -> fim da fila",p->dado);
  }
}

int Ins_Fila(struct info **fim, char *s){
  struct info *p;  
  p = (struct info*) malloc(sizeof(struct info));
  if ( !p ) return(ERRO);
  strcpy(p->dado,s);
  p->prox = NULL;
  if ( *fim == NULL ) {
    *fim = p;
    (*fim)->prox = p;
  }  
  else   {
    p->prox = (*fim)->prox;
    (*fim)->prox = p;
    *fim = p;
  }
  return(OK);
}

int Del_Fila(struct info **fim, char *s){
  struct info *p;

  if ( *fim == NULL ) {
    printf("\nErro - Removendo de uma Fila Vazia...\n");
    return(ERRO);
  }
  else {
    p = (*fim)->prox;
    strcpy(s,p->dado);
    (*fim)->prox = p->prox;    
    if ( *fim == p ) *fim = NULL;
    free(p);
  }
  return(OK);
}

int Rec_Frente(struct info *fim, char *s)
{
  if ( fim == NULL ) {
    printf("\nErro - Recuperando frente de uma Fila Vazia...\n");
    return(ERRO);
  }
  else strcpy(s,fim->prox->dado);
  return(OK);
}

void main()
{
  char str[21];
  int op=0,ok;
  fimA = fimB = NULL;

  while ( op != 8 )
  {
    printf("\n\nMenu\n1-Inserir Fila A\n2-Inserir Fila B\n3-Remover Fila A\n4-Remover Fila B\n5-Mostra frente Fila A\n6-Mostra frente Fila B\
    \n7-Imprime Filas A e B\n8-Fim\nOpcao: ");
    scanf("%d",&op);
    if ( op == 1) {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(&fimA,str);
    }
    if ( op == 2){
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(&fimB,str);
    }
    else if ( op == 3 ){
      ok = Del_Fila(&fimA,str);
      if ( ok != ERRO) printf("\nElemento removido da Fila A: %s",str);
    }
    else if ( op == 4 ) {
      ok = Del_Fila(&fimB,str);
      if ( ok != ERRO) printf("\nElemento removido da Fila B: %s",str);
    }
    else if ( op == 5 ) {
      ok = Rec_Frente(fimA,str);
		  if ( ok != ERRO) printf("\nElemento do inicio da Fila A: %s",str);
    }
    else if ( op == 6 ) {
      ok = Rec_Frente(fimB,str);
		  if ( ok != ERRO) printf("\nElemento do inicio da Fila B: %s",str);
    }
    else if ( op == 7 ) {
      Imp_Lista(fimA,"\nFila A:\n");
      Imp_Lista(fimB,"\nFila B:\n");
    }
  }
}
