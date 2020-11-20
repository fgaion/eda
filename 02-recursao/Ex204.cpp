#include <iostream.h>
void Hanoi(int n,char Orig,char Dest,char Aux)
{
  if ( n == 1 )
    cout << "\nMover o disco " << n << " de " << Orig << " para " << Dest;
  else
  {
    Hanoi(n-1,Orig,Aux,Dest);
    cout << "\nMover o disco " << n << " de " << Orig << " para " << Dest;
    Hanoi(n-1,Aux,Dest,Orig);
  }
}
void main()
{
  int k;
  cout << "\nEntre com o numero de discos: ";
  cin >> k;
  Hanoi(k,'A','C','B');
}

