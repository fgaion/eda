#include <iostream.h>
//01) funcao exponencial a^b
long  int Eleva(int a, int b)
{
  if ( b == 0 ) return(1);
  else return(a * Eleva(a,b-1));
}

//02) Somatoria de 1 a n ( 1 + 2 + 3 + ... + n - 1 + n )
int Somat(int n)
{
  if ( n == 1 ) return(1);
  else return(n + Somat(n-1));
}

//03) Triangulo de Pascal
int Pascal(int lin, int col)
{
  if ( col == 1 || lin == col ) return(1);
  else return(Pascal(lin-1,col-1)+Pascal(lin-1,col));
}

//04)  Funcao de Ackerman:
long int Ackerman(int m, int n)
{
  if ( m == 0 ) return(1);
  else
  {
    if ( n == 0 ) return(Ackerman(m-1,1));
    else return(Ackerman(m-1, Ackerman(m,n-1)));
  }
}

//05) Funcoes recursivas com vetor
//a) Soma dos elmentos de um vetor - VetSoma
int VetSoma(int A[], int n)
{
  if ( n == 1 ) return(A[0]);
  else return(A[n-1] + VetSoma(A,n-1));
}

//b) Maior elemento de um vetor - VetMaior
int VetMaior(int A[], int n)
{
  int aux;
  if ( n == 1 ) return(A[0]);
  else
  {
    aux = VetMaior(A,n-1);
    if ( aux > A[n-1] ) return(aux);
    else return(A[n-1]);
  }
}

//c) Inverter os elementos de um vetor - VetInv
void VetInv(int A[], int inic, int fim)
{
  int aux;
  if ( inic < fim )
  {
    aux = A[inic];
    A[inic] = A[fim];
    A[fim] = aux;
    VetInv(A,inic+1,fim-1);
  }
}

void main()
{
  int A[10], k;
  for(k=0; k<10; k++) A[k] = k;

  cout << "\n3 elevado a 4 e' " << Eleva(3,4);
  cout << "\nA somatoria de 1 a 100 e' " << Somat(100);
  cout << "\nO elemento na linha 8 e coluna 4 do triangulo de Pascal e' " << Pascal(8,4);
  cout << "\nAckerman para m=5 e n=3 e': " << Ackerman(5,3);
  cout << "\nA soma dos elementos do vetor A e' : " << VetSoma(A,10);
  cout << "\nO maior elemento de A e': " << VetMaior(A,10);
  cout << "\nO vetor A contem os seguintes elementos: ";
  for(k=0; k<10; k++) cout << A[k] << " ";
  VetInv(A,0,9);
  cout << "\nApos invertido, O vetor A contem os seguintes elementos: ";
  for(k=0; k<10; k++) cout << A[k] << " ";
}