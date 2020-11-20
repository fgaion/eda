#include <iostream.h>
int FibNR(int n)
{
  int i,ant,atual,seg;
  if ( n <= 2 ) return(1);
  else
  {
    ant = 1;
    atual = 1;
    for(i=3; i <= n; i++)
    {
      seg = atual + ant;
      ant = atual;
      atual = seg;
    }
  }
  return(atual);
}
void main()
{
  int k;
  for(k=1; k <= 20; k++)
    cout << "\nFibonacci de " << k << " = " << FibNR(k);
}
