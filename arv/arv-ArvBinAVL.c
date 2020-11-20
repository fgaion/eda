/****************************************************************
* Arvore Binária de Busca AVL (balanceada)
* Desenvolvido por: Fábio Gaion
* Observações:
* estrutura exemplo que armazena um dado inteiro
* o campo Bal armazena o peso de um nó para verificar se árvore
* é balanceada
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
  int Info;
  int Bal;  //coeficiente de balanceamento: -1, 0 ou 1
  struct No *Dir, *Esq;
};
struct No *Raiz;

int Altura(struct No *T) {
  int AltE,AltD;
  if ( !T ) return(0);
  else  {
	  AltE = Altura(T->Esq);
	  AltD = Altura(T->Dir);
	  return( (AltD > AltE) ? AltD+1 : AltE+1 );
  }
}

void ImpUmNivel(struct No *T, int nivel) {
  if ( T == NULL ) return;
  if ( nivel == 0 )  printf("%d ",T->Info);
  else
  {
	 ImpUmNivel(T->Esq,nivel-1);
	 ImpUmNivel(T->Dir,nivel-1);
  }
}

void ImpPorNivel(struct No *T) {
  int n=0, k=Altura(T);
  for(n=0;n<k;n++) {
	  printf("\nNivel %d: ",n+1);
	  ImpUmNivel(T,n);
  }
}

void InOrder(struct No *T) {
  if ( T != NULL ) {
	 InOrder(T->Esq);
	 printf("%d ",T->Info);
	 InOrder(T->Dir);
  }
}

void PreOrder(struct No *T) {
  if ( T != NULL ) {
	 printf("%d ",T->Info);
	 PreOrder(T->Esq);
	 PreOrder(T->Dir);
  }
}

void PosOrder(struct No *T) {
  if ( T != NULL ) {
	 PosOrder(T->Esq);
	 PosOrder(T->Dir);
	 printf("%d ",T->Info);
  }
}

void RotacaoDir(struct No **p){
  struct No *q, *h;
  q = (*p)->Esq;
  h = q->Dir;
  q->Dir = (*p);
  (*p)->Esq = h;
}

void RotacaoEsq(struct No **p){
  struct No *q, *h;
  q = (*p)->Dir;
  h = q->Esq;
  q->Esq = (*p);
  (*p)->Dir = h;
}

struct No* BuscaAVL(struct No *T, int Elem){  //idem BuscaAbb
  if ( T != NULL ){
	  if ( Elem < T->Info ) return(BuscaAVL(T->Esq,Elem));
	  else if ( Elem > T->Info ) return(BuscaAVL(T->Dir,Elem));
	  else return(T);
  }
  else return(NULL);
}

void InsAVL(struct No **Raiz, int Elem) {
  struct No *p, *q, *fp, *ya, *fya, *s;
  int imbal;

  if ( (*Raiz) == NULL ){
    (*Raiz) = (struct No*) malloc(sizeof( struct No));
	  (*Raiz)->Info = Elem;
	  (*Raiz)->Bal = 0;
	  (*Raiz)->Dir = NULL;
	  (*Raiz)->Esq = NULL;
	  return;
  }
  ya = p = (*Raiz);
  fp = fya = NULL;
  while (p != NULL)
  {
	  if (Elem == p->Info){
		  printf("\nErro - Elemento ja existe na arvore");
		  return;
	  }
	  q = (Elem < p->Info) ? p->Esq : p->Dir;
	  if (q != NULL) {
		  if (q->Bal != 0 ){
		    fya = p;
		    ya = q;
		  }
    }
	  fp = p;
	  p = q;
  }
  //aloca espaco e inicializa um no´
  q = (struct No*) malloc(sizeof(struct No));
  q->Info = Elem;
  q->Dir = NULL;
  q->Esq = NULL;
  q->Bal = 0;
  (Elem < fp->Info) ? (fp->Esq = q) : (fp->Dir = q);
  //Alterar coeficientes de balanceamento entre ya e q
  p = (Elem < ya->Info) ? ya->Esq : ya->Dir;
  s = p;
  while (p != q){
	  if (Elem < p->Info) {
		  p->Bal = 1;
		  p = p->Esq;
	  }
	  else {
	 	  p->Bal = -1;
		  p = p->Dir;
	  }
  }
  //Determina se a árvore está desbalanceada, sendo q o nó
  //inserido, ya o nó desbalanceado com maior altura, fya o
  //pai de ya e s o filho de ya na direção do desbalanceamento
  imbal = (Elem < ya->Info) ? 1 : -1;
  if (ya->Bal == 0) { //arv. não desbalanceada  
	  ya->Bal = imbal;
	  return;
  }
  if (ya->Bal != imbal) { //arv. não desbalanceada  
	  ya->Bal = 0;
	  return;
  }
  if (s->Bal == imbal){ //arv. desbal. na mesma direção (EE,DD)
	  p = s;
	  if (imbal == 1) RotacaoDir(&ya);
	  else RotacaoEsq(&ya);
	  ya->Bal = s->Bal = 0;
  }
  else {  //arv. desbal. Em direções opostas (ED,DE)
	  if (imbal == 1){
		  p = s->Dir;
		  RotacaoEsq(&s);
		  ya->Esq = p;
		  RotacaoDir(&ya);
	  }
	  else{
		  p = s->Esq;
      RotacaoDir(&s);
      ya->Dir = p;
      RotacaoEsq(&ya);
	  }
    if (p->Bal == 0) ya->Bal = s->Bal = 0;
	  else if (p->Bal == imbal){
		  ya->Bal = -imbal;
      s->Bal = 0;
    }
    else {
      ya->Bal = 0;
		  s->Bal = imbal;
	  }
	  p->Bal = 0;
  }
  //ajusttar o apontador da subárvore rotacionada
  if (fya == NULL) (*Raiz) = p;
  else (ya==fya->Dir) ? (fya->Dir = p) : (fya->Esq = p);
}

int main()
{
  int dado, op=1;
  struct No *p;

  Raiz = NULL;
  while ( op != 0 ) {
	  printf("\n\n1 - Inserir\n2 - Consultar\n3 - Deletar\n4 - In Order\n5 - Imprime por Nivel\n0 - Sair\nOpcao: ");
	  scanf("%d",&op);
	  if (op == 1) {
		  printf("Inserção - entre com a informacao (n. inteiro): ");
		  scanf("%d",&dado);
		  InsAVL(&Raiz,dado);
	  }
	  else if (op == 2){
		  printf("Busca - entre com a informacao (n. inteiro): ");
		  scanf("%d",&dado);
		  p = BuscaAVL(Raiz,dado);
		  if ( p ) printf("\nElemento encontrado");
		  else printf("\nElemento não encontrado");
	  }
	  else if (op == 3) {
		  printf("Deleção - entre com a informacao (n. inteiro):\nOPÇÃO NÃO IMPLEMENTADA");
		  //scanf("%d",&dado);
		  //DelAVL(&Raiz,dado);
	 }
	 else if (op == 4){
		 printf("\nPercurso In Order:\n");
		 InOrder(Raiz); 
   }
	 else if (op == 5) {
		 printf("\nArvore por niveis:\n");
		 ImpPorNivel(Raiz);
	 }
  }
  return(1);
}
