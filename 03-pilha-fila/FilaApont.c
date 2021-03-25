/*********************************************************/
/* FILA UTILIZANDO ESTRUTURA LIGADA COM ALOCACAO DINAMI- */
/* CA E  APONTADORES                                     */
/* Exemplo com 2 filas                                   */
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
struct info *frenteA, *fimA, *frenteB, *fimB;

void Imp_Lista(struct info *cabec, char *txt) {
  struct info *p;

  if (cabec == NULL ) printf("%s - Fila vazia...\n",txt);
  else {
    printf("%s: frente -> ",txt);
    p = cabec;
    while ( p != NULL ) {
      printf("%s -> ",p->dado);      
      p = p->prox;
    }
    printf("fim da fila");
  }
}

int Ins_Fila(struct info **frente, struct info **fim, char *s){
  struct info *p;  
  p = (struct info*) malloc(sizeof(struct info));
  if ( !p ) return(ERRO);
  strcpy(p->dado,s);
  p->prox = NULL;
  if ( *fim == NULL ) *frente = *fim = p;
  else   {
    (*fim)->prox = p;
    *fim = p;
  }
  return(OK);
}

int Del_Fila(struct info **frente, struct info **fim, char *s){
  struct info *p;

  if ( frente == NULL ) {
    printf("\nErro - Removendo de uma Fila Vazia...\n");
    return(ERRO);
  }
  else {
    p = *frente;
    strcpy(s,(*frente)->dado);
    *frente = (*frente)->prox;
    free(p);
    if ( *frente == NULL ) *fim = NULL;
  }
  return(OK);
}

int Rec_Frente(struct info *frente, char *s)
{
  struct info *p;

  if ( frente == NULL ) {
    printf("\nErro - Recuperando frente de uma Fila Vazia...\n");
    return(ERRO);
  }
  else strcpy(s,frente->dado);
  return(OK);
}


void main()
{
  char str[21];
  int op=0,ok;
  frenteA = fimA = frenteB = fimB = NULL;

  while ( op != 8 )
  {
    printf("\n\nMenu\n1-Inserir Fila A\n2-Inserir Fila B\n3-Remover Fila A\n4-Remover Fila B\n5-Mostra frente Fila A\n6-Mostra frente Fila B\
    \n7-Imprime Filas A e B\n8-Fim\nOpcao: ");
    scanf("%d",&op);
    if ( op == 1) {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(&frenteA,&fimA,str);
    }
    if ( op == 2){
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Fila(&frenteB,&fimB,str);
    }
    else if ( op == 3 ){
      ok = Del_Fila(&frenteA,&fimA,str);
      if ( ok != ERRO) printf("\nElemento removido da Fila A: %s",str);
    }
    else if ( op == 4 ) {
      ok = Del_Fila(&frenteB,&fimB,str);
      if ( ok != ERRO) printf("\nElemento removido da Fila B: %s",str);
    }
    else if ( op == 5 ) {
      ok = Rec_Frente(frenteA,str);
		  if ( ok != ERRO) printf("\nElemento do inicio da Fila A: %s",str);
    }
    else if ( op == 6 ) {
      ok = Rec_Frente(frenteB,str);
		  if ( ok != ERRO) printf("\nElemento do inicio da Fila B: %s",str);
    }
    else if ( op == 7 ) {
      Imp_Lista(frenteA,"\nFila A:\n");
      Imp_Lista(frenteB,"\nFila B:\n");
    }
  }
}
