/**********************************************************/
/* PILHA UTILIZANDO ESTRUTURA LIGADA COM VETOR E APONTADOR*/
/* Exemplo com 3 pilhas                                   */
/**********************************************************/

#include <stdio.h>
#include <string.h>


#define OK   1
#define ERRO 0
#define TAM_VET 10

struct dado {
  char info[10];
  int  prox;
};

struct dado P[TAM_VET];
int TopoA,TopoB,TopoC,Livre;

void Inic_Vetor(struct dado P[],int *Livre) {
  int k;
  *Livre = 0;
  for(k=0; k < TAM_VET; k++) P[k].prox = k+1;
  P[TAM_VET-1].prox = -1;
}

void Inic_Pilha(int *Topo) {
  *Topo = -1;
}

int Ins_Pilha(struct dado P[], char *Elem, int *Topo, int *Livre){
  int atual;
  if ( *Livre == -1 ) {
    printf("\nInsercao Impossivel - Pilha Cheia\n");
    return(ERRO);
  }
  else {
    atual = *Livre;
    *Livre = P[*Livre].prox;
    strcpy(P[atual].info,Elem);
    P[atual].prox = *Topo;
    *Topo = atual;
  }
  return(OK);
}

int Del_Pilha(struct dado P[], char *Elem, int *Topo, int *Livre) {
  int atual;
  if ( *Topo == -1 ){
    printf("\nDelecao Impossivel - Pilha Vazia\n");
    return(ERRO);
  }
  else {
    atual = *Topo;
    strcpy(Elem,P[atual].info);
    *Topo = P[*Topo].prox;
    P[atual].prox = *Livre;
    *Livre = atual;
  }
  return(OK);
}

int Recup_Topo(struct dado P[], char *Elem, int Topo) {
  int atual;

  if ( Topo == -1 ) {
    printf("\nRecupera Topo - Pilha Vazia\n");
    return(ERRO);
  }
  else strcpy(Elem,P[Topo].info);
  return(OK);
}

void Imp_Pilha(struct dado P[],int Topo,char *txt){
  int k;
  k = Topo;
  printf("\n%s : Topo-> ",txt);
  while ( k != -1 ){
    printf("%s -> ",P[k].info);
    k = P[k].prox;
  }
  printf("(fim da pilha)\n");
}

void Imp_Vetor(struct dado P[]) {
  int k;
  printf("\nind  prox   info\n");
  for(k=0; k < TAM_VET; k++)
    printf("%d    %d    %s\n", k,P[k].prox,P[k].info);
}

int menu_pilha() {
  int x;
  printf("\n\n1) Inserir\n2) Deletar\n3) Recuperar\n4) Imprimir\n5) Vetor\n0) Sair\nOpcao: ");
  scanf("%d",&x);
  return(x);
}

int main()
{
  int op=1, que_pilha, x;
  char Elem[10];

  Inic_Vetor(P,&Livre);
  Inic_Pilha(&TopoA);
  Inic_Pilha(&TopoB);
  Inic_Pilha(&TopoC);
  while ( op ) {
    op = menu_pilha();
    if ( op == 1)
    {
      printf("\nEntre com o elemento a ser inserido: ");
      scanf("%s",Elem);
      printf("\nInserir em qual Pilha:\n1-Pilha A\n2-Pilha B\n3-Pilha C\nOpcao:");
      scanf("%d",&que_pilha);
      if (que_pilha == 1)	Ins_Pilha(P,Elem,&TopoA,&Livre);
      else if (que_pilha == 2) 	Ins_Pilha(P,Elem,&TopoB,&Livre);
      else if (que_pilha == 3) 	Ins_Pilha(P,Elem,&TopoC,&Livre);
    }
    else if ( op == 2) {
      printf("\nRemover de qual Pilha:\n1-Pilha A\n2-Pilha B\n3-Pilha C\nOpcao:");
      scanf("%d",&que_pilha);
      if (que_pilha == 1) 	x = Del_Pilha(P,Elem,&TopoA,&Livre);
      else if (que_pilha == 2)	x = Del_Pilha(P,Elem,&TopoB,&Livre);
      else if (que_pilha == 3)	x = Del_Pilha(P,Elem,&TopoC,&Livre);
      if ( x != ERRO ) printf("\nElemento removido: %s",Elem);
    }
    else if ( op == 3) {
      printf("\nEscolha a Pilha:\n1-Pilha A\n2-Pilha B\n3-Pilha C\nOpcao:");
      scanf("%d",&que_pilha);
      if (que_pilha == 1)	x = Recup_Topo(P,Elem,TopoA);
      else if (que_pilha == 2) 	x = Recup_Topo(P,Elem,TopoB);
      else if (que_pilha == 3) 	x = Recup_Topo(P,Elem,TopoC);
      if ( x != ERRO ) printf("\nElemento do topo da pilha: %s",Elem);
    }
    else if ( op == 4)     {
      Imp_Pilha(P,TopoA,"Pilha A");
      Imp_Pilha(P,TopoB,"Pilha B");
      Imp_Pilha(P,TopoC,"Pilha C");
    }
    else if ( op == 5)     {
      Imp_Vetor(P);
      printf("\nTopoA = %d  TopoB = %d TopoC = %d  Livre = %d\n",TopoA,TopoB,TopoC,Livre);
    }
    else
      printf("\nOpcao Invalida...\n");
  }
}
