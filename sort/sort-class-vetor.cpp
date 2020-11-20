#include <iostream>
#include <stdlib.h>
#include <ctime> 

using namespace std;

class vetor
{
  private:
	 int *v;
	 int tam;
   void swap(int i, int j) { int t = v[i]; v[i]=v[j]; v[j] = t; }
   void perm(int n, int i);
   void particionar(int lb,int ub, int &j);
   void quickSort(int lb, int ub,int n);
  public:
	 vetor();
	 vetor(int n);
	 vetor(int n,int val);
	 vetor(const vetor &vaux);
	 ~vetor(void);
   void resize(int n);
	 void set_val(int i,int val); //coloca valor no vetor na posição i
	 int get_val(int i);  //acessa valor do vetor na posição i
   int get_tamanho() { return tam; }
   void random(int n);
	 void imprime(void);
	 int maior(void);
	 int menor(void);
	 float media(void);
   float mediana(void) {return ( (tam%2) ? (float) v[(int)(tam/2)] : (float) (v[(int) tam/2]+v[(int) (tam/2)-1])/2 ); }
   void sumario();
	 void inverte(void);
   void permuta(int n);  //permuta os n primeiros elementos do vetor
   void permuta() { permuta(tam); }
   void ordena() { quickSort(0,tam-1,tam); }
};

vetor::vetor() {
   cout << "\nConstrutor sem parametros chamado.";
   tam = 0;
   v = NULL;
}

vetor::vetor(int n) {
  cout << "\nConstrutor com um parametro chamado.";
  if (n>=0){
    if ( n!= 0) v=new int[n];
    else v = NULL;
    tam=n;
    for(int k=0;k<n;k++) v[k]=0;
  }
  else {
    tam=0;
    v = NULL;
    cout<<"\ntamanho do vetor deve ser maior que zero\n";
  }
}

vetor::vetor(int n,int val) {
  cout << "\nConstrutor com dois parametros chamado.";
  if (n>=0) {
    if (n!=0) v=new int[n];
    else v = NULL;
    tam=n;
    for(int k=0;k<n;k++)v[k]=val;
  }
  else {
    tam=0;
    v = NULL;
    cout<<"\ntamanho do vetor deve ser maior que zero\n";
  }
}

vetor::vetor(const vetor &vaux) {
  cout << "\nConstrutor copia chamado.";
  if (vaux.tam>=0) {
    if (vaux.tam != 0 ) v=new int[vaux.tam];
    else v = NULL;
    tam=vaux.tam;
    for(int k=0;k<vaux.tam;k++) v[k]=vaux.v[k];
  }
  else {
    tam=0;
    v = NULL;
    cout<<"\ntamanho do vetor deve ser maior que zero\n";
  }
}

vetor::~vetor(void) {
  cout << "\nDestrutor chamado";
  delete[]v;
  tam=0;
  v=NULL;
}

void vetor::resize(int n) {  
  if (n>=0){
    if (tam > 0) delete []v;
    if ( n!= 0) v=new int[n];
    else v = NULL;
    tam=n;
    for(int k=0;k<n;k++) v[k]=0;
  }
  else cout<<"\nResize: tamanho do vetor deve ser maior que zero\n";
}

void vetor::set_val(int i,int val) {
  if (i>=0 && i<tam) v[i]=val;
  else cout<<"\nindice do vetor invalido \n";
}

int vetor::get_val(int i) {
  if (i>=0 && i<tam) return(v[i]);
  else {
    cout<<"\n indice do vetor invalido \n";
    return(0);
  }
}

void vetor::random(int n) {
 int k;
  if ( tam == 0 ) {
    cout << "\nvetor de tamanho 0";
    return;
  }
  if ( n ) {
    srand((unsigned)time(0));
    for(k=1;k<tam;k++) v[k] = rand() % n + 1;
  }  
  else  cout << "\nErro - n deve ser diferente de 0";
}  
  
void vetor::imprime(void) {
  int k;
  cout<<"vetor tamanho:" <<tam<<"\n";
  for(k=0;k<tam;k++) cout<<v[k]<<" ";
}

 int vetor::maior(void){
  int k,ma;
  if ( tam == 0 ) {
    cout << "\nvetor de tamanho 0";
    return(0);
  }
  ma=v[0];
  for(k=1;k<tam;k++)
    if(v[k]>ma)ma=v[k];
  return(ma);
}

int vetor::menor(void) {
  int k,me;
  if ( tam == 0 ) {
    cout << "\nvetor de tamanho 0";
    return(0);
  }
  me=v[0];
  for(k=1;k<tam;k++)
    if(v[k]<me)me=v[k];
  return(me);
}

float vetor::media(void) {
  int k,soma=0;
  if ( tam == 0 ) {
    cout << "\nvetor de tamanho 0";
    return(0);
  }
  for(k=0;k<tam;k++) soma+=v[k];
  return((float) soma/tam);
}

void vetor::sumario(void) {
  cout << "\nSumario\nTamanho do vetor: " << tam
       << "\nMaior: " << maior()
       << "\nMenor: " << menor()
       << "\nMedia: " << media()
       << "\nMediana: " << mediana() << endl;
}       

void vetor::inverte(void) {
  int k,aux;
  if (tam == 0 ) {
    cout << "\nvetor de tamanho 0";
    return;
  }
  for(k=0;k<tam/2;k++) {
    aux=v[k];
    v[k]=v[tam -1 -k];
    v[tam -1 -k]=aux;
  }
}

// full permutation
void vetor::perm(int n, int i) {
  if (i == (n-1)) { //check if reach the end of iteration
    // print out the iteration
    for (int j =0; j < n; j ++) cout<< v[j];
    cout << "  -  ";
  }
  else {
    for (int j =i; j < n; j ++) {
      swap(i,j); // swap
      perm(n,i + 1);         // recursive
      swap(i,j); // swap it back
    }
  }
}

void vetor::permuta(int n) {
  if (!n) {
    cout << "Vetor de tamnaho 0";
    return;
  }
  perm(n,0);  
}

void vetor::particionar(int lb,int ub, int &j){
  int a,temp, down, up;
  a = v[lb];
  up = ub;
  down = lb;
  while ( down < up ){
	 while ( v[down] <= a && down < ub ) down++;
	 while ( v[up] > a ) up--;
	 if ( down < up ){
		temp = v[down];
		v[down]=v[up];
		v[up] = temp;
	 }
  }
  v[lb]=v[up];
  v[up]=a;
  j = up;
}

void vetor::quickSort(int lb, int ub,int n) {
  int j;
  if ( lb >= ub ) return;
  particionar(lb,ub,j);
  quickSort(lb,j-1,n);
  quickSort(j+1,ub,n);
}


int main() {
  int k;
  vetor a(10,20);
  vetor b(11);
  vetor d;
  cout << "\nvetor a (ants do comando set):";
  a.imprime();
  for(k=0;k<a.get_tamanho();k++) a.set_val(k,k*k);
  for(k=0;k<b.get_tamanho();k++) b.set_val(k,3*k);
  cout << "\nvetor a:";
  a.imprime();
  cout<<"\nmaior de a: "<<a.maior();
  cout<<"\nmenor de a: "<<a.menor();
  cout<<"\nmedia de a: "<<a.media();
  cout<<"\nmediana de a: "<<a.mediana() << endl;
  a.inverte();
  a.imprime();
  
  cout << "\n\nvetor b:";
  b.imprime();
  cout<<"\nmaior de b: "<<b.maior();
  cout<<"\nmenor de b: "<<b.menor();
  cout<<"\nmedia de b: "<<b.media();
  cout<<"\nmediana de b: "<<b.mediana() << endl;
  b.inverte();
  b.imprime();
  cout << "\nvetor b random (0a100):"; 
  b.random(100);
  b.imprime();  
  b.ordena();
  cout << "\n\nvetor b ordenado:";
  b.imprime();
  b.sumario();
  
  
  vetor c = a;
  cout << "\nvetor c:";
  c.imprime();
  cout << "\nvetor d antes do resize:";
  d.imprime();
  d.resize(4);
  for(k=0;k<d.get_tamanho();k++) d.set_val(k,k);
  cout << "\nvetor d:";
  d.imprime();
  cout << "\nPermutacao: ";
  d.permuta();
   cout << "\nPermutacao: ";
  d.permuta(d.get_tamanho()-1);
  cout << "\nvetor d:";
  d.imprime();
  
}
