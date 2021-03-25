/*********************************************************/
/* PILHA UTILIZANDO ESTRUTURA LIGADA COM ALOCACAO DINAMI-*/
/* CA E  APONTADORES                                     */
/* Exemplo com 2 pilhas                                  */
/*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK   1
#define ERRO 0

struct info{
  char dado[21];
  struct info *prox;
};
struct info *TopoA, *TopoB;

void Imp_Lista(struct info *cabec, char *txt) {
  struct info *p;

  if (cabec == NULL ) printf("Lista vazia...\n");
  else {
    printf("%s - Topo -> ",txt);
    p = cabec;
    while ( p != NULL ) {
      printf("%s -> ",p->dado);
      p = p->prox;
    }
    printf("fim da pilha");
  }
}

int Ins_Pilha(struct info **Topo, char *s) {
  struct info *p;
  p = (struct info*) malloc(sizeof(struct info));
  if ( !p ) return(ERRO);
  strcpy(p->dado,s);
  p->prox = *Topo;
  *Topo = p;
  return(OK);
}

int Del_Pilha(struct info **Topo, char *s){
  struct info *p;

  if ( Topo == NULL ) {
    printf("\nErro - Removendo de uma Pilha Vazia...\n");
    return(ERRO);
  }
  else {
    p = *Topo;
    *Topo = (*Topo)->prox;
    strcpy(s,p->dado);
    free(p);
  }
  return(OK);
}

int Rec_Topo(struct info *Topo, char *s)
{
  if ( Topo == NULL ) {
    printf("\nErro - Recuperando Topo de uma Pilha Vazia...\n");
    return(ERRO);
  }
  else strcpy(s,Topo->dado);
  return(OK);
}


int main()
{
  char str[21];
  int op=0,ok;
  TopoA = TopoB = NULL;

  while ( op != 8 )
  {
    printf("\n\nMenu\n1-Inserir Pilha A\n2-Inserir Pilha B\n3-Remover Pilha A\n4-Remover Pilha B\n5-Mostra Topo Pilha A\n6-Mostra Topo Pilha B\n7-Imprime Pilhas A e B\n8-Fim\nOpcao: ");
    scanf("%d",&op);
    if ( op == 1) {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Pilha(&TopoA,str);
    }
    if ( op == 2) {
      printf("\nDigite uma string (ate 20 caracteres): "); scanf("%s",str);
      Ins_Pilha(&TopoB,str);
    }
    else if ( op == 3 ) {
      ok = Del_Pilha(&TopoA,str);
      if ( ok != ERRO) printf("\nElemento removido da Pilha A: %s",str);
    }
    else if ( op == 4 ) {
      ok = Del_Pilha(&TopoB,str);
      if ( ok != ERRO) printf("\nElemento removido da Pilha B: %s",str);
    }
    else if ( op == 5 ) {
      ok = Rec_Topo(TopoA,str);
      if ( ok != ERRO) printf("\nElemento do topo da pilha A: %s",str);
    }
    else if ( op == 6 )
    {
      ok = Rec_Topo(TopoB,str);
      if ( ok != ERRO) printf("\nElemento do topo da pilha B: %s",str);
    }
    else if ( op == 7 ) {
      Imp_Lista(TopoA,"\nPilha A:\n");
      Imp_Lista(TopoB,"\nPilha B:\n");
    }
  }
}
