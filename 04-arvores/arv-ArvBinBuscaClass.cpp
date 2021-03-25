/****************************************************************
* Classes Arvore Binária, Arvore Binária de Busca e Árvore AVL (balanceada)
* Desenvolvido por: Fábio Gaion
* Observações:
* estrutura exemplo que armazena um dado inteiro
* o campo Bal armazena o peso de um nó para verificar se árvore
* é balanceada (usado somente na árvore AVL)
****************************************************************/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class No {
  public:
    int Info, Bal;
    No *Dir, *Esq;
    No(int x) {Info =x; Bal=0; Dir=Esq=NULL;}
    ~No() {}
    int getInfo() { return(Info); }
    void setInfo(int x) { Info = x; }
    void impNo() { cout << "\nInfo: " << Info;}
};

class ArvBin {
  protected:
    No *Raiz;
    void percPreOrder(No *T);
    void percInOrder(No *T);
    void percPosOrder(No *T);
    void insNoEsq(No *&p, int x);
    void insNoDir(No *&p, int x);
    void buscaArvBin(No *&T, int x, No *&p);
    int calcAltura(No *T);
    void imprimeUmNivel(No *T, int nivel);
    void geraGraphvizPreOrdem(No *T);
  public:
    ArvBin() { Raiz = NULL; }
    ArvBin(No x) { Raiz = &x; }
    ~ArvBin() {}   
    //No *getRaiz() { return(Raiz);}  //somente para debug
    void insRaiz(int x); 
    void insFolhaEsq(int x, int dado);
    void insFolhaDir(int x, int dado);
    void preOrder();
    void inOrder();
    void posOrder();
    int  altura();
    void impUmNivel(int nivel);
    void impPorNivel();
    void geraGraphviz();
};

class ArvBinBusca: public ArvBin {
  private:
    void insAbb(No *&T, int Elem);
    No *buscaAbb(No *T, int Elem);
    void substitue(No *&T, No *&suc);
    void delAbb(struct No *&T, int x);
  public:
    ArvBinBusca(): ArvBin() {}
    ArvBinBusca(No x): ArvBin(x) {}
    ~ArvBinBusca() {}
    void insArvBinBusca(int x);
    bool buscaArvBinBusca(int x,int &dado); //retorna true ou false
    void delArvBinBusca(int x);
};

class ArvBinAVL: public ArvBinBusca {
  private:
    void RotacaoEsq(struct No *&p);
    void RotacaoDir(struct No *&p);
    void InsAVL(No *&T, int Elem);
    //void delAVL(No *&T, int Elem);  //não implementada
  public:
    ArvBinAVL(): ArvBinBusca() {}
    ArvBinAVL(No x): ArvBinBusca(x) {}
    ~ArvBinAVL() {}
    void insArvBinAVL(int x) { InsAVL(Raiz,x);   }
    //void delArvBinAVL(int x) { delAVL(Raiz,x); }
};  
 
void ArvBin::insRaiz(int x){
  if ( Raiz != NULL) cout << "\nErro: Arvore Nao Vazia";
  else Raiz=new No(x);
}  

void ArvBin::insNoEsq(No *&p, int x){
  if ( p == NULL) cout << "\nErro: Arvore Vazia";
  else if (p->Esq != NULL ) cout << "\nErro: insercao No Esq incorreta";
  else p->Esq = new No(x);
}

void ArvBin::insNoDir(No *&p, int x){
  if ( p == NULL) cout << "\nErro: Arvore Vazia";
  else if (p->Dir != NULL ) cout << "\nErro: insercao No Dir incorreta";
  else p->Dir = new No(x);
}

//retorna em p um apontador para o elemento encontrado ou NULL não achar
void ArvBin::buscaArvBin(No *&T, int x, No *&p) {  
  if ( T != NULL){
    if (T->Info == x) p = T;
	  buscaArvBin(T->Esq,x,p);
	  buscaArvBin(T->Dir,x,p);
  }
}

//insere dado a esquerda de x 
void ArvBin::insFolhaEsq(int x, int dado){
  No *pos_x;
  if ( Raiz == NULL) cout << "\nErro: Arvore Vazia";
  else {
    buscaArvBin(Raiz,x,pos_x);
    if ( pos_x == NULL ) cout << "\nErro - elem " << x << " nao existe\n";
    else insNoEsq(pos_x,dado);
  }
}  

//insere dado a direita de x 
void ArvBin::insFolhaDir(int x, int dado){
  No *pos_x;
  if ( Raiz == NULL) cout << "\nErro: Arvore Vazia";
  else {
    buscaArvBin(Raiz,x,pos_x);
    if ( pos_x == NULL ) cout << "\nErro - elem " << x << " nao existe\n";
    else insNoDir(pos_x,dado);
  }
}  

void ArvBin::percPreOrder(No *T) {
  if ( T != NULL){
    cout << T->Info << " ";
	  percPreOrder(T->Esq);
	  percPreOrder(T->Dir);
  }
}

void ArvBin::preOrder() {
  if ( Raiz == NULL ) cout << "\nArvore Vazia";
  else {
    cout << "\nPre Order: ";
    percPreOrder(Raiz);
  }
}    

void ArvBin::percInOrder(No *T) {
  if ( T != NULL){    
	  percInOrder(T->Esq);
    cout << T->Info << " ";
	  percInOrder(T->Dir);
  }
}

void ArvBin::inOrder() {
  if ( Raiz == NULL ) cout << "\nArvore Vazia";
  else {
    cout << "\nIn Order: ";
    percInOrder(Raiz);
  }
}    

void ArvBin::percPosOrder(No *T) {
  if ( T != NULL){    
	  percPosOrder(T->Esq);    
	  percPosOrder(T->Dir);
    cout << T->Info << " ";
  }
}

void ArvBin::posOrder() {
  if ( Raiz == NULL ) cout << "\nArvore Vazia";
  else {
    cout << "\nPos Order: ";
    percPosOrder(Raiz);
  }
}

int ArvBin::calcAltura(No *T){
  int AltE,AltD;
  if ( !T ) return(0);
  else{
	 AltE = calcAltura(T->Esq);
	 AltD = calcAltura(T->Dir);
	 return( (AltD > AltE) ? AltD+1 : AltE+1 );
  }
}

int ArvBin::altura() {
  if ( Raiz == NULL ) return(0);
  else return(calcAltura(Raiz));
}

void ArvBin::imprimeUmNivel(No *T, int nivel)
{
  if ( T == NULL ) return;
  if ( nivel == 0 )  cout << T->Info << "  ";
  else{
	  imprimeUmNivel(T->Esq,nivel-1);
	  imprimeUmNivel(T->Dir,nivel-1);
  }
}

void ArvBin::impUmNivel(int nivel){
  if ( Raiz == NULL ) cout << "\nArvore Vazia";
  else imprimeUmNivel(Raiz,nivel);
}  
  

void ArvBin::impPorNivel()
{
  int n=0, k=calcAltura(Raiz);
  for(n=0;n<k;n++)
  {
	 cout << "\nNivel: " << (n+1) << ": ";
	 imprimeUmNivel(Raiz,n);
  }
}

void ArvBin::geraGraphvizPreOrdem(No *T) {
  if (T != NULL) {
    if (T->Esq)
      cout << T->Info << "->" << T->Esq->Info << endl;
    if (T->Dir)
      cout << T->Info << "->" << T->Dir->Info << endl;
    geraGraphvizPreOrdem(T->Esq);
    geraGraphvizPreOrdem(T->Dir);
  }  
}      

void ArvBin::geraGraphviz(){
  if ( Raiz == NULL ) cout << "\nArvore Vazia";
  else {
    cout << "\nCopiar para http://www.webgraphviz.com/\ndigraph G {\n";
    geraGraphvizPreOrdem(Raiz);
    cout << "}\n";
  }
}    

void ArvBinBusca::insAbb(No *&T, int x){
  if ( T == NULL ) T = new  No(x);
  else{
	  if ( x > T->Info ) insAbb(T->Dir,x);
	  else if ( x < T->Info ) insAbb(T->Esq,x);
	  else cout << "\nErro - Elemento ja existe na arvore";
  }
}

void ArvBinBusca::insArvBinBusca(int x){
  if ( Raiz == NULL ) insRaiz(x);
  else insAbb(Raiz,x);
}  

No* ArvBinBusca::buscaAbb(No *T, int x){
  if ( T != NULL ){
	 if ( x < T->Info ) return(buscaAbb(T->Esq,x));
	 else if ( x > T->Info ) return(buscaAbb(T->Dir,x));
	 else return(T);
  }
  else return(NULL);
}

bool ArvBinBusca::buscaArvBinBusca(int x,int &dado) {
  No *p;
  if (Raiz == NULL ) return(false);
  else {
    p = buscaAbb(Raiz,x);
    if ( p != NULL ){
      dado = p->Info;
      return(true);
    }  
    else return(false);
  }  
}  

void ArvBinBusca::substitue(No *&T, No *&suc) {
  No *aux;
  if ( suc->Esq == NULL ){
	  T->Info = suc->Info;
	  aux = suc;
	  suc = suc->Dir;
	  delete aux;
  }
  else substitue(T,suc->Esq);
}

void ArvBinBusca::delAbb(No *&T, int x) {
  No *aux;
  if ( T != NULL )
  {
	  if ( x < T->Info ) delAbb(T->Esq,x);
	  else if ( x > T->Info ) delAbb(T->Dir,x);
	  else{
		  if ( T->Esq == NULL ){
		    aux = T;
		    T = T->Dir;
		    delete aux;
		  }
		 else if ( T->Dir == NULL ) {
		   aux = T;
		   T = T->Esq;
		   delete aux;
		 }
		 else substitue(T,T->Dir);
	 }
  }
  else cout << "Erro - Elemento nao existe";
}

void ArvBinBusca::delArvBinBusca(int x) {
  if (Raiz == NULL ) cout << "\nDelecao - Arvore Vazia\n";
  else delAbb(Raiz,x);
}

void ArvBinAVL::RotacaoDir(No *&p)
{
  struct No *q, *h;
  q = p->Esq;
  h = q->Dir;
  q->Dir = p;
  p->Esq = h;
}

void ArvBinAVL::RotacaoEsq(No *&p)
{
  struct No *q, *h;
  q = p->Dir;
  h = q->Esq;
  q->Esq = p;
  p->Dir = h;
}

void ArvBinAVL::InsAVL(No *&Raiz, int Elem)
{
  struct No *p, *q, *fp, *ya, *fya, *s;
  int imbal;

  if ( Raiz == NULL ){
	  Raiz = new No(Elem);
	  Raiz->Info = Elem;
	  Raiz->Bal = 0;
	  Raiz->Dir = NULL;
	  Raiz->Esq = NULL;
	  return;
  }
  ya = p = Raiz;
  fp = fya = NULL;
  while (p != NULL){
	  if (Elem == p->Info){
		  cout << "\nErro - Elemento ja existe na arvore";
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
  q = new No(Elem);
  //q->Info = Elem;
  q->Dir = NULL;
  q->Esq = NULL;
  q->Bal = 0;
  (Elem < fp->Info) ? (fp->Esq = q) : (fp->Dir = q);
  //Alterar coeficientes de balanceamento entre ya e q
  p = (Elem < ya->Info) ? ya->Esq : ya->Dir;
  s = p;
  while (p != q) {
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
  if (s->Bal == imbal) { //arv. desbal. na mesma direção (EE,DD)
	  p = s;
	  if (imbal == 1) RotacaoDir(ya);
	  else RotacaoEsq(ya);
	  ya->Bal = s->Bal = 0;
  }
  else {  //arv. desbal. Em direções opostas (ED,DE)
	  if (imbal == 1) {
		  p = s->Dir;
		  RotacaoEsq(s);
		  ya->Esq = p;
		  RotacaoDir(ya);
    }
	  else {
		  p = s->Esq;
      RotacaoDir(s);
      ya->Dir = p;
      RotacaoEsq(ya);
	  }
    if (p->Bal == 0) ya->Bal = s->Bal = 0;
	  else if (p->Bal == imbal) {
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
  if (fya == NULL) Raiz = p;
  else (ya==fya->Dir) ? (fya->Dir = p) : (fya->Esq = p);
}


void testaArvBin()
{
  No no(100);
  ArvBin arv1;
  ArvBin arv2(no);
  cout << "\nARVORE BINARIA\n";
  cout << "\n============================\nArvore 2\n";
  arv2.insFolhaEsq(100,50);
  //arv2.preOrder();
  arv2.insFolhaDir(100,150);
  arv2.insFolhaEsq(50,25);
  arv2.insFolhaDir(50,75);
  arv2.insFolhaEsq(150,125);
  arv2.insFolhaDir(150,175);
  arv2.insFolhaEsq(100,10); //deve exibir msg de erro
  arv2.preOrder();
  arv2.inOrder();
  arv2.posOrder();
  cout << "\nAltura: " << arv2.altura() << endl;
  arv2.impPorNivel();
  arv2.geraGraphviz();
  cout << "\n============================\nArvore 1\n";
  arv1.insRaiz(10);
  arv1.insFolhaEsq(10,5);
  arv1.insFolhaDir(10,15);
  arv1.insFolhaEsq(5,2);
  arv1.insFolhaDir(5,7);
  arv1.insFolhaEsq(15,12);
  arv1.insFolhaDir(15,17);
  arv1.insFolhaDir(17,20);
  arv1.insFolhaEsq(20,19);
  arv1.preOrder();
  arv1.inOrder();
  arv1.posOrder();
  cout << "\nAltura: " << arv1.altura() << endl;
  arv1.impPorNivel();
  arv1.geraGraphviz();
}  

void testaArvBinBusca(){
  int dado, resp, op=1;
  bool existe;
  ArvBinBusca arv;
  
  cout << "\nARVORE BINARIA BUSCA\n";
  while ( op != 0 ){
	 cout << "\n1 - Inserir\n2 - Consultar\n3 - Deletar"
			<< "\n4 - In Order\n5 - Pre Order\n6 - Pos Order"
      << "\n7 - Por Nivel\n8 - Altura\n9 - GraphViz\n0 - Sair\nOpcao: ";
	 cin >> op;
	 if (op == 1){
		 cout << "Insercao - entre com a informaao (n. inteiro): ";
		 cin >> dado;
		 arv.insArvBinBusca(dado);
	 }
	 else if (op == 2){
		 cout << "Busca - entre com a informacao (n. inteiro): ";
		 cin >> dado;
		 existe = arv.buscaArvBinBusca(dado,resp);
		 if ( existe ) cout << "\nElemento encontrado: resp = " << resp;
		 else cout << "\nElemento não encontrado";
	 }
	 else if (op == 3){
		 cout << "Delecao - entre com a informacao (n. inteiro): ";
		 cin >> dado;
		 arv.delArvBinBusca(dado);
	 }
	 else if (op == 4){
		 cout << "\nPercurso In Order:\n";
		 arv.inOrder(); cout << "\n\n";
	 }
   else if (op == 5){
		 cout << "\nPercurso Pre Order:\n";
		 arv.preOrder(); cout << "\n\n";
	 }
   else if (op == 6){
		 cout << "\nPercurso Pos Order:\n";
		 arv.posOrder(); cout << "\n\n";
	 }
   else if (op == 7){
     cout << "\nImprime por nivel:\n";
     arv.impPorNivel();
   }
   else if (op == 8) cout << "\nAltura da árvore: " << arv.altura() << endl;
   else if (op == 9) arv.geraGraphviz();
  }
}

void testaArvBinAVL(){
  int dado, resp, op=1;
  bool existe;
  ArvBinAVL arv;
  
  cout << "\nARVORE BINARIA BUSCA - AVL\n";
  while ( op != 0 ){
	 cout << "\n1 - Inserir\n2 - Consultar\n3 - Deletar"
			<< "\n4 - In Order\n5 - Pre Order\n6 - Pos Order"
      << "\n7 - Por Nivel\n8 - Altura\n9 - GraphViz\n0 - Sair\nOpcao: ";
	 cin >> op;
	 if (op == 1){
		 cout << "Insercao - entre com a informaao (n. inteiro): ";
		 cin >> dado;
		 arv.insArvBinAVL(dado);
	 }
	 else if (op == 2){
		 cout << "Busca - entre com a informacao (n. inteiro): ";
		 cin >> dado;
		 existe = arv.buscaArvBinBusca(dado,resp);
		 if ( existe ) cout << "\nElemento encontrado: resp = " << resp;
		 else cout << "\nElemento não encontrado";
	 }
	 else if (op == 3){
		 cout << "Delecao - entre com a informacao (n. inteiro): NAO IMPLEMETADO";
		 //cin >> dado;
		 //arv.delArvBinAVL(dado);
	 }
	 else if (op == 4){
		 cout << "\nPercurso In Order:\n";
		 arv.inOrder(); cout << "\n\n";
	 }
   else if (op == 5){
		 cout << "\nPercurso Pre Order:\n";
		 arv.preOrder(); cout << "\n\n";
	 }
   else if (op == 6){
		 cout << "\nPercurso Pos Order:\n";
		 arv.posOrder(); cout << "\n\n";
	 }
   else if (op == 7){
     cout << "\nImprime por nivel:\n";
     arv.impPorNivel();
   }
   else if (op == 8) cout << "\nAltura da árvore: " << arv.altura() << endl;
   else if (op == 9) arv.geraGraphviz();
  }
}


int main()
{
  int dado, op=0;

  testaArvBin();
  testaArvBinBusca();
  testaArvBinAVL();
  return(1);
}

